#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    printf("Enter serial key: ");
    char serial_key[123];
    scanf("%123s", serial_key);

    int condition1 = 0;
    while (serial_key[condition1] != '\0')
    {
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
    for (i = 0; i <= condition1 - 6; i += 3)
    {
        int sum1 = (serial_key[i] - '0') + (serial_key[i + 1] - '0') + (serial_key[i + 2] - '0');
        int sum2 = (serial_key[i + 3] - '0') + (serial_key[i + 4] - '0') + (serial_key[i + 5] - '0');
        if (sum1 <= sum2)
        {
            condition3 = 0;
            break;
        }
    }

    int condition4 = 0;
    int sum_all_digits = 0;
    for (i = 0; i < condition1; i++)
    {
        sum_all_digits += (serial_key[i] - '0');
    }

    if (sum_all_digits == 134)
    {
        condition4 = 1;
    }

    int condition5 = 0;
    if (strncmp(serial_key, "89898", 5) == 0 && strncmp(&serial_key[condition1 - 5], "12125", 5) == 0)
    {
        condition5 = 1;
    }

    int condition6 = 1;
    for (i = 0; i < condition1; i++)
    {
        if (serial_key[i] == '0')
        {
            condition6 = 0;
            break;
        }
    }

    int condition7 = 0;
    char fourth_group[4];
    fourth_group[0] = serial_key[9];
    fourth_group[1] = serial_key[10];
    fourth_group[2] = serial_key[11];
    fourth_group[3] = '\0';

    int fourth_group_number = atoi(fourth_group);

    if (sqrt(fourth_group_number) == 27)
    {
        condition7 = 1;
    }

    char third_group[4];
    third_group[0] = serial_key[6];
    third_group[1] = serial_key[7];
    third_group[2] = serial_key[8];
    third_group[3] = '\0';

    int condition8 = strncmp(third_group, "698", 3) == 0;

    int condition9 = (serial_key[13] - '0') == (serial_key[12] - '0') + 1 &&
                     (serial_key[14] - '0') == (serial_key[13] - '0') + 1 &&
                     (serial_key[15] - '0') == (serial_key[14] - '0') + 1;

    int all_conditions_true = (condition1 == 24) && condition2 && condition3 && condition4 && condition5 && condition6 && condition7 && condition8 && condition9;

    if (all_conditions_true)
    {
        printf("Securinets{%s}\n", serial_key);
        return 0;
    }
    else
    {
        printf("Try again.\n");
        return 1;
    }
}
