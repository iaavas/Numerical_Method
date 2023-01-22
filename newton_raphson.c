#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * log10(x) - 1.2;
}
float df(float x)
{
    return log(x) + 0.4232;
}

int main()
{
    int itr, maxitr;
    float h, aerr, x0, x1;
    printf("Enter x0, maxitr,aerr : \n");
    scanf("%f %d %f", &x0, &maxitr, &aerr);

    for (int itr = 1; itr <= maxitr; itr++)
    {

        h = (f(x0) / df(x0));
        x1 = x0 - h;

        printf("\nFor Root = %9.4f and iteration no  = %d \n", x1, itr);

        if (fabs(h) < aerr)
        {
            printf("\nRoot is %9.4f and no of iterations is %3d \n", x1, itr);
            return 0;
        }
        x0 = x1;
    }

    printf("Not of iternations are not sufficient");
    return 0;
}