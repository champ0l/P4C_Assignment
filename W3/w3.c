#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Winsock2.h>
#include <windows.h>
#include <tchar.h>
#pragma comment(lib, "ws2_32.lib") 

int main()
{
	WSADATA wsaData;
	SOCKET server_socket, client_socket;
	SOCKADDR_IN server_addr, client_addr; //socket에 주소와 port 할당
	HOSTENT* IpHost; //호스트 정보를 저장
	IN_ADDR inaddr; //IP 주소를 저장
	#define PORT_NUM 10000 //포트 번호 10000번 지정

	int i, j;
	unsigned char buf[1024], path[1024], html[2048];
	char myName[256], myIp[16];

	//winsock2 dll 사용 시작
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) == SOCKET_ERROR)
	{
		printf("WSAStartup Error\n");
		return 1;
	}

	//호스트 이름을 획득(내 PC이름)
	gethostname(myName, sizeof(myName));

	//gethostbyname은 호스트 이름에 상응하는 hostent타입의 구조체를 반환
	IpHost = gethostbyname(myName);

	for (i = 0; IpHost->h_addr_list[i]; i++)
	{
		memcpy(&inaddr, IpHost->h_addr_list[i], 4);
	}

	//네트워크 바이트 순서 정렬을 문자열로 형태변환하여 IP에 아이피 주소를 저장
	strcpy(myIp, inet_ntoa(inaddr));
	printf("build server: http://%s:%d\n", myIp, PORT_NUM);

	//서버 소켓 생성
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == INVALID_SOCKET)
	{
		printf("socket : %d\n", WSAGetLastError());
		return 1;
	}

	//주소 정보 할당
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_NUM);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	//소켓 bind
	if (bind(server_socket, &server_addr, sizeof(server_addr)) == SOCKET_ERROR)
	{
		printf("bind : %d\n", WSAGetLastError());
		return 1;
	}

	//소켓 listen
	if (listen(server_socket, 5) == SOCKET_ERROR)
	{
		printf("listen : %d\n", WSAGetLastError());
		return 1;
	}

	while (1)
	{
		//소켓 accept & 클라이언트 소켓 생성
		int client_addr_length = sizeof(client_addr);
		client_socket = accept(server_socket, &client_addr, &client_addr_length);

		if (client_socket == INVALID_SOCKET)
		{
			printf("accept : %d\n", WSAGetLastError());
			break;
		}

		//초기화
		memset(path, 0, 1024);
		memset(html, 0, 2048);

		//소켓 recv(소켓으로부터 데이터 수신)
		int recv_len = recv(client_socket, buf, 1024, 0);
		if (recv_len <= 0)
			continue;

		//마지막 열의 儆문자들 제거하여 출력
		buf[recv_len - 1] = 0;
		if (buf[0] == '\0')
			strcpy(buf, NULL);
		printf("%s \n", buf);

		//request method가 GET일 경우(본 코드에서는 GET만 받음)
		for (i = 0; i < strlen(buf); i++)
		{
			if (memcmp(buf + i, "GET ", 4) == 0)
			{
				for (j = 0; buf[4 + j] != ' '; j++)
				{
					path[j] = buf[4 + j];
				}
				break;
			}
		}

		//response 설정
		printf("request : %s \n", path);
		unsigned char* header =
			"HTTP/1.0 200 OK\n"
			"Content-type: text/html\n"
			"\n";

		//send header
		send(client_socket, header, strlen(header), 0);

		char file_path[256] = { 0, };
		sprintf_s(file_path, sizeof(file_path), "d:\\1000. COM\\HTML\\%s", path);

		//HTML파일 열어서 읽기
		FILE* fp;
		if (fopen_s(&fp, file_path, "rb") == 0)
		{
			fread(html, sizeof(html), 1, fp);
			fclose(fp);
		}

		//send HTML
		if (send(client_socket, html, strlen(html), 0) == SOCKET_ERROR)
		{
			printf("send : %d\n", WSAGetLastError());
			break;
		}

		//클라이언트 소켓 종료
		closesocket(client_socket);
	}

	//서버 소켓 종료
	closesocket(server_socket);

	//winsock2 dll 사용 종료
	WSACleanup();

	//종료
	return 0;
}