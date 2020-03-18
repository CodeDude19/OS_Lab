#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
sem_t chopstick[5];
void *philosopher(void *arg)
{
    int x = (*(int *)arg);
    while (1)
    {
        printf("\nPhil %d is Thinking....", x + 1);
        sleep(1);
        sem_wait(&chopstick[x]);
        printf("\nPhil %d is Hungry!", x + 1);
        sleep(1);
        printf("\nPhil %d is takes chop %d and %d", x + 1, x + 1, (((x + 1) % 5) + 1));
        sleep(1);
        sem_wait(&chopstick[(x + 1) % 5]);
        printf("\nPhil %d is eating with chop %d and %d", x + 1, x + 1, (((x + 1) % 5) + 1));
        sleep(1);
        sem_post(&chopstick[x]);
        sem_post(&chopstick[(x + 1) % 5]);
        printf("\nPhil %d puts chop %d and %d", x + 1, x + 1, (((x + 1) % 5) + 1));
        sleep(1);
    }
}
int main()
{
    pthread_t tid[5];
    for (int i = 0; i < 5; i++)
    {
        sem_init(&chopstick[i], 0, 1);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&tid[i], NULL, &philosopher, (void *)&i);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(tid[i], NULL);
    }
    return 0;
}