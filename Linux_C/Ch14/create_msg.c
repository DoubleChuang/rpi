#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qid;
    key_t key;
    
    key = 113;
    //建立一個訊息佇列
    if((qid = msgget(key, IPC_CREAT | 0666)) < 0)
    {
        perror("msgget");
        exit(1);
    }
    printf("created queue id : %d \n",qid);

    system("ipcs -q");
    return 0;

}