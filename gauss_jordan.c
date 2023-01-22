#include <stdio.h>
#include <math.h>
#define SIZE 20
int main()
{
    int n;
    float arr[SIZE][SIZE], ratio;

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

    //  3 0 0 3 - > 1  1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
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
    for (int row = 0; row < n; row++)
    {
        float op_ratio = arr[row][row];
        for (int col = 0; col < n + 1; col++)
        {
            if (arr[row][col] != 0)
            {
                arr[row][col] /= op_ratio;
            }
            printf("%5.2f | ", arr[row][col]);
        }
        printf("\n");
    }

    return 0;
}