#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define SUCCESS 1
#define FAILURE -1

int READLINE_READ_SIZE = 1;
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

char* str_cpy(char* dest, char* source)
{
    for (int i = 0; source[i] != '\0'; i++)
    {
       dest[i] = source[i];
    }
    
    return dest;
}

void fill_with_nl(char* str, int size)
{
    for (int i = 0; i < size; i++)
    {
        str[i] = '\0';
    }
}

char* str_cat(char* main_str, char* str)
{
    // to continue printing next lines
    int len_main = my_strlen(main_str);
    int len_str = my_strlen(str);

    int index = len_main;

    for (int i = 0; i < len_main ; i++)
    {
        main_str[index] = str[i];
        index++;
    }
    
    return main_str;
}

char* my_realloc(char* str, int size)
{
    char* new_str = malloc(size);

    if (size <= 0) {
        return NULL;
    }

    if(new_str == NULL)
    {
        return NULL;
    }

    if (str != NULL)
    {
        str_cpy(new_str, str);
        free(str);
    }
    return new_str;    
}

int file_size(char* str)
{
    int fd = open(str, O_RDONLY);
    char letter;
    int counter = 0;
    while (read(fd, &letter, 1))
    {
        counter++;
    }

    return counter;
}

void init_my_readline()
{
    if (STORAGE_OF_FILE)
        free(STORAGE_OF_FILE);

    // int counter = file_size()
    STORAGE_OF_FILE = malloc((READLINE_READ_SIZE + 1) * sizeof(char));
    fill_with_nl(STORAGE_OF_FILE, READLINE_READ_SIZE + 1);
}

char *my_readline(int fd)
{
    if (fd == -1)
        return NULL;

    int index = 0;
    if (my_strlen(STORAGE_OF_FILE) == 0)
    {
        while (read(fd, &STORAGE_OF_FILE[index], READLINE_READ_SIZE))
        {
            index += READLINE_READ_SIZE;
            int allocate_size = READLINE_READ_SIZE + index + 1;
            STORAGE_OF_FILE =(char*) realloc(STORAGE_OF_FILE, allocate_size);
            // fill_with_nl(STORAGE_OF_FILE, (READLINE_READ_SIZE + index + 1));
        }
    }
    char* ret_value;
    int n_index = check_n(STORAGE_OF_FILE);
    if (n_index == FAILURE)
    {
        int length = my_strlen(STORAGE_OF_FILE);
        if (my_strlen(STORAGE_OF_FILE) == 0)
        {
            return NULL;
        }
        ret_value = malloc((my_strlen(STORAGE_OF_FILE) + 1) * sizeof(char));
        fill_with_nl(ret_value, (my_strlen(STORAGE_OF_FILE) + 1));
        ret_value = strn_cpy(ret_value, STORAGE_OF_FILE, my_strlen(STORAGE_OF_FILE));
        STORAGE_OF_FILE += length;
        return ret_value;
    }
    else
    {
        ret_value = malloc((n_index + 2) * sizeof(char));
        fill_with_nl(ret_value, (n_index + 2));
        ret_value = strn_cpy(ret_value, STORAGE_OF_FILE, n_index);
        STORAGE_OF_FILE += n_index + 1;
        return ret_value;
    }
}

int main(int ac, char** av)
{
    char *str = NULL;

    init_my_readline();
    int fd = open(av[1], O_RDONLY);
    while ((str = my_readline(fd)) != NULL)
    {
        // sleep(1);
        printf("%s\n", str);
        free(str);
    }
    close(fd);

    return 0;
}