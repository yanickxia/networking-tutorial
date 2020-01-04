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


int main(int argc, char *argv[]) {
    printf("echo server sample...\n");

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
    int new_socket = accept(server_fd, (struct sockaddr *) &client, (socklen_t *) &c);

    if (new_socket < 0) {
        perror("accept failed");
    }

    auto *msg = "ready to echo \n";
    write(new_socket, msg, strlen(msg));

    char* buffer = new char[500];
    while (read(new_socket, buffer, 500 ) > 0){
        write(new_socket, buffer, strlen(buffer));
    }
    return 0;
}

