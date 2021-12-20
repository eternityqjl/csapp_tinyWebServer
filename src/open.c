#include "inc/csapp.h"
#include <semaphore.h>

//gcc -O2 -pthread -o open open.c csapp.c
int main() {
    int fd1;
    fd1 = Open("1.txt", O_RDONLY, 0);
    printf("result: %d", fd1);
    Close(fd1);

    return 0;
}