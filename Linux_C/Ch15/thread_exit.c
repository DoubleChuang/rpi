#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * tfn1(void * arg)
{
    printf("the first\n");
    return (void *) 1;
}

void * tfn2(void * arg)
{
    printf("the second\n");
    pthread_exit((void *) 3);
    printf("should not be here\n");
}

void * tfn3(void * arg)
{
    printf("the third\n");
    return NULL;
}

int main()
{
    pthread_t tid1, tid2, tid3;
    void * res;
    int err;
//thread 1
    err = pthread_create(&tid1, NULL, tfn1, NULL);
    if(err != 0)
    {
        printf("can't create thread %s\n", strerror(err));
    }

    err = pthread_join(tid1, &res);
    if(err != 0)
    {
        printf("can't join thread %s\n", strerror(err));
        exit(1);
    }

    printf("result from thd1: %d\n",(unsigned int)res);
//thread 2
    err = pthread_create(&tid2, NULL, tfn2, NULL);
    if(err != 0)
    {
        printf("can't create thread %s\n", strerror(err));
    }

    err = pthread_join(tid2, &res);
    if(err != 0)
    {
        printf("can't join thread %s\n", strerror(err));
        exit(1);
    }

    printf("result from thd2: %d\n",(unsigned int)res);
//thread 3
    err = pthread_create(&tid3, NULL, tfn3, NULL);
    if(err != 0)
    {
        printf("can't create thread %s\n", strerror(err));
    }

    err = pthread_join(tid3, NULL);
    if(err != 0)
    {
        printf("can't join thread %s\n", strerror(err));
        exit(1);
    }

    printf("the third thread has done\n");


}



