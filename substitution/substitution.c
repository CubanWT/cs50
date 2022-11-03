#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // ensure key is the right length and exists,
    // also limit args to one
    if (!argv[1] || argv[2])
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Error! key is not 26 characters long!\n");
        return 1;
    }

    string key = argv[1];

    // get user input
    string input = get_string("plaintext: ");

    // convert key to uppercase
    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = toupper(key[i]);
    }

    //


}