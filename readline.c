#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define SUCCESS 1
#define FAILURE -1

int READLINE_READ_SIZE = 2;
char* STORAGE_OF_FILE;

int my_strlen(char* str)
{
    int i = 0;
    while (str[i++]);

    return --i;
}

int check_n(char* str)
{
    for (int i = 0; i < my_strlen(str); i++)
    {
        if (str[i] == '\n') return i;
    }

    return FAILURE;
}

char* strn_cpy(char* dest, char* source, int length)
{
    for (int i = 0; i < length; i++)
    {
        dest[i] = source[i];
    }
    return dest;
}

char *my_readline(int fd)
{
    if (STORAGE_OF_FILE == NULL)
    {
        STORAGE_OF_FILE = calloc(READLINE_READ_SIZE + 1, sizeof(char));
    }
    int index_of_storage = 0;
    int flag_n;

    while ((flag_n = check_n(STORAGE_OF_FILE)) != FAILURE)
    {
        int reader = read(fd,&STORAGE_OF_FILE[index_of_storage], READLINE_READ_SIZE);
        if (reader == 0)
        {
            return STORAGE_OF_FILE;
        }
        index_of_storage += reader;
    }

    char* ready_line = calloc(flag_n + 1, sizeof(char));
    strn_cpy(ready_line, STORAGE_OF_FILE, flag_n);

    return ready_line;
}

int main(int ac, char av)
{
    char *str = NULL;

    int fd = open("./example.txt", O_RDONLY);
    while ((str = my_readline(fd)) != NULL)
    {
        printf("%s\n", str);
        free(str);
    }
    close(fd);

    // if (STORAGE_OF_FILE == NULL)
    // {
    //     printf("%d\n", my_strlen("12345678910"));
    // }

    return 0;
}