/*
 *
 *unix->cc -Wall -I../../common hello.c ../../common/csapp.c -lpthread -o hello
 *unix-> ./hello
 */

#include "csapp.h"

void *thread(void *argvp);

int main()
{
    pthread_t tid;
    Pthread_create(&tid, NULL, thread, NULL);
    Pthread_join(tid, NULL);
    exit(0);
}

void *thread(void *argvp)
{
     printf("hello world\n");
     return NULL;
}
