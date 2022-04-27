#include <ctype.h> // isalpha, isspace
#include <cs50.h> // get_string, string
#include <stdio.h> // printf
#include <string.h> // strlen
#include <math.h> // round

// declaration of auxiliar functions to be used in this program:

int count_letters(string text, int len);
int count_words(string text, int len);
int count_sentences(string text, int len);

int main(void)
{
    //prompt user for imput

    string text = get_string("Text: ");

    int len = strlen(text);

    //count the number of letters, words and sentences

    //count the number of letters

    int l_counter = count_letters(text, len);

    //count the number of words

    int w_counter = count_words(text, len);

    //any occurrence of a period, exclamation point, or question mark indicates the end of a sentence

    int s_counter = count_sentences(text, len);

    //calculate the average number of letters per 100 words

    float L = ((float) l_counter / (float) w_counter) * 100.00;

    //calculate the average number of sentences per 100 words

    float S = ((float) s_counter / (float) w_counter) * 100.00;

    //calculate the Coleman-Liau index

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    //print the result

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        int round_index =  round(index);
        printf("Grade %i\n", round_index);
    }

}

// *** auxiliar functions: ***

//counts any lowercase character from a to z or any uppercase character from A to Z
int count_letters(string text, int len)
{
    int l_counter = 0;

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            l_counter += 1;
        }
    }

    return l_counter;

}


//counts any sequence of characters separated by spaces as a word
int count_words(string text, int len)
{
    int w_counter = 1;

    for (int i = 0; i < len; i++)
    {
        if (isspace(text[i]))
        {
            w_counter += 1;
        }
    }

    return w_counter;
}


//counts any occurrence of a period, exclamation point, or question mark as a indicator of the end of a sentence
int count_sentences(string text, int len)
{
    int s_counter = 0;

    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s_counter += 1;
        }
    }

    return s_counter;
}