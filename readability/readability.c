#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

//array to hold chars used to determine when a sentence ends
char punctuation[] = {'.', '!', '?'};

int main(void)
{
    //get input from user
    string input = get_string("Text: ");

    //calculate Coleman-Liau Index
    float L = (float) count_letters(input) / count_words(input) * 100;
    float S = (float) count_sentences(input) / count_words(input) * 100;

    int grade_level = round(0.0588 * L - 0.296 * S - 15.8);

    //check for grade level limits
    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }

}

int count_letters(string text)
{
    int letters = 0;

    //cycle through chars in text
    for (int i = 0; i < strlen(text); i++)
    {
        //add letter if uppercase
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letters += 1;
        }
        //add letter if lowercase
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letters += 1;
        }
    }

    return letters;
}

int count_words(string text)
{
    //initialize words int as 1 because there is always
    //one more word than space in a sentence
    int words = 1;

    //cycle through chars in text
    for (int i = 0; i <= strlen(text); i++)
    {
        //add word if selected char is a space
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

    //cycle through chars in text
    for (int i = 0; i < strlen(text); i++)
    {
        //cycle through chars in punctuation[] to determine
        //if a sentence has ended
        for (int n = 0; n < 3; n++)
        {
            if (text[i] == punctuation[n])
            {
                sentences += 1;
            }
        }
    }

    return sentences;
}