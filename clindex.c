#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    //Getting initial input for text from the user
    //Calculating how many letters and then words in the given string
    string text = get_string("Text: ");
    int letter_amount = count_letters(text);
    int word_amount = count_words(text);
    int sentence_amount = count_sentences(text);

    //Implement the Coleman-Liau index
    //index = 0.0588 * L - 0.296 * S - 15.8
    float L = (letter_amount / (float) word_amount) * 100;
    float S = (sentence_amount / (float) word_amount) * 100;
    float clindex = (0.0588 * L) - (0.296 * S) - 15.8;
    int clindex_final = (int) round(clindex);

    //Print grades
    if (clindex_final < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (clindex_final >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", clindex_final);
    }
}


int count_letters(string text)
{
    //Determine string length
    //Iterate through the string as if it were an array
    //Determine if each character is a letter or 'other'

    int length1 = strlen(text);
    int total = 0;

    for (int i = 0; i < length1; i++)
    {
        if isalpha(text[i])
        {
            total++;
        }

    }

    return total;
}

int count_words(string text)
{
    //Make sure to account for lack of space after the last word
    int length2 = strlen(text);
    int total_words = 1;
    for (int j = 0; j < length2; j++)
    {
        if isspace(text[j])
        {
            total_words++;
        }
    }

    return total_words;
}

int count_sentences(string text)
{
    int length3 = strlen(text);
    int total_sentences = 0;
    for (int k = 0; k < length3; k++)
    {
        if (text[k] == '.' || text[k] == '!' || text[k] == '?')
        {
            total_sentences++;
        }
    }

    return total_sentences;
}
