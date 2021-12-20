#include "inc/csapp.h"

int main(int argc, char **argv)
{
    int clientfd;
    char *host, *port, buf[MAXBUF];
    rio_t rio;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port> \n", argv[0]);
        exit(0);
    }
    host = argv[1];
    port = argv[2];

    //fd指的是文件描述符file descriptor
    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);

    //反复从标准输入读入文本，发送给服务器
    while (Fgets(buf, MAXLINE, stdin) != NULL) {
        Rio_writen(clientfd, buf, strlen(buf));
        rio_readlineb(&rio, buf, MAXLINE);
        Fputs(buf, stdout);
    }

    Close(clientfd);
    exit(0);
}