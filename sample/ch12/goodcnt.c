/*
 * p669
 *
 * 使用信号量来实现互斥
 *
 * 在类 UNIX 系统中编译和运行：
 *
 * unix> make goodcnt
 * unix> ./goodcnt
 */


#include "csapp.h"

void *thread(void *vargp);      /*Thread routine prototype*/

/*Global shared variable*/
volatile int cnt  = 0;          /*Counter*/
sem_t mutex;                    /*Semaphore that protect counter*/

int main(int argc, char **argv)
{
    int niters;
    pthread_t tid1, tid2;

    if (argc != 2)
    {
      printf("usage:%s <niters>\n", argv[0]);
      exit(0);
    }
    niters = atoi(argv[1]);
    Sem_init(&mutex, 0, 1);    /*mutext = 1*/

    Pthread_create(&tid1, NULL, thread, &niters);
    Pthread_create(&tid2, NULL, thread, &niters);
    Pthread_join(tid1, NULL);
    Pthread_join(tid2, NULL);

    if (cnt != (2 * niters))
    {
        printf("BOOM! cnt=%d\n", cnt);
    }
    else
    {
        printf("Ok cnt=%d\n", cnt);
    }

    exit(0);
}

void *thread(void *vargp)
{
    int i, niters = *((int *)vargp);
    for (i = 0; i < niters; i++)
    {
        P(&mutex);
        cnt++;
        V(&mutex);
    }

    return NULL;
}
