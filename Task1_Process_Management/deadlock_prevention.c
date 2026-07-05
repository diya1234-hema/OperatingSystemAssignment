#include <stdio.h>
#include <pthread.h>

pthread_mutex_t resource1;
pthread_mutex_t resource2;

void* worker(void* arg)
{
    int id = *(int*)arg;

    printf("Thread %d waiting for Resource 1\n", id);

    pthread_mutex_lock(&resource1);

    printf("Thread %d acquired Resource 1\n", id);

    printf("Thread %d waiting for Resource 2\n", id);

    pthread_mutex_lock(&resource2);

    printf("Thread %d acquired Resource 2\n", id);

    printf("Thread %d is working...\n", id);

    pthread_mutex_unlock(&resource2);
    pthread_mutex_unlock(&resource1);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    int id1 = 1;
    int id2 = 2;

    pthread_mutex_init(&resource1, NULL);
    pthread_mutex_init(&resource2, NULL);

    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&resource1);
    pthread_mutex_destroy(&resource2);

    printf("Deadlock prevention demonstrated successfully.\n");

    return 0;
}

