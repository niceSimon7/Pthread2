#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int key = 100; //global

void* hello1(void *arg)
{
    printf("The message is %s\n", (char*)arg);
    key = 10; //change global value
    printf("key = %d, the child id is %lu\n", key, pthread_self());

    return NULL;
}

void* hello2(void *arg)
{
    printf("The message is %s\n",(char*)arg);
    sleep(1);
    printf("key = %d, the child id is %lu\n", key, pthread_self());

    return NULL;
}

int main(int argc, char* argv[])
{
    pthread_t tid1;
    pthread_t tid2;

    char* msg1 = "hello1";
    char* msg2 = "hello2";

    pthread_create(&tid1, NULL, hello1, msg1);
    pthread_create(&tid2, NULL, hello2, msg2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
