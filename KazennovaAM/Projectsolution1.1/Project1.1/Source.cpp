#include <stdio.h>
int main()
{
    double h, h2, w, d, pdsp = 650, pdvp = 950, ptree = 660; // средней dsp(550—750 кг/м³), 950 кг/м2 - dvp; 
    double m, m1, m2, m3, m4, m5; // массы
    double k = 0; // счетчик полок;
    do
    {
        printf(" Input h, w, d in meters:");
        scanf("%lf %lf %lf", &h, &w, &d);
    } while ((h < 1.80) || (h > 2.20) || (w < 0.80) || (w > 1.20) || (d < 0.50) || (d > 0.90));
    m1 = h * w * 0.005 * pdvp;
    m2 = 2 * h * d * 0.015 * pdsp;
    m3 = 2 * w * d * 0.015 * pdsp;
    m4 = h * w * 0.01 * ptree; // тк 2 двери по 0.5 * w, то 2 сокращаетсяя;
    h2 = h;
    while (h2 >= 0.40)
    {
        h2 = h2 - 0.4 - 0.015; //вычитаем и толщину полки и расстояние между полками;
        k = k + 1;
    }
    m5 = k * 0.015 * (w - 0.03) * d * pdsp;
    m = m1 + m2 + m3 + m4 + m5;
    printf("m = %lf\n", m);
    return 0;
}