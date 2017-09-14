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
    int server_signal = 0;

    key = 9876;

    if((shmid = shmget(key, SHSIZE, 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }
    if((shm = (char *)shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }

    sscanf(shm, "%d", &server_signal);
    printf("%d\n",server_signal);
    *shm = '*';

    return 0;
}