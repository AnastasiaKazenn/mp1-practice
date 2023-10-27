#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int option, max = 1000, min = 0, k = 0, num1, num2, startnumber = 500;
    do {
        printf("which mode do you want to select? 1 - you guess the numbers, 2 - computer guesses the number");
        scanf("%d", &option);
    } while ((option != 1) && (option != 2));
    if (option == 1)
    {
        srand((unsigned int)time(0));
        num1 = 1 + rand() / 1000;
        do
        {
            printf("\nInput you answer\n");
            scanf("%d", &num2);

            k++;
            if (num1 < num2)
            {
                max = num2;
                printf("The hidden number is less\n"); //загаданное число меньше; 
                printf("range %d %d\n", min, max);
            }
            else if (num1 > num2)
            {
                min = num2;
                printf("The hidden number is bigger\n");//загаданное число больше;
                printf("range %d %d\n", min, max);
            }
            else
                printf("you guessed right\n");
        } while (num1 != num2);
    }
    else
    {
        printf("input you number:\n");
        scanf("%d", &num1);
        char i;
        do
        {
            printf("you numder %d\n", num1);
            printf("Assumption:");
            printf("%d\n", startnumber);
            printf("answer <, > , =\n");
            scanf("%*c%c", &i);
            if (i == '<')
                max = startnumber;
            else if (i == '>')
                min = startnumber;
            else if (i == '=')
                printf("number guessed\n");
            startnumber = (min + max) / 2;
            k++;
        } while (i != '=');
    }
    printf("number of attempts %d", k);
    return 0;
}