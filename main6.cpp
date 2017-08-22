#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thread_fun(void* arg)
{
    int i;
    for(i=0; i<5; i++)
    {
        printf("I am running\n");
        sleep(1);
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    int ret =0;
    pthread_t tid;

    ret = pthread_create(&tid, NULL, thread_fun, NULL);
    if(ret!=0)
    {
        perror("pthread_create");
    }

    pthread_detach(tid); //thread detach

    int flag = pthread_join(tid, NULL);
    if(flag!=0)
    {
        printf("join not working\n");
    }

    printf("after join\n");
    sleep(4);
    printf("I am leaving\n");

    return 0;
}
