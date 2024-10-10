#include <stdio.h>
#include <string.h>

int main() {
    char s[30];

    printf("Enter the password:\n");
    scanf("%s", s); 

    // Calculate the sum of ASCII values of the input password
    int sum = 0;
    for(int i = 0; i < 25 ; i++) {
        sum += (int)s[i];
    }

    // Check if the input password matches the expected flag
    if (
        sum == 2471 &&
        (int)s[0] == 'S' &&
        (int)s[1] == 'e' &&
        (int)s[3] == 'u' &&
        (int)s[5] == 'i' &&
        (int)s[7] == 'e' &&
        (int)s[14] == 'k' &&
        (int)s[9] == 's' &&
        (int)s[19] == 'W' &&
        (int)s[4] == 'r' &&
        (int)s[10] == '{' &&
        (int)s[6] == 'n' &&
        (int)s[12] == '4' &&
        (int)s[11] == 'H' &&
        (int)s[13] == 'c' &&
        (int)s[8] == 't' &&
        (int)s[17] == 's' &&
        (int)s[16] == 'r' &&
        (int)s[18] == '_' &&
        (int)s[15] == '3' &&
        (int)s[2] == 'c' &&
        ((int)s[20]-(int)s[22]) == -60 &&
        ((int)s[21]^(int)s[24]) == 0xF &&
        ((int)s[23]+(int)s[20]) == 0x94 &&
        ((int)s[21] ^ (int)s[22]) == 0x1E &&
        ((int)s[20] - (int)s[15]) == -3
    ) {
        printf("CORRECT FLAG!\n");
    } else {
        printf("Incorrect flag. Try again.\n");
    }

    return 0;
}
