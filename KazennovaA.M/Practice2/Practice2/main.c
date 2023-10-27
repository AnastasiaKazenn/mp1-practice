#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int option, max = 1000, min = 0, k = 0, num1, num2, startnumber = 500;
    char i = '0';
    do{
        printf("which mode do you want to select? 1 - you guess the numbers, 2 - computer guesses the number");
        scanf("%d", &option);
    } while ((option != 1) && (option != 2));   
    if (option == 1)
    {
        srand((unsigned int)time(0));
        num1 = ((max - min) * rand(0) / RAND_MAX + min);
        do
        {
            printf("\nInput you answer\n");
            scanf("%d", &num2);

            k ++ ;
            if (num1 < num2)
            {
                max = num2;
                printf("The hidden number is less\n"); //загаданное число меньше; 
                printf("range %d %d", min, max, "\n");
            }
            else if (num1 > num2)
            {
                min = num2;
                printf("The hidden number is bigger\n");//загаданное число больше;
                printf("range %d %d", min, max, "\n");
            }
            else
                printf("you guessed right\n");
        } while (num1 != num2);
    }
    else
    {    
        while (i != "=")
        {
            printf("%d\n", startnumber);
            printf("answer <, > , =\n");
            scanf("\n%c", &i);
            if (i == '<')
                max = startnumber;
            else if (i == '>')
                min = startnumber;
            else if (i == '=')
                printf("number guessed\n");
            startnumber = (min + max) / 2;
        }
    }
    printf("number of attempts %d", k);
    return 0;
}