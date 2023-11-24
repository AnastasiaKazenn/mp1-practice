#include <stdio.h>
#define N 5
int main()
{
    int n;
    int i, g;
    int computer[N], people[N], cow, bull;

    do {
        printf("Input line:\n");
        scanf("%d", &n);
    } while ((n < 2) && (n > 5));

    srand((unsigned int)time(0));
    computer[0] = 1 + rand() % 9;
    for (i = 1; i < n; i++)
    {
        int flag;
        do {
            flag = 1;
            computer[i] = rand() % 10;
            for (g = 0; g < i; g++)
            {
                if (computer[i] == computer[g])
                {
                    flag = 0;
                    break;
                }
            }
        } while (flag == 0); //????????? ?????? ???????? + ??????? ???????   
    }

    printf("\n");

    do {
        int num;
        printf("input your answer:");
        scanf("%d", &num);
        if (fill(num, &(people[0]), n) == 0)
        {
            cow = 0, bull = 0;
            for (i = 0; i < n; i++)
            {
                for (g = 0; g < n; g++)
                {
                    if (i != g && computer[i] == people[g])
                        cow++;
                    if (i == g && computer[i] == people[i])
                        bull++;
                }
            }
            printf("count cows:  ");
            printf("%d\n", cow);
            printf("count bulls: ");
            printf("%d\n", bull);
        }
    } while (bull != n);
    printf(" you win! ");
}

int fill(int num, int* people, int n)
{
    int i = 0;
    while (i >= 0 && num != 0)
    {
        people[n - i - 1] = num % 10;
        num /= 10;
        i++;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", people[i]);
    }
    printf("\n");
    if (i < 0)
    {
        return 1;
    }
    return 0;
}