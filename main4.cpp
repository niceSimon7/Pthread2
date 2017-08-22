#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thread_fun(void *arg)
{
    static int num = 123;
    printf("after 2 seconds, thread will return\n");
    sleep(2);

    return (void*)&num;
}

int main(int argc, char* argv[])
{
    pthread_t tid;
    int ret =0;
    void* value = NULL;

    ret = pthread_create(&tid, NULL, thread_fun, NULL);
    if(ret!=0)
    {
        perror("pthread_create");
    }

    pthread_join(tid, &value);
    printf("value=%d\n", *((int*)value));

    return 0;
}
