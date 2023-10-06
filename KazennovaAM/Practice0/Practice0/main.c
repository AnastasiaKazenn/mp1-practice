#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, r1, x2, y2, r2, d;
    printf("Input x1, y1, r1: ");
    scanf("%f %f %f", &x1, &y1, &r1);
    printf("Input x2, y2, r2: ");
    scanf("%f %f %f", &x2, &y2, &r2);
    if ((r1 <= 0) || (r2 <= 0))
    {
        printf("ancorretc radius");
        return 0;
    }
    d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if ((d == 0) && (r1 == r2))
    {
        printf("the circles coincide");
    }
    else if (d > (r1 + r2))
    {
        printf("no common points");
    }
    else if (d == (r1 + r2))
    {
        printf("one common point or do they touch");
    }
    else if (d == (abs(r1 - r2)))
    {
        printf("one common point and one circle inside the second");
    }
    else if (d < abs(r1 - r2)) 
    {
        printf("no common points and one circle inside the second");
    }
    else 
    {
        printf("two common point");
    }
    return 0;
}