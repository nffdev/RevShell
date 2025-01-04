#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <iostream>
#include <string>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

WSADATA wsaData;
SOCKET wSock;
struct sockaddr_in hax;
STARTUPINFO sui;
PROCESS_INFORMATION pi;

int main(int argc, char* argv[])
{
    const char* ip = "127.0.0.1";
    short port = 8080;

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    wSock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);

    hax.sin_family = AF_INET;
    hax.sin_port = htons(port);
    hax.sin_addr.s_addr = inet_addr(ip);

    if (WSAConnect(wSock, (SOCKADDR*)&hax, sizeof(hax), NULL, NULL, NULL, NULL) == SOCKET_ERROR) {
        cout << "Error: Unable to connect to server." << endl;
        WSACleanup();
        return 1;
    }

    const char* request = "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n";
    if (send(wSock, request, strlen(request), 0) == SOCKET_ERROR) {
        cout << "Error: Unable to send request." << endl;
        closesocket(wSock);
        WSACleanup();
        return 1;
    }

    char buffer[1024];
    int bytesReceived = recv(wSock, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        cout << "Response: " << buffer << endl;
    }
    else {
        cout << "Error: No response received or connection closed." << endl;
    }

    closesocket(wSock);
    WSACleanup();

    return 0;
}