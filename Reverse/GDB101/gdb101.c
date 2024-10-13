#include <stdio.h>
#include <string.h>

int main() {
    int encoded_flag[] = {
        83, 101, 99, 117, 114, 105, 110, 101, 116, 115, 123, 
        103, 100, 98, 95, 49, 53, 95, 117, 114, 95, 98, 51, 
        115, 116, 102, 114, 49, 101, 110, 100, 125
    };

    char flag[sizeof(encoded_flag) / sizeof(int) + 1];
    flag[0] = '\0';

    for (int i = 0; i < sizeof(encoded_flag) / sizeof(int); i++) {
        char current_char[2];
        current_char[0] = (char)encoded_flag[i];
        current_char[1] = '\0';
        
        strcat(flag, current_char);
    }

    printf("\n");
    printf("==   GDB 101   ==\n");
    printf("-- Author: jio --\n");
    printf("\n");
    printf("Run me in GDB and keep looking at registers. The flag will be there ;)\n");
    printf("Good luck! ^_^\n");

    return 0;
}
