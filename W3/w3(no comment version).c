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
	SOCKADDR_IN server_addr, client_addr; 
	HOSTENT* IpHost; 
	IN_ADDR inaddr; 
	#define PORT_NUM 10000

	int i, j;
	unsigned char buf[1024], path[1024], html[2048];
	char myName[256], myIp[16];

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) == SOCKET_ERROR)
	{
		printf("WSAStartup Error\n");
		return 1;
	}

	gethostname(myName, sizeof(myName));

	IpHost = gethostbyname(myName);

	for (i = 0; IpHost->h_addr_list[i]; i++)
	{
		memcpy(&inaddr, IpHost->h_addr_list[i], 4);
	}

	strcpy(myIp, inet_ntoa(inaddr));
	printf("build server: http://%s:%d\n", myIp, PORT_NUM);

	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == INVALID_SOCKET)
	{
		printf("socket : %d\n", WSAGetLastError());
		return 1;
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_NUM);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(server_socket, &server_addr, sizeof(server_addr)) == SOCKET_ERROR)
	{
		printf("bind : %d\n", WSAGetLastError());
		return 1;
	}

	if (listen(server_socket, 5) == SOCKET_ERROR)
	{
		printf("listen : %d\n", WSAGetLastError());
		return 1;
	}

	while (1)
	{
		int client_addr_length = sizeof(client_addr);
		client_socket = accept(server_socket, &client_addr, &client_addr_length);

		if (client_socket == INVALID_SOCKET)
		{
			printf("accept : %d\n", WSAGetLastError());
			break;
		}

		memset(path, 0, 1024);
		memset(html, 0, 2048);

		int recv_len = recv(client_socket, buf, 1024, 0);
		if (recv_len <= 0)
			continue;

		buf[recv_len - 1] = 0;
		if (buf[0] == '\0')
			strcpy(buf, NULL);
		printf("%s \n", buf);

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

		printf("request : %s \n", path);
		unsigned char* header =
			"HTTP/1.0 200 OK\n"
			"Content-type: text/html\n"
			"\n";

		send(client_socket, header, strlen(header), 0);

		char file_path[256] = { 0, };
		sprintf_s(file_path, sizeof(file_path), "d:\\1000. COM\\HTML\\%s", path);

		FILE* fp;
		if (fopen_s(&fp, file_path, "rb") == 0)
		{
			fread(html, sizeof(html), 1, fp);
			fclose(fp);
		}

		if (send(client_socket, html, strlen(html), 0) == SOCKET_ERROR)
		{
			printf("send : %d\n", WSAGetLastError());
			break;
		}

		closesocket(client_socket);
	}

	closesocket(server_socket);
	WSACleanup();
	return 0;
}