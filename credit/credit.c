#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{

    //Get card input
    long input = get_long("Enter Credit Card Number: ");


    //Check if input checksum is valid

    int evenTotal;
    bool stepComplete = false;
    int digitPosition = 0;

   do
    {

        digitPosition += 2;

        long digit = input % pow(10, digitPosition);
        digit = (digit - digit % pow(10, (digitPosition - 1))) / pow(10, (digitPosition - 1));

        printf("digitPosition: %i, ",digitPosition);
        printf("digit: %li\n", digit);
        stepComplete = true;

    } while (!stepComplete);


    //Check if mastercard, visa, AMEX,
    //else: output invalid
}