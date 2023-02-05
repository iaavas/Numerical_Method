#include <stdio.h>
#define N 4

float fxn(float x)
{
    return x * x;
}

void main()
{

    float x[N], y[N], b, a, h, s;

    printf("Enter upper and lower limit: ");
    scanf("%f%f", &b, &a);

    h = (b - a) / N;

    s = fxn(a) + fxn(b);
    int c = 1;
    for (float i = a + h; i < b; i = i + h)
    {
        if (c % 2 == 1)
        {

            s += 4 * fxn(i);
        }
        else
        {
            s += 2 * fxn(i);
        }
        c++;
    }
    s = s * h / 3;

    printf("%f", s);
}