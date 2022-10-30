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
        for(int i = 0; i <= height; i++)
        {
            bricks
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