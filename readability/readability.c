#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{

    string text = get_string("text:");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    float L = (letters / words) * 100;//Here  L is the average number of letters per 100 words in the text means.
    float S = (sentences / words) * 100;//Here  S is the average number of sentences per 100 words in the text.

    float calculated_index = 0.0588 * L - 0.296 * S -
                             15.8;// This varibale to store calculeted valu using the formula "Coleman-Liau index".
    int index = round(
                    calculated_index); // This varibale round figer the value store in 'calculated_index' using the formula "Coleman-Liau index".

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {

        printf("Grade %i\n", index);//Here print the calculated Grade value that between 1 and 15.
    }
}
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]))
        {
            int count = text[i] + 1;
            letters += count - text[i];
        }

        if (isupper(text[i]))
        {
            int count = text[i] + 1;
            letters += count - text[i];
        }
    }

    return letters;// Here the function return how much letters in the 'text' varibale
}

int count_words(string text)
{
    int words = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {

            words++;
        }
    }

    return words;// Here the function return how much words in the 'text' varibale
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;// Here the function return how much sentences in the 'text' varibale
}