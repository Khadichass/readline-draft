#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() 
{   
   
    char* str = calloc(10, sizeof(char));
    char arr[10];

    // if (fd == NULL) 
    // {
    //     printf("File is empty\n");
    // }
    
    int fd = open("./example.txt", O_RDONLY);
    char string_arr;
    read(fd, &string_arr, 1);
    printf("%c\n", string_arr);
    close(fd);   

    
    FILE* file_p;
    
    file_p = fopen("./example.txt", "r");
    fread(str, sizeof(char), 10, file_p);
    printf("%s\n", str);
    fclose(file_p);


}
