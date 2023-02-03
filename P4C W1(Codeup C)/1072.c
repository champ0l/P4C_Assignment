#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d", &a);      //정수의 개수 a를 입력받는다.
reget:
    scanf("%d", &b);      //정수 b를 입력받고 그대로 출력한다.
    printf("%d\n", b);
    if (--a != 0) goto reget;   //a가 0이 아니면 1을 차감하고 goto문을 이용하여 다시 b를 입력받으러 거슬러 올라간다.
    return 0;                            //a가 0이 되면 goto문은 더이상 작동하지 않는다.
}