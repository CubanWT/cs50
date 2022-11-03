#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

char punctuation[] = {',', '.', '!', '?'};

int main(void)
{
    string input = get_string("Text: ");

    float L = count_letters(input) / count_words(input) * 100;
    float S = count_sentences(input) / count_words(input) * 100;

    int grade_level = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade_level < 1)
    {
        printf("Before Grade 1");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }

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
    int words = 1;

    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }

    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        for (int n = 0; n < 4; n++)
        {
            if (text[i] == punctuation[n])
            {
                sentences += 1;
            }
        }
    }

    return sentences;
}