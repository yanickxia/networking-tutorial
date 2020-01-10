//
// Created by yanick on 1/4/20.
//

#include <cstdio>
#include <sys/socket.h>
#include <cstdarg>
#include <cstdlib>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

void handler_connection(int);

int main(int argc, char *argv[]) {

    setbuf(stdout, NULL);

    printf("multi server [fork] sample...\n");

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("could create socket...\n");
        exit(2);
    }

    struct sockaddr_in server, client;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *) &server, sizeof(server)) != 0) {
        printf("listen server at 8080, failed");
        exit(2);
    }
    printf("Listen at 8080\n");

    listen(server_fd, 100);
    printf("Waiting for incoming connections....\n");

    int c = sizeof(struct sockaddr_in);
    char str[INET_ADDRSTRLEN];

    while (1) {
        int new_socket = accept(server_fd, (struct sockaddr *) &client, (socklen_t *) &c);
        inet_ntop(AF_INET, &(client.sin_addr), str, INET_ADDRSTRLEN);
        printf("accept new connection from %s\n", str);

        if (new_socket < 0) {
            perror("accept failed");
        }

        if (fork() == 0) {
            handler_connection(new_socket);
        }
    }

    return 0;
}

void handler_connection(int new_sock) {
    auto *msg = "ready to echo \n";
    write(new_sock, msg, strlen(msg));

    char *buffer = new char[500];
    while (read(new_sock, buffer, 500) > 0) {
        write(new_sock, buffer, strlen(buffer));
    }
}

