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
    char *filename[8];
    int count = 0;

    //create file for image

    if (fread(image, blockSize, 1, file) == 0)
    {
        printf("Couldn't read file\n");
        return 2;
    }

    int counter = 0;
    bool blockFound = true;

    while( blockFound == true)
    {

    }

    free(image);
}