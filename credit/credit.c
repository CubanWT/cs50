#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long input = get_long("Enter Credit Card Number: ");


    //Check if input checksum is valid

    int digit1 = input % 100;
    printf("%i", digit1);


        //Check if mastercard, visa, AMEX,
    //else: output invalid
}