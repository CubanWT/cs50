#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long input = get_long("Enter Credit Card Number: ");


    //Check if input checksum is valid

    int evenTotal;
    bool stepComplete = false;
    int digitPosition = 0;

   do
    {

        digitPosition += 2;

        int digit1 = input % 10^digitPosition;
        digit1 = (digit1 - digit1 % 10^(digitPosition - 1)) / 10^(digitPosition - 1);

        printf("digitPosition: %i, ",digitPosition);
        printf("digit: %i\n", digit1);
        stepComplete = true;

    } while (!stepComplete);


    //Check if mastercard, visa, AMEX,
    //else: output invalid
}