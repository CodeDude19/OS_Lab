#include <stdio.h>
#include <sys/types.h>
void child()
{
    printf("Hello Fcker!\n");
}
int main()
{
    pid_t pid;
    pid = fork();
    printf("Pid = %d\n", pid);
    if (pid == 0)
        child();
    return 0;
}