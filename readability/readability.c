#include <cs50.h>
#include <string.h>
#include <stdio.h>


int count_letters(string text);

int main(void)
{
    string input = get_string("Text: ");

    printf("%i letters\n", count_letters(input));

}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letters += 1;
        }
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letters += 1;
        }
    }

    return letters;
}