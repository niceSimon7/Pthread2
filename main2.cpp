#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thread_fun(void* arg)
{
    sleep(1);
    int num = *((int*)arg);
    printf("In the new thread: num = %d\n",num);

    return NULL;
}

int main(int argc, char* argv[])
{
    pthread_t tid;
    int sum = 100;

    pthread_create(&tid, NULL, thread_fun, (void*)&sum);

    while(1);

    return 0;
}
