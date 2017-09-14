#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(){
    printf("kill myself\n");
    raise(SIGKILL);
    printf("should not be here, never\n");
    return 0;
}