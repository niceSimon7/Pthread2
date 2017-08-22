#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int var=8; //global

void* thread_01(void *arg)
{
    while(1)
    {
        printf("this is thread_01: var++\n");
        var++;
        sleep(1);
    }
    return NULL;
}

void* thread_02(void *arg)
{
    while(1)
    {
        printf("this is thread_02: var = %d\n",var);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    pthread_t tid1,tid2;

    //Create two thread
    pthread_create(&tid1, NULL, thread_01, NULL);
    pthread_create(&tid2, NULL, thread_02, NULL);

    while(1)
    {
        printf("the main thread: var=%d\n",var);
        sleep(1);
    }
    return 0;

}
