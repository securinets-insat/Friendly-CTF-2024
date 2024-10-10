#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "4321[w6sH{~gek`>";
    int len = strlen(str);


    for (int i=0; i<len; i++) {
        str[i] = str[i] ^ i;
    }
   
    for (int i = 0; i < len / 2; i++) {
        str[i] = str[i] ^ str[len - i - 1];
        str[len - i - 1] = str[i] ^ str[len - i - 1];
        str[i] = str[i] ^ str[len - i - 1];
    }

    printf("Reversed string: %s\n", str);
    return 0;
}
