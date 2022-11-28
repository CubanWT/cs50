#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //ensure proper usage
    if(argc != 2)
    {
        printf("Improper usage. use ./recover {file}\n");
        return 1;
    }

    //read input file and check if file can't be opened
    FILE *file = fopen(argv[1], "r");

    //check if file could be opened
    if (file == NULL)
    {
        printf("File cannot be opened.\n");
        return 2;
    }

    //create buffer
    int blockSize = 512;
    int *buffer = malloc(blockSize);

    //store file name and jpeg count
    char *filename = malloc(8 * sizeof(char));
    int count = 0;

    //look through blocks
    while(fread(buffer, 1, blockSize, file) == blockSize)
    {
        count++;
        sprintf(filename, "%03i.jpg", count);

        
    }

    fclose(file);
    free(buffer);
    free(filename);
}