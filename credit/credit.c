#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long input = get_long("Enter Credit Card Number: ");


    //Check if input checksum is valid

    int evenTotal;
    bool checkComplete = false;
    int loopCount = 0;

   do
    {

        loopCount++;
        int digit1 = input % 100^loopCount;
        digit1 = (digit1 - (digit1 % 10)) / 10;

    } while (!checkComplete);




    printf("%i\n", digit1);






        //Check if mastercard, visa, AMEX,
    //else: output invalid
}