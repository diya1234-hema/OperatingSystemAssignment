#include <stdio.h>
#include <pthread.h>

void* worker(void* arg)
{
    printf("Worker thread is running.\n");
    return NULL;
}

int main()
{
    pthread_t thread1;

    printf("Creating thread...\n");

    pthread_create(&thread1, NULL, worker, NULL);

    pthread_join(thread1, NULL);

    printf("Thread execution completed.\n");

    return 0;
}
