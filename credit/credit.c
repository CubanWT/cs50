#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long input = get_long("Enter Credit Card Number: ");


    //Check if input checksum is valid

    int evenTotal;
    bool stepComplete = false;
    int loopCount = 0;

   do
    {

        digitPosition += 2;

        int digit1 = input % 10^loopCount;
        digit1 = (digit1 - (digit1 % 10^(loopCount - 1))) / 10^(loopCount - 1);

        evenTotal += digit1 * 2;

        if(input % 100^loopCount)

    } while (!stepComplete);


    //Check if mastercard, visa, AMEX,
    //else: output invalid
}