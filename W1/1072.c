#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d", &a);      //������ ���� a�� �Է¹޴´�.
reget:
    scanf("%d", &b);      //���� b�� �Է¹ް� �״�� ����Ѵ�.
    printf("%d\n", b);
    if (--a != 0) goto reget;   //a�� 0�� �ƴϸ� 1�� �����ϰ� goto���� �̿��Ͽ� �ٽ� b�� �Է¹����� �Ž��� �ö󰣴�.
    return 0;                            //a�� 0�� �Ǹ� goto���� ���̻� �۵����� �ʴ´�.
}