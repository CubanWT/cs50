#include <cs50.h>
#include <stdio.h>

int main(void)
{

    bool isInRange;

do {
    int height = get_int("Pyramid height: ");

    if(height > 0 && height < 9)
    {
        string bricks;
        for(int i = 1; i <= height; i++)
        {
            //print spaces
            spaces = height - i;
            //print hashes
            hashes = "#" * i;
            //print middle space
            //print hashes
        }
        //output
        printf("%s  %s", bricks)

        isInRange = true;
    }
    else
    {
        isInRange = false;
    }
} while(!isInRange);


}




