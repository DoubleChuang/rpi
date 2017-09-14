#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100

int main()
{
    int shmid;
    key_t key;
    char *shm;

    key = 9876;

    if((shmid = shmget(key, SHSIZE, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }
    if((shm = (char *)shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }
    sprintf(shm, "%d", getpid());
    
    while(*shm != '*')
        sleep(1);
    if(shmdt(shm) == -1)
    {
        perror("shmdt");
        exit(1);
    }
    /*刪除共用記憶體*/
    if(shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        exit(1);
    }
    printf("Shared Memory Bye\n");
    return 0;
}