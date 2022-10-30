#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long input = get_long("Enter Credit Card Number: ");


    //Check if input checksum is valid

    int evenTotal;
    bool checkComplete = false;

    for (int i = 1; !checkComplete; i++)
    {
        int digit1 = input % 100^i;
        digit1 = (digit1 - (digit1 % 10)) / 10;
    }




    printf("%i\n", digit1);






        //Check if mastercard, visa, AMEX,
    //else: output invalid
}