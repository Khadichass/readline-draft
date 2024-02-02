#include <stdio.h>


int main() {
    FILE *filePointer;
    int character;

    int a = 97;
    char b = 'a';

    if (a == b)
    {
        printf("true\n");
    }
    else
    {
       printf("false\n");
    }
    
    filePointer = fopen("example.txt", "r");

    if (filePointer == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((character = fgetc(filePointer)) != EOF) {
        putchar(character);
    }

    fclose(filePointer);

    return 0;
}
