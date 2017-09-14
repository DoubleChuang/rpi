#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void timer_handler(int signo)
{
    if(signo == SIGALRM)
    {
        printf("the time is now\n");
        exit(0);
    }
    else 
        printf("unexpected signal");       
}

int main(){
    if(signal(SIGALRM, timer_handler) == SIG_ERR)
    {
        perror("Can't set handler for SIGALRM\n");
        exit(0);
    }
    alarm(1);

    while(1)
        printf("Too early\n");
    printf("Should not be here, never\n");
    return 0;
}