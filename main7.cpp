#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thread_fun(void* arg)
{
    static int num = 123;
    int i =0;
    while(1)
    {
        printf("I am running\n");
        sleep(1);
        i++;
        if(i==3)
        {
            pthread_exit((void*)&num); //return &num
        }
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    int ret = 0;
    pthread_t tid;
    void* value = NULL;

    ret = pthread_create(&tid, NULL, thread_fun, NULL);
    if(ret!=0)
    {
        perror("pthread_create");
    }

    pthread_join(tid, &value);
    printf("value = %d\n",*(int*)value);

    return 0;
}
