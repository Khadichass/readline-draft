#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char* str)
{
    int i = 0;
    while (str[i++]);

    return --i;
}

char* str_cat(char* main_str, char* str)
{
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

char* str_cpy(char* dest, char* source)
{
    int len = my_strlen(source);
   
    for (int i = 0; i <= len; i++)
    {
        dest[i] = source[i];
    }
    
    return dest;
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


int main(void)
{
    // char arr1[20] = "Hello, ";
    // char* arr2 = "World!";
    // str_cat(arr1, arr2);
    // printf("%s\n", arr1);
    // strcat(arr1, arr2);
    // printf("%s\n", arr1);

    // char* arr3 = calloc(10, sizeof(char));
    // str_cpy(arr3, "hi");
    // printf("%s\n", arr3);


    char* str = malloc(sizeof(char) * 2);

    str = my_realloc(str, 10);
    str_cpy(str, "hellokjefnbr");

    printf("%s\n", str);

}