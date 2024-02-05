#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char* str)
{
    int i = 0;
    while (str[i++]);

    return --i;
}

char* str_cat(char* temp, char* str)
{
    int lent_temp = my_strlen(temp);
    int len_str = my_strlen(str);
    int full_length = lent_temp + len_str + 1;

    char* full_str = calloc(full_length, sizeof(char));

    int index = 0;
    for (; index < lent_temp; index++)
    {
        full_str[index] = temp[index];
    }

    for (int i = 0; i < len_str; i++)
    {
        full_str[index] = str[i];
        index++;   
    }
    
    return full_str;
}

int main(void)
{
   char* arr1 = calloc(20, sizeof(char));
   strcpy(arr1, "Hello, ");

   char* arr2 = calloc(10, sizeof(char));
   strcpy(arr2, "World!");

    str_cat(arr1, arr2);

    printf("%s\n", arr1);
}