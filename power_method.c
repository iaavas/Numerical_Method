#include <stdio.h>
#include <math.h>
#define N 3

float returnMax(float arr[N][1])
{

    float max = fabs(arr[0][0]);
    for (int i = 1; i < N; i++)
    {
        if (fabs(arr[i][0]) > max)
        {
            max = fabs(arr[i][0]);
        }
    }
    return fabs(max);
}
float divideArr(float arr[N][1], float x)
{
    for (int i = 0; i < N; i++)
    {
        arr[i][0] /= x;
    }
}

void multiplyMatrices(float firstMatrix[][N], float secondMatrix[][1], float mult[][1])
{
    int i, j, k;

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < 1; ++j)
        {
            mult[i][j] = 0;
        }
    }

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < 1; ++j)
        {
            for (k = 0; k < N; ++k)
            {
                mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main()
{
    int maxitr, itr;
    float aerr;

    float m[N][N];
    float o[N][1];

    float g[N][1];

    printf("Enter maxitr, aerr: ");
    scanf("%d%f", &maxitr, &aerr);

    printf("Enter matrix rowwise: ");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%f", &m[i][j]);
        }
    }

    printf("Enter guess: ");

    for (int i = 0; i < N; i++)
    {
        scanf("%f", &g[i][0]);
    }
    float prev = 0;
    for (itr = 0; itr < maxitr; itr++)
    {
        multiplyMatrices(m, g, o);

        float val = returnMax(o);
        divideArr(o, val);
        printf("%f=>\t\t", val);
        for (int i = 0; i < N; i++)
        {

            printf(" %f ", o[i][0]);
        }
        printf("\n");
        for (int i = 0; i < N; i++)
        {
            g[i][0] = o[i][0];
        }
        if ((val - prev) < aerr)
        {
            printf("The max eigen value is %f", val);
            return 1;
        }

        prev = val;
    }
    return 0;
}