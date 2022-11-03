#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Error! key is not 26 characters long!\n");
        return -1;
    }

    string input = get_string("plaintext: ");

}