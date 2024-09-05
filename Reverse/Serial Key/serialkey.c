#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter serial key: ");
    char serial_key[123];
    scanf("%123s", serial_key);

    int condition1 = 0;
    while(serial_key[condition1] != '\0') {
        condition1++;
    }

    int i = 0;
    int condition2 = 1;
    while (i < condition1)
    {   
        if (i % 2 == 0)
        {
            if ((serial_key[i] - '0') % 2 != 0)
            {
                condition2 = 0;
                break;
            }
        }
        else
        {
            if ((serial_key[i] - '0') % 2 != 1)
            {
                condition2 = 0;
                break;
            }
        }
        i++;
    }

    int condition3 = 1;
    for (i = 0; i <= condition1 - 6; i += 3) {
        int sum1 = (serial_key[i] - '0') + (serial_key[i+1] - '0') + (serial_key[i+2] - '0');
        int sum2 = (serial_key[i+3] - '0') + (serial_key[i+4] - '0') + (serial_key[i+5] - '0');
        if (sum1 <= sum2) {
            condition3 = 0;
            break;
        }
    }

    int condition4 = 0;
    int sum_all_digits = 0;
    for (i = 0; i < condition1; i++) {
        sum_all_digits += (serial_key[i] - '0');
    }

    if (sum_all_digits == 159) {
        condition4 = 1;
    }

    int condition5 = 0;
    if (strncmp(serial_key, "89898", 5) == 0 && strncmp(&serial_key[condition1-5], "12125", 5) == 0) {
        condition5 = 1;
    }

    int all_conditions_true = (condition1 == 30) && condition2 && condition3 && condition4 && condition5;

    if(all_conditions_true) {
        printf("Securinets{%s}\n", serial_key);
        return 0;
    } else {
        printf("Try again.\n");
        return 1;
    }
}
