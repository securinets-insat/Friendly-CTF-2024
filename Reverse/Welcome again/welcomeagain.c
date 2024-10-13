#include <stdio.h>
#include <string.h>

int main() {
    const char* flag = "S\0e\0c\0u\0r\0i\0n\0e\0t\0s\0{\0x\0x\0d\0_\0i\0s\0_\0b\0e\0t\0t\0e\0r\0_\0t\0h\0a\0n\0_\0s\0t\0r\0i\0n\0g\0s\0}\0";
    printf("\n");
    printf("== WELCOME AGAIN ==\n");
    printf("--  Author: jio  --\n");
    printf("\n");
    char input[70];
	printf("flag? ");
	fgets(input, 70, stdin);
	for(int i = 0; i < strlen(input) - 1; i++) {
		if(input[i] != flag[2*i]) {
			puts("wrong!");
			return -1;
		}
	}
	puts("correct!");
	return 0;
}
