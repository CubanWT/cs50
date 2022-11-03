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

    // check if key is invalid
    for (int i = 0; i < strlen(key); i++)
    {
        // ensure only alphabetical input
        if (isalpha(key[i]) == 0)
        {
            printf("Invalid character in key! only alphabetical input allowed\n");
            return 1;
        }

        // keep temp_key chars in same case to compare them
        string temp_key = toupper(key);

        // cycle through chars in temp_key
        for (int n = 0; n < strlen(temp_key); n++)
        {
            // checks if parent loop char is the same as any char in temp_key
            if (temp_key[i] == temp_key[n])
            {
                printf("Error! No duplicate characters allowed in key!\n");
                return 1;
            }
        }

    }

    // get user input
    string input = get_string("plaintext: ");
    string output = input;

    // cycle through chars in input
    for (int i = 0; i < strlen(input); i++)
    {
        // identify lowercase
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            // convert using lowercase key
            output[i] = tolower(key[input[i] - 'a']);
        }
        // identify uppercase
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            // convert using uppercase key
            output[i] = toupper(key[input[i] - 'A']);
        }
        else
        {
            // preserve any !letters
            output[i] = input[i];
        }
    }

    printf("ciphertext: %s\n", output);
    return 0;
}