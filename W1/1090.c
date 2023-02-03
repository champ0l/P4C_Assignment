#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    long long int answer = 1, a, r, n, i;
    scanf("%lld %lld %lld", &a, &r, &n);      //첫항 a, 공비 r, 횟수 n을 입력받는다.
    for (i = 1; i < n; i++)
        answer = answer * r;                       //점화식을 사용하여 등비수열을 만든다.
    printf("%lld", answer * a);                    //마지막에 첫항을 곱해주며 출력한다.

    return 0;
}