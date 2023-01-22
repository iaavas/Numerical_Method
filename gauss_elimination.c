#include <stdio.h>
#define SIZE 20
int main()
{
    int n;

    float arr[SIZE][SIZE], ratio;
    float x[SIZE];

    printf("Enter no of variables:  ");
    scanf("%d", &n);

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n + 1; col++)
        {
            printf("Enter a[%d][%d] = ", row + 1, col + 1);
            scanf("%f", &arr[row][col]);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            if (i != j)
            {

                ratio = arr[j][i] / arr[i][i];
                for (int k = 0; k < n + 1; k++)
                {
                    arr[j][k] = arr[j][k] - ratio * arr[i][k];
                }
            }
        }
    }

    printf("\n");
    // display
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n + 1; col++)
        {

            printf("%5.2f | ", arr[row][col]);
        }
        printf("\n");
    }

    x[n] = arr[n - 1][n] / arr[n - 1][n - 1];

    printf("\n");

    for (int i = n - 1; i > 0; i--)
    {
        x[i] = arr[i - 1][n];

        for (int j = n; j != i; j--)
        {

            x[i] -= arr[i - 1][j - 1] * x[j];

            // printf("%f", x[j - 1]);
        }
        x[i] /= arr[i - 1][i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        printf("x[%d] =  %2.2f \n", i, x[i]);
    }

    printf("\n\n\n\n");

    return 0;
}