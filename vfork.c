#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int arr[] = {4, 3, 1, 2, 6, 5, 7, 10, 9};
void child()
{
    printf("Child is sorting the array now!\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorting done!\n");
    return;
}
void parent()
{
    printf("Enter a number to search :\n");
    int s;
    scanf("%d", &s);
    for (int i = 0; i < 8; i++)
    {
        if (s == arr[i])
        {
            printf("Found at Location %d!\n", i + 1);
            return;
        }
    }
    printf("Not Found!\n");
}
int main()
{
    pid_t pid;
    pid = vfork();
    if (pid == 0)
    {
        child();
    }
    else
    {
        parent();
        exit(0);
    }
    return 0;
}