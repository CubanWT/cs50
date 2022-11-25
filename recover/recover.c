#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 1)
    {
        printf("Too many arguments. use ./recover {file}\n");
        return 1;
    }

    FILE *input = fopen(argv[0], "r");
    if (input == NULL)
    {
        printf("File cannot be opened.\n");
        return 2;
    }
}