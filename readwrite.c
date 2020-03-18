#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int readCount = 0;
sem_t mutex, wrtblock;

void *write(void *arg)
{
    int x = *(int *)arg;
    sem_wait(&wrtblock);
    printf("\n%d Writing... done", x);
    sem_post(&wrtblock);
}

void *read(void *arg)
{
    int x = *(int *)arg;
    sem_wait(&mutex);
    readCount++;
    if (readCount == 1)
        sem_wait(&wrtblock);
    sem_post(&mutex);
    printf("\n%d Reading... done", x);
    sem_wait(&mutex);
    if (readCount == 1)
        sem_post(&wrtblock);
    readCount--;
    sem_post(&mutex);
}

int main()
{
    pthread_t w[3], r[3];
    sem_init(&mutex, 0, 1);
    sem_init(&wrtblock, 0, 1);
    for (int i = 0; i < 100; i++)
    {
        pthread_create(&r[i], NULL, read, (void *)&i);
        pthread_create(&w[i], NULL, write, (void *)&i);
    }
    for (int i = 0; i < 100; i++)
    {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }
    printf("\n");
    return 0;
}
