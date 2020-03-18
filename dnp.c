#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
sem_t cs[5];
void *phil(void *arg)
{
    int i = *(int *)arg;
    do
    {
        sem_wait(&cs[i]);
        sem_wait(&cs[(i + 1) % 5]);
        printf("Fork %d and %d is picked up!\n", i, (i + 1));
        printf("Philosopher %d is eating!\n", i + 1);
        printf("Fork %d and %d is dropped!\n", i, i + 1);
        sleep(1);
        sem_post(&cs[i]);
        sem_post(&cs[(i + 1) % 5]);
        printf("Philosopher %d is thinking!\n", i + 1);
        sleep(1);
    } while (1);
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        sem_init(&cs[i], 0, 1);
    }
    pthread_t tid[5];
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&tid[i], NULL, phil, (void *)&i);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(tid[i], NULL);
    }
    return 0;
}