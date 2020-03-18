#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <random>
#include <unistd.h>

using namespace std;

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;

sem_t full, empt;
pthread_mutex_t mut;

void *produce(void *arg)
{
	while (1)
	{
		sleep(1);
		sem_wait(&empt);
		pthread_mutex_lock(&mut);
		int item = rand() % 100;
		buffer[in++] = item;
		cout << "Produced " << item << endl;
		pthread_mutex_unlock(&mut);
		sem_post(&full);
	}
}

void *consume(void *arg)
{
	while (1)
	{
		sleep(1);
		sem_wait(&full);
		pthread_mutex_lock(&mut);
		int item = buffer[--in];
		cout << "Consumed " << item << endl;
		pthread_mutex_unlock(&mut);
		sem_post(&empt);
	}
}

int main()
{
	pthread_t producer, consumer;
	sem_init(&empt, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);
	pthread_mutex_init(&mut, NULL);
	pthread_create(&producer, NULL, produce, NULL);
	pthread_create(&consumer, NULL, consume, NULL);
	pthread_exit(NULL);
}