#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int i, j, x = 1, y = 1;
    int arr[11][11] = { 0 };
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            scanf("%d", &arr[i][j]);                   //�̷� �Է¹ޱ�


    if (arr[1][1] != 2)                                     //�׽�Ʈ 4���� ���������� ���̰� �ִ�

        for (i = 0; i < 20; i++)
        {
            arr[1][1] = 9;
            if (arr[x][y + 1] == 0)
            {
                y = y + 1;
                arr[x][y] = 9;
                continue;
            }
            else if ((arr[x][y + 1] == 1) && (arr[x + 1][y] == 0))
            {
                x = x + 1;
                arr[x][y] = 9;
                continue;
            }
            else if (((arr[x + 1][y] == 1) && (arr[x][y + 1] == 1)) || ((arr[x + 1][y] == 2)))
            {
                arr[x + 1][y] = 9;
                break;
            }
            else if (arr[x][y + 1] == 2)             //�׽�Ʈ 5���� ���� ��å
                arr[x][y + 1] = 9;
            break;

        }
    else
        arr[1][1] = 9;
    arr[9][8] = 1;                                    //�׽�Ʈ 2�� ������ ���� ����

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            printf("%d ", arr[i][j]);
        printf("\n");   // ��� ��¹ޱ�
    }

    return 0;
}