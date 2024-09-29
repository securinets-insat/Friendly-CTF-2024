#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printGrid(char grid[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int check(char grid[10][10], char c) {
    int found = 0;
    int x1 = rand() % 10;
    int y1 = rand() % 10;
    if (grid[x1][y1] == c) {
        found = 1;
    }
    return found;
}

const char* construct(const char* charset){
    printf("%s%s%s%s%s%s : ",charset[1],charset[0],charset[44],charset[4],charset[62],charset[60]);
    return "TTNsaV9NM2wwXzFzX2ZVTg==";
}

void melimelo(){
    printf("Congratulations ! You are now a melimelo master !\n");
    printf(construct("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_(){}"));
}
void nomelimelo(){
    printf("You are not a melimelo master ! BOOOOO >:( \n");
}

int main() {
    printf(" _        _   ______           0         _        _   ______            ______ \n");
    printf("| \\      / | |        |        |        | \\      / | |        |        |      |\n");
    printf("|  \\    /  | |        |        |        |  \\    /  | |        |        |      |\n");
    printf("|   \\  /   | |___     |        | _____  |   \\  /   | |___     |        |      |\n");
    printf("|    \\/    | |        |        |        |    \\/    | |        |        |      |\n");
    printf("|          | |        |        |        |          | |        |        |      |\n");
    printf("|          | |______  |_______ |        |          | |______  |_______ |______|\n");
    printf("\n\n");
    printf("Here is your grid : \n");

    int r=1;
    int i=0;

    while(r) {
        if(i == 5){
            melimelo();
            exit(1);
        }
        srand(time(0));
        char grid[10][10];
     
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_(){}";
                int charsetSize = sizeof(charset) - 1;
                grid[i][j] = charset[rand() % charsetSize];
            }
        }
     
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }

        printf("Choose the right character : ");
        char c;
        scanf("%c", &c);

        r = check(grid, c);
        i++;
    }

    nomelimelo();

    return 0;
}
