#include <stdio.h>
#include <stdlib.h>

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

    blockSize = 512 * sizeof(BYTE);

    char *buffer = malloc(7 * sizeof(char))
    {
        
    }
}