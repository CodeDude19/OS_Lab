#include <stdio.h>
#include <pthread.h>
void *OddEven(int x)
{
    if (x == 0)
        printf("\neven: ", x);
    if (x == 1)
        printf("\nodd: ");
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == x)
            printf(" %d ", i);
    }
    return NULL;
}
int main()
{
    pthread_t tid1, tid2;
    const int a = 0, b = 1;
    pthread_create(&tid1, NULL, OddEven, 0);
    pthread_create(&tid2, NULL, OddEven, 1);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("\n");
    return 0;
}