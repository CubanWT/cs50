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
        printf("Improper usage. use ./recover {file}\n");
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
    FILE *image = malloc(blockSize);


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

        if (counter < 10)
        {
            printf("00%i\n", counter);
        }
        else if (counter < 100)
        {
            printf("0%i\n", counter);
        }

        if (counter == 15)
        {
            blockFound = false;
        }
    }

    free(image);
}