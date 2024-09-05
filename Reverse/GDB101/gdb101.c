#include <stdio.h>

int main() {
    int encoded_flag[] = {
        83, 101, 99, 117, 114, 105, 110, 101, 116, 115, 123, 
        103, 100, 98, 95, 49, 53, 95, 117, 114, 95, 98, 51, 
        115, 116, 102, 114, 49, 101, 110, 100, 125
    };
    char flag[sizeof(encoded_flag) / sizeof(int) + 1];

    for (int i = 0; i < sizeof(encoded_flag) / sizeof(int); i++) {
        flag[i] = (char)encoded_flag[i];
    }
    flag[sizeof(encoded_flag) / sizeof(int)] = '\0';

    printf("Hello again!\n");
    printf("This time you need to actually run the program and dig a bit deeper!\n");
    printf("Good luck!\n");
    printf("Author: jio\n");

    return 0;
}
