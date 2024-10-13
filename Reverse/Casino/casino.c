#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIN_GOAL 1234

struct Coin {
    int value;
    int quantity;
};

void display_banner() {
    printf("=====================\n");
    printf("  WELCOME TO CASINO  \n");
    printf("     Author: jio     \n");
    printf("=====================\n");
}

void slot_animation() {
    const char *slots[] = {"[X]", "[O]", "[#]", "[@]", "[%]"};

    for (int i = 0; i < 10; i++) {
        // Print 5 random slots instead of 3
        printf(" %s %s %s %s %s\r", 
            slots[rand() % 5], 
            slots[rand() % 5], 
            slots[rand() % 5], 
            slots[rand() % 5], 
            slots[rand() % 5]
        );
        fflush(stdout);
        usleep(200000);  // Sleep for 200 milliseconds
    }
    printf("\n");
}

void gamble(struct Coin *coins, int *balance, int *totalCoins) {
    if (*totalCoins <= 0) {
        printf("You don't have any coins to gamble.\n");
        return;
    }

    int betType;
    printf("Choose the coin type to gamble:\n");
    printf("1. $1 coins (%d available)\n", coins[0].quantity);
    printf("2. $10 coins (%d available)\n", coins[1].quantity);
    printf("3. $20 coins (%d available)\n", coins[2].quantity);
    printf("4. $100 coins (%d available)\n", coins[3].quantity);
    scanf("%d", &betType);

    if (betType < 1 || betType > 4 || coins[betType - 1].quantity <= 0) {
        printf("Invalid choice or no coins of this type available.\n");
        return;
    }

    struct Coin *selectedCoin = &coins[betType - 1];

    slot_animation();

    srand(time(NULL));
    int loss = rand() % selectedCoin->value;

    printf("You gambled a $%d coin and lost $%d!\n", selectedCoin->value, loss);
    selectedCoin->quantity--;
    (*totalCoins)--;

    int remaining = selectedCoin->value - loss;
    printf("You received $%d back from the gamble.\n", remaining);
    
    *balance += remaining;
    printf("New balance: $%d\n", *balance);
}

void buy_coins(struct Coin *coins, int *balance, int *totalCoins) {
    int choice, amount;
    printf("Choose the coin package to buy:\n");
    printf("1. $1 coins\n");
    printf("2. $10 coins\n");
    printf("3. $20 coins\n");
    printf("4. $100 coins\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice.\n");
        return;
    }

    printf("Enter the number of coins to buy: ");
    scanf("%d", &amount);

    if ((choice == 1 || choice == 3 || choice == 4) && amount < 1) {
        printf("Invalid: You must buy at least 1 coin!\n");
        return;
    }

    struct Coin *selectedCoin = &coins[choice - 1];
    int cost = selectedCoin->value * amount;

    *balance -= cost;
    selectedCoin->quantity += amount;
    *totalCoins += amount;

    printf("You bought %d $%d coins. New balance: $%d\n", amount, selectedCoin->value, *balance);
}


int main() {
    setbuf(stdout,0);
    setbuf(stdin,0);

    struct Coin coins[] = {{1, 0}, {10, 0}, {20, 0}, {100, 0}};
    srand(time(NULL));
    int balance = rand() % 100 + 1;
    int totalCoins = 0;

    slot_animation();
    display_banner();
    slot_animation();

    while (balance > 0) {
        printf("\nCurrent Balance: $%d\n", balance);
        printf("Coins: %d (1$:%d, 10$:%d, 20$:%d, 100$:%d)\n",
               totalCoins, coins[0].quantity, coins[1].quantity, coins[2].quantity, coins[3].quantity);

        printf("Choose an option:\n");
        printf("1. Buy coins\n");
        printf("2. Gamble\n");
        printf("3. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                buy_coins(coins, &balance, &totalCoins);
                break;
            case 2:
                gamble(coins, &balance, &totalCoins);
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                return 1;
        }

        if (balance == WIN_GOAL) {
            FILE *file = fopen("flag.txt", "r");
            if (file) {
                char line[256];
                while (fgets(line, sizeof(line), file)) {
                    printf("%s", line);
                }
                fclose(file);
            } else {
                printf("Error: flag.txt not found.\n");
            }
            break;
        }
    }

    if (balance == 0) {
        printf("\nYou're broke. Gambling is bad!\n");
    } else if (balance < 0) {
        printf("\nYou're in debt! Don't gamble ever again!\n");
    }

    return 0;
}
