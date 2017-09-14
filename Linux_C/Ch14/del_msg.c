#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int qid;

    if(argc != 2)
    {
        puts("USAGE:del_msgq.c <queue ID>");
        exit(1);
    }
    qid = atoi(argv[1]);
    
    system("ipcs -q");
    //printf("qid:%d\n",qid);
    if((msgctl(qid, IPC_RMID, NULL)) < 0)
    {
        perror("msgctl");
        exit(1);
    }
    system("ipcs -q");
    printf("successfully remove %d queue\n", qid);

    exit(0);
}