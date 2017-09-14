#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
void * thfn(void * arg)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();

    tid = pthread_self();

    printf("the new thread: pid is :%u,tid is :%lu\n", (unsigned int)pid, (unsigned long)tid);
    return NULL;
}

int main()
{
    pid_t pid;
    int err;
    pthread_t mtid,ntid;
    
    pid = getpid();
    mtid = pthread_self();
    err = pthread_create(&ntid, NULL, thfn, NULL);
    if(err != 0)
    {
        printf("can't create thread %s \n",strerror(err));
        exit(1);
    }

    sleep(1);
    printf("ther main thread: pid is: %u, tid is: %lu\n", (unsigned int)pid, (unsigned long)mtid);
    
    return 0;
}