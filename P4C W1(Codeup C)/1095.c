#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int t = 0, n, i;
    int a[10000] = { 0 };
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    t = a[1];
    for (i = 1; i < n; i++)
    {
        if (t > a[i + 1])
            t = a[i + 1];
    }
    printf("%d\n", t);

    return 0;
}