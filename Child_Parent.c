#include <stdio.h>
#include <sys/types.h>
#define MAX_COUNT 200
void child()
{
    // for (int i = 0; i < MAX_COUNT; i++)
    //     printf("Child Running with value : %d\n", i);
    printf("%d %d- pid\n", getpid(), getppid());
}
void parent()
{
    // for (int i = 0; i < MAX_COUNT; i++)
    //     printf("Parent Running with value : %d\n", i);
    printf("%d %d- pid\n", getpid(), getppid());
}
int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
        child();
    else
        parent();
    return 0;
}