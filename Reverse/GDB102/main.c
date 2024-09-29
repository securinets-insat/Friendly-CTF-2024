#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_file(const char *filename) {
    FILE *file;
    char *buffer = NULL;
    size_t length = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL; 
    }

    fseek(file, 0, SEEK_END);      
    length = ftell(file);          
    fseek(file, 0, SEEK_SET);      

    buffer = (char *)malloc(length + 1);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL; 
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0'; 

    fclose(file);
    return buffer;
}

int main() {
    char *str = read_file("flag.txt");
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];
        char var1 = c << 1;
        char var2 = c & 0xAA; 
        char var3 = (c & 0x01); 
        char var4 = c & 0x55;
        char var5 = (var2 | var4); 
    }

    for (int i = 0; i < len / 2; i++) {
        str[i] = str[i] ^ str[len - i - 1];
        str[len - i - 1] = str[i] ^ str[len - i - 1];
        str[i] = str[i] ^ str[len - i - 1];
    }

    for (int i=0; i<len; i++) {
        str[i] = str[i] ^ i;
    }

    return 0;
}
