#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex, wrt;
int readcount = 0;
void *write(void *arg)
{

    sem_wait(&wrt);
    printf("Writing!\n");
    sem_post(&wrt);
}
void *read(void *arg)
{

    sem_wait(&mutex);
    readcount++;
    if (readcount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);
    printf("Reading!\n");
    sem_wait(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);
    sem_post(&mutex);
}
int main()
{
    pthread_t r, w;
    pthread_create(&r, NULL, read, NULL);
    pthread_create(&w, NULL, write, NULL);
    pthread_join(r, NULL);
    pthread_join(w, NULL);
    return 0;
}