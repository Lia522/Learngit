#include <stdio.h>

int main()
{
    int n;
    double pi = 0.0;

    printf("请输入要计算的项数: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            pi += 1.0 / (2 * i + 1);
        }
        else
        {
            pi -= 1.0 / (2 * i + 1);
        }
    }

    pi *= 4;

    printf("π 的近似值为: %lf\n", pi);

    return 0;
}
