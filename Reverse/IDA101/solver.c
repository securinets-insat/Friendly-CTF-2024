#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

void generate_key(char *key, const char *seed) {
    unsigned long seed_value = 0;
    for (int i = 0; i < strlen(seed); i++) {
        seed_value = seed_value * 31 + seed[i];
    }
    
    srand(seed_value);
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
}

void hex_to_bytes(const char *hex, unsigned char *bytes, int *length) {
    int len = strlen(hex) / 2;
    for (int i = 0; i < len; i++) {
        sscanf(hex + 2 * i, "%2hhx", &bytes[i]);
    }
    *length = len;
}

void xor_decrypt(const unsigned char *input, unsigned char *output, const unsigned char *key, int input_length, int key_length) {
    for (int i = 0; i < input_length; i++) {
        output[i] = input[i] ^ key[i % key_length];
    }
}

int main() {
    const char *hex_encrypted_text = "D823D2CD2708D982C96CAFFDADF39028B875D5CB0A258485C878B399B7BE";
    char key[KEY_LENGTH];
    const char *seed = "Securinets{s33d}";
    generate_key(key, seed);

    unsigned char encrypted_bytes[1024];
    unsigned char decrypted_bytes[1024];
    int encrypted_length;
    
    hex_to_bytes(hex_encrypted_text, encrypted_bytes, &encrypted_length);

    xor_decrypt(encrypted_bytes, decrypted_bytes, key, encrypted_length, KEY_LENGTH);

    printf("Decrypted text: ");
    for (int i = 0; i < encrypted_length; i++) {
        printf("%c", decrypted_bytes[i]);
    }
    printf("\n");

    return 0;
}
