#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string word = get_string("Player 1: ");

    int score = 0;

    int lenght = strlen(word);

    for (int i = 0; i < lenght; i++)
    {
        if (isupper(word[i]))
        {
            char c = tolower(word[i]);
            int position = (int) c - 97;
            score +=  POINTS[position];
        }
        else if (islower(word[i]))
        {
            char c = word[i];
            int position = (int) c - 97;
            score +=  POINTS[position];
        }
        else
        {
            score += 0;
        }

    printf("%i\n", score);

    }

    printf("%i\n", score);

}