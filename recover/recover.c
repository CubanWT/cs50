#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //ensure proper usage
    if(argc != 1)
    {
        printf("Too many arguments. use ./recover {file}\n");
        return 1;
    }

    //read input file and check if file can't be opened
    FILE *input = fopen(argv[0], "r");
    if (input == NULL)
    {
        printf("File cannot be opened.\n");
        return 2;
    }

    int

    //loop through file
    while ( != EOF)
    {

    }
}