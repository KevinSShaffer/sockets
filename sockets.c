
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsa;
    SOCKET sock;

    printf("\nInitialising Winsock...");

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Failed.  Error Code : %d", WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d", WSAGetLastError());
        return 1;
    }

    printf("Socket created.\n");

    if (closesocket(sock) == SOCKET_ERROR)
    {
        printf("Could not close socket : %d", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    printf("Socket closed.\n");

    WSACleanup();
    return 0;
}