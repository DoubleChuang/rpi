#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
typedef struct arg_struct{
    int * heap;
    int * stack;
    FILE *fp;
}ARG;


void * thfn(void * arg)
{
    ARG *p = (ARG *)arg;
    (*p->heap)++; // ->和 ++ 優先度一樣所以要括號出來 在*
    (*p->stack)++;
    
    fprintf(p->fp, "new thread heap:%d stack %d \n", *p->heap, *p->stack);

    printf("the new thread done\n");
    return NULL;
}

int main(void)
{
    pthread_t tid, tid2;
    ARG arg;
    int * heap;
    int stack;
    int err;
    if((heap = (int *)malloc(1 * sizeof(int))) == NULL)
    {
        perror("fail to malloc");
        exit(1);
    }

    *heap = 2;
    stack = 3;
    arg.fp = NULL;
    arg.heap = heap;
    arg.stack = &stack;

    if((arg.fp=fopen("test.txt","wb")) == NULL){
        perror("fail to open");
        exit(1);
    }

    err = pthread_create(&tid, NULL, thfn, (void *)&arg);
    if(err != 0){
        printf("can't create thread %s\n",strerror(err));
        exit(1);
    }
    pthread_join(tid, NULL);
    (*heap)++;
    stack++;

    fprintf(arg.fp, "main thread:heap:%d stack %d\n",*(arg.heap), *(arg.stack));
    printf("the main thread done\n");
    fclose(arg.fp);
    free(heap);
    return 0;
}
