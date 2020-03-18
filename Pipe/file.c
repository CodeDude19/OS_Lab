#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *file;
    char c;
    file = fopen("file.txt", "r");
    if (file == NULL)
        exit(1);
    else
    {
        while (1)
        {
            c = fgetc(file);
            if (c == EOF)
                break;
            else
                printf("%c", c);
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}