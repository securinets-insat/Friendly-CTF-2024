#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256
#define KEY_LENGTH 16

// Function to initialize the pseudo-random number generator and generate a key
void generate_key(char *key, const char *seed) {
    unsigned long seed_value = 0;
    for (int i = 0; i < strlen(seed); i++) {
        seed_value = seed_value * 31 + seed[i]; // Simple hash to generate seed value
    }
    
    srand(seed_value); // Initialize PRNG with the hash of the seed
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256; // Generate a random byte key
    }
}

// Function to encrypt/decrypt the string using XOR and a key
void encrypt(const char *input, char *output, const char *key, int key_length) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ key[i % key_length]; // XOR with key
    }
    output[len] = '\0'; // Null-terminate the output string
}

void bytes_to_hex(const char *input, char *hex_output, int length) {
    for (int i = 0; i < length; i++) {
        sprintf(hex_output + (i * 2), "%02X", (unsigned char)input[i]); // Convert each byte to hex and store in hex_output
    }
    hex_output[length * 2] = '\0'; // Null-terminate the hex string
}

int main() {
    char input[MAX_LENGTH], encrypted[MAX_LENGTH];
    char key[KEY_LENGTH];
    char hex_encrypted[MAX_LENGTH * 2 + 1];
    const char *seed = "Securinets{s33d}"; 

    printf("Enter the password: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; 

    generate_key(key, seed);
    encrypt(input, encrypted, key, KEY_LENGTH);
    bytes_to_hex(encrypted, hex_encrypted, strlen(input));

    if(strcmp(hex_encrypted, "D823D2CD2708D982C96CAFFDADF39028B875D5CB0A258485C878B399B7BE") == 0) {
        printf("YESS.. Noice Work !\n");
        return 0;
    } else {
        printf("Nope.. Try Again !\n");
    }

    return 0;
}
