#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int h, w, n, l, d, x, y, i, j;
    int a[100][100] = { 0 };

    scanf("%d %d", &h, &w);            //격자판의 가로와 세로의 길이를 입력받는다.
    for (i = 1; i <= h; i++)
    {
        for (j = 1; j <= w; j++)
            a[i][j] = 0;
    }
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d %d %d %d", &l, &d, &x, &y);
        if (d == 0)
        {
            for (j = y; j < l + y; j++)
                a[x][j] = 1;
        }
        else
        {
            for (j = x; j < l + x; j++)
                a[j][y] = 1;
        }
    }
    for (i = 1; i <= h; i++)
    {
        for (j = 1; j <= w; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}