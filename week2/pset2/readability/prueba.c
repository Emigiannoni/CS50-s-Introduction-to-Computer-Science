#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    int len = strlen(text);

    int s_counter = 0;

    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s_counter += 1;
        }
    }

    int l_counter = 0;

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            l_counter += 1;
        }
    }

    int w_counter = 1;

    for (int i = 0; i < len; i++)
    {
        if (isspace(text[i]))
        {
            w_counter += 1;
        }
    }


    printf("%i\n", l_counter);

    printf("%i\n", w_counter);

    printf("%i\n", s_counter);

    float L = ((float) l_counter / (float) w_counter) * 100.00;

    float S = ((float) s_counter / (float) w_counter) * 100.00;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    printf("%f\n", L);

    printf("%f\n", S);

    printf("%f\n", index);

}