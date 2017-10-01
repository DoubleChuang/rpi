#include <stdio.h>
#include <arpa/inet.h>

int main()
{
    short a = htons(0x0102);
    short * p = &a;
    
    if( *((char *)p) == 0x01 )
        printf("big-endian\n");
    else if( *((char *)p) == 0x02 )
        printf("little-endian\n");
    else
        printf("unknown\n");

    return 0;
}