#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    long long int answer = 1, a, r, n, i;
    scanf("%lld %lld %lld", &a, &r, &n);      //ù�� a, ���� r, Ƚ�� n�� �Է¹޴´�.
    for (i = 1; i < n; i++)
        answer = answer * r;                       //��ȭ���� ����Ͽ� �������� �����.
    printf("%lld", answer * a);                    //�������� ù���� �����ָ� ����Ѵ�.

    return 0;
}