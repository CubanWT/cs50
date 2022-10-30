#include <cs50.h>
#include <stdio.h>

int main(void)
{

    bool isInRange;

do {
    int height = get_int("Pyramid height: ");

    if(height > 0 && height < 9)
    {
        for(int row = 1; row <= height; row++)
        {
            //print spaces
            int spaces = height - row;
            for(int i = spaces; i > 0; i--) {
                printf(" ");
            }

            //print hashes
            for(int i = row; i > 0; i--) {
                printf("#");
            }

            //print middle space
            printf("  ");

            //print hashes
            for(int i = row; i > 0; i--) {
                printf("#");
            }
            printf("\n");
        }

        isInRange = true;
    }
    else
    {
        isInRange = false;
    }
} while(!isInRange);


}




