#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int file_pipes[2], data_pro;
    const char data[] = "Hello World";
    char buffer[20];
    pipe(file_pipes);
    if (fork() == 0)
    {
        printf("Child!\n");
        data_pro = write(file_pipes[1], data, strlen(data));
        printf("Wrote %d bytes.\n", data_pro);
    }
    else
    {
        printf("Parent!\n");
        data_pro = read(file_pipes[0], buffer, 20);
        printf("Read %d bytes : %s\n", data_pro, buffer);
    }
    return 0;
}