#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int func_0928() {
        if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
                return 1; 
        } else {
                ptrace(PTRACE_DETACH, 0, 1, 0);
                return 0; 
        }
}

int func_1234(const char* str1) {
        int result = 0;
        int shift = 3;
        const char* text = "1wV_g33S3u_Wk4q_B0x_Wk1qn";
        size_t len = (strlen(text) <= strlen(str1)) ? strlen(text) : strlen(str1);
        char c;
        char base;
        for (size_t i = 0; i < len; ++i) {
                if (isalpha(text[i])) {
                        base = isupper(text[i]) ? 'A' : 'a';
                        c = ((text[i] - base - shift + 26) % 26) + base;
                        result |= str1[i] ^ c;
                } else {
                        result |= str1[i] ^ text[i];
                }
	}
	return result == 0;
}

void func_5362(const char* string){
        int n = func_1234(string);
        if(n){
                printf("You found the treasure !");
        } else {
                printf("The treasure is forever lost !!!!");
        }
}

void func_5678(){
        if(func_0928()){
		printf("Debugger detected. Process terminated.");
	       	exit(1);
	}
}

int main(){
	func_5678();
	printf("Enter the treasure code: ");
	char *input = (char*)malloc(20*sizeof(char));
	scanf("%s",input);
	func_5362(input);
	return 0;
}



