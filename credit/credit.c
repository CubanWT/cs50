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

        loopCount++;

        int digit1 = input % 100^loopCount;
        digit1 = (digit1 - (digit1 % 10^(loopCount * 2 - 1))) / 10^(loopCount * 2 - 1);

        evenTotal += digit1 * 2;

    } while (!stepComplete);


    //Check if mastercard, visa, AMEX,
    //else: output invalid
}