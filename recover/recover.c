#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //ensure proper usage
    if(argc != 1)
    {
        printf("Too many arguments. use ./recover {file}\n");
        return 1;
    }

    //read input file and check if file can't be opened
    FILE *file = fopen(argv[0], "r");
    if (file == NULL)
    {
        printf("File cannot be opened.\n");
        return 2;
    }

    //variables
    int blockSize = 512;
    BYTE *image = malloc(blockSize);


    if (fread(image, blockSize, 1, file) == 0)
    {
        printf("Couldn't read file\n");
        return 2;
    }

    int counter = 0;
    bool blockFound = true;

    while( blockFound == true)
    {
        if (fread(image, blockSize, 1, file) == 0)
        {
            printf("Couldn't read file\n");
            return 2;
        }
        int currentChar = fgetc(image);


        sprintf("%i", currentChar);

        if (counter == 50)
        {
            blockFound == false;
        }
    }

    free(image);
}