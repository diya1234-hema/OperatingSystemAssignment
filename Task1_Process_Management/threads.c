#include <stdio.h>
#include <pthread.h>

void* task1(void* arg)
{
    for(int i = 1; i <= 5; i++)
    {
        printf("Thread 1: Processing task %d\n", i);
    }
    return NULL;
}

void* task2(void* arg)
{
    for(int i = 1; i <= 5; i++)
    {
        printf("Thread 2: Processing task %d\n", i);
    }
    return NULL;
}

void* task3(void* arg)
{
    for(int i = 1; i <= 5; i++)
    {
        printf("Thread 3: Processing task %d\n", i);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;

    printf("Creating 3 threads...\n");

    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    pthread_create(&t3, NULL, task3, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("All threads completed.\n");

    return 0;
}
