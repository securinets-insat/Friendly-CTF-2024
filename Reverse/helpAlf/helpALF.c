#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bomb() {
    printf("                                  ..-^~~~^-..\n");
    printf("                                .~           ~.\n");
    printf("                               (;:           :;)\n");
    printf("                                (:           :)\n");
    printf("                                  ':._   _.:'\n");
    printf("                                      | |\n");
    printf("                                    (=====)\n");
    printf("                                      | |\n");
    printf("-O-                                   | |\n");
    printf("  \\                                   | |\n");
    printf("  /\\                               ((/   \\))\n");
    printf("       💣 BOOM! You hit the bomb! 💥\n");

    exit(1);
}

int live(char *input);
int love(char *input);
int laugh(char *input);
int hacker(char *input);

int main() {
    char input[20]; 
    printf("OH NO ! ALF ACCIDENTLY LIGHTED A BOMB WITH HIS SPARKY FINGER !\n");
    printf("QUICKKKK ! HELP HIM TO DEFUSE THE BOMB !\n\n");
    printf("             \\|/\n");
    printf("            .-*- \n");
    printf("           / /|\\ \n");
    printf("          _L_ \n");
    printf("        ,\"   \". \n");
    printf("    (\\ /  O O  \\ /) \n");
    printf("     \\|    _    |/ \n");
    printf("       \\  (_)  / \n");
    printf("       _/.___,\\_ \n");
    printf("      (_/ alf \\_)\n");
    printf("\n");
    printf("                                                                    ,-.--.\n");
    printf("  *.______________________________________________________________,' (Bomb)\n");
    printf("                                                                      `--'\n\n");
    printf("Time is ticking, hurry upppp! ⏳\n");
    printf("Give me the Key: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if (strlen(input) == 19) { 
        live(input);
        love(input);
        laugh(input);
        hacker(input);
    } else {
        bomb();
    }

    return 0;
}

int live(char *input) {
    int count = 0x0;
    int offset = 0x0;
    do {
        int eax = input[offset] & 0xff;
        if (eax == 0x0) {
            break;
        }
        if ((input[offset] > ',') && (((input[offset] <= '-') || (input[offset] > '/')))) {
            if ((input[offset] > '9') && (input[offset] <= '@')) {
                printf("LIVE 2");
                bomb();
            } else {
                if (input[offset] > 'Z') {
                    if (input[offset] > '`') {
                        if (input[offset] > 'z') {
                            printf("LIVE 3");
                            bomb();
                        }
                    } else {
                        printf("LIVE 3");
                        bomb();
                    }
                } else {
                    if (input[offset] > 'z') {
                        printf("LIVE 3");
                        bomb();
                    }
                }
            }
        } else {
            printf("LIVE 1");
            bomb();
        }
        count = count + 0x1;
        offset = offset + 0x1;
    } while (1);
    
    if (count != 0x13) {
        puts("LIVE 4");
        bomb();
    }

    int condition_1 = input[0x0] ^ 0x37 == 0x0;
    int condition_2 = input[0x5] ^ 0x48 == 0x0;
    int condition_3 = input[0x8] ^ 0x68 == 0x0;

    if(input[0x6] != 0x4F || input[0x7] != 0x4C || input[0xB] != 0x46 || input[0xC] != 0x73) {
        puts("LIVE 5");
        bomb();
    }

    return 0;
}

int love(char *input) {
    int var_10 = (input[0xa] ^ input[0x8]) + 0x30;
    int var_c = (input[0xd] ^ input[0x5]) + 0x30;
    int var_idk1 = input[0xa] - input[0x8];
    int var_idk2 = input[0xd] - input[0x5];
    int var_idk3 = input[0xa] & input[0x8];
    int var_idk4 = input[0xd] & input[0x5];

    if (var_10 <= 0x39 && var_c <= 0x39) {
        if ((var_10 <= 0x2f) || (var_c <= 0x2f)) {
            puts("Love 1 lower");
            bomb();
            exit(1);
        }
    } else {
        puts("Love 1");
        bomb();
        exit(1);
    }

    if(var_idk1 == 0x7 || var_idk2 == 0x7) {
        if(var_idk3 != 0x68 || var_idk4 != 0x48) {
            puts("Love 4");
            bomb();
            exit(1);
        }
    } else {
        puts("Love 4");
        bomb();
        exit(1);
    }

    if (input[0x3] == var_10 && input[0xf] == var_10) {
        if (input[0] == var_c) {
            if (input[0x12] != var_c) {
                puts("Love 3");
                bomb();
                exit(1);
            }
        } else {
            puts("Love 3");
            bomb();
            exit(1);
        }
    } else {
        puts("Love 2");
        bomb();
        exit(1);
    }
    return 0;
}

int laugh(char *input) {
    int var_10 = input[0x2] + input[0x1];
    int var_c = input[0x11] + input[0x10];
    int var_idk1 = input[0x2] - input[0x1];
    int var_idk2 = input[0x11] - input[0x10];

    if ((var_10 <= 0xaa) && (var_c <= 0xaa)) {
        if (var_10 == var_c) {
            puts("Laugh 2");
            bomb();
            exit(1);
        }
    } else {
        puts("Laugh 1");
        bomb();
        exit(1);
    }

    if (var_idk1 == 0x6 || var_idk2 == 0xd) {
        if(((var_idk2^input[0x10])!= 0x44) || ((var_idk1^input[0x1]) != 0x4b)) {
            puts("Laugh 3");
            bomb();
        }
    } else {
        puts("Laugh 4");
        bomb();
    }

    int condition_a2 = input[2] - 0x37 ; // input[2] should be 
    int condition_a16 = input[16] - 0x49; // input[16] should be 0x49
    int condition_a17 = input[17] - 0x56; // input[17] should be 0x56

    if (condition_a2 != 0) { // if input[2] is not 'S'
        puts("Laugh 5");
        bomb();
    }

    if (condition_a16 != 0) { // if input[16] is not 'I'
        puts("Laugh 5");
        bomb();
    }

    if (condition_a17 != 0) { // if input[17] is not 'V'
        puts("Laugh 5");
        bomb();
    }

    return 0;
}

int hacker(char *input) {
    int var_c = input[0xe] + input[0x4] + input[0x9];
    if (var_c != 0x87) {
        puts("Hacker 1");
        bomb();
    } else {
        if((input[0xe] != input[0x4]) || (input[0x4] != input[0x9]) || (input[0x9] != input[0xe])) {
            puts("Hacker 2");
            bomb();
        }
    }

    printf("             \\|/\n");
    printf("            .-*-         \n");
    printf("           / /|\\         \n");
    printf("          _L_            \n");
    printf("        ,\"   \".          \n");
    printf("    (\\ /  O O  \\ /)             YAAYYYY HAPPY ALF !  \n");
    printf("     \\|    _    |/       \n");
    printf("       \\  \\_/  /         \n");
    printf("       _/.___,\\_         \n");
    printf("      (_/ alf \\_)        \n");
    return 0;
}
