#include <cs50.h>
#include <string.h>
#include <stdio.h>


int count_letters(string text);
int count_words(string text);

char punctuation[] = {',', '.', '!', '?'};

int main(void)
{
    string input = get_string("Text: ");

    printf("%i letters\n", count_letters(input));
    printf("%i words\n", count_words(input));
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

int count_words(string text)
{
    int words = 0;

    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
        for (int n = 0; n < 4; n++)
        {
            if (text[i] == punctuation[n])
            {
                words += 1;
            }
        }
    }

    return words;
}