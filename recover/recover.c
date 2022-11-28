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
        return 1;
    }

    //create buffer
    int blockSize = 512;
    BYTE *buffer = malloc(blockSize);

    //store file name and jpeg count
    char *filename = malloc(8 * sizeof(char));
    int count = 0;

    //look through blocks
    while(fread(buffer, 1, blockSize, file) == blockSize)
    {
        //check if block has jpeg headers
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            buffer[3] >= 0xe0 &&
            buffer[3] <= 0xf0)
        {
            if (count == 0)
            {
                //format and save filename
                sprintf(filename, "%03i.jpg", count);
                count++;

                //create image file
                FILE *image = fopen(filename, "w");

                //write jpg in buffer to file
                fwrite(buffer, 1, blockSize, image);
            }
            else
            {
                //close previous image
                fclose(image);

                //format and save filename
                sprintf(filename, "%03i.jpg", count);
                count++;

                //create image file
                FILE *image = fopen(filename, "w");

                //write jpg in buffer to file
                fwrite(buffer, 1, blockSize, image);
            }
        }
        else
        {
            //check if currently writing to jpg
            if (image != NULL)
            {
                //keep writing to file
                fwrite(buffer, 1, blockSize, image);
            }
        }
    }

    fclose(file);
    free(filename);
    free(buffer);
}