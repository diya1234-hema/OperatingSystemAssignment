#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 100000

int counter = 0;

/* Mutex lock */
pthread_mutex_t lock;

void* incrementCounter(void* arg)
{
    for(int i = 0; i < ITERATIONS; i++)
    {
        pthread_mutex_lock(&lock);

        counter++;

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, incrementCounter, NULL);
    pthread_create(&t2, NULL, incrementCounter, NULL);
    pthread_create(&t3, NULL, incrementCounter, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Final Counter Value = %d\n", counter);

    pthread_mutex_destroy(&lock);

    return 0;
}
