#define _WIN32_WINNT 0x0501
#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

void scan_port(const char *host, int port) {
    SOCKET sock;
    struct sockaddr_in server;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) return;

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    // Set timeout to 500ms
    DWORD timeout = 500;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout, sizeof(timeout));

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
        printf("[OPEN]   Port %d\n", port);
    }

    closesocket(sock);
}

int main() {
    WSADATA wsa;
    char host[100];
    int start_port, end_port;

    WSAStartup(MAKEWORD(2, 2), &wsa);

    printf("=== GuardianScan - Port Scanner ===\n");
    printf("Enter target IP (e.g. 127.0.0.1): ");
    scanf("%s", host);
    printf("Enter start port: ");
    scanf("%d", &start_port);
    printf("Enter end port: ");
    scanf("%d", &end_port);

    printf("\nScanning %s from port %d to %d...\n\n", host, start_port, end_port);

	int port;
	for (port = start_port; port <= end_port; port++) {
        scan_port(host, port);
    }

    printf("\nScan complete.\n");
    WSACleanup();
    return 0;
}
