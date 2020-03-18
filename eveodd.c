#include <stdio.h>
#include <pthread.h>

int count;

void *evenodd(int x)
{
    if (x == 0)
        printf("\neven: ", x);
    if (x == 1)
        printf("\nodd: ");
    for (count = 0; count < 10; count++)
    {
        if (count % 2 == x)
            printf(" %d ", count);
    }
    return NULL;
}

int main()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, evenodd, 0);
    pthread_create(&tid2, NULL, evenodd, 1);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("\n");
    return 0;
}