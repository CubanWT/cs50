#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    // ensure key is the right length
    if (strlen(key) == 0)
    {
        printf("Usage: ./substitution key\n");
        return 
    }

    else if (strlen(key) != 26)
    {
        printf("Error! key is not 26 characters long!\n");
        return -1;
    }

    // convert key to uppercase
    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = toupper(key[i]);
    }

    string input = get_string("plaintext: ");


}