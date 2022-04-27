#include <ctype.h> // isalpha
#include <cs50.h> // get_string, string
#include <stdio.h> // printf
#include <string.h> // strlen

int main (void)
{
    string argv1 = "VCHPRZGJNTLSKFBDQWAXEUYMOI";

    char c0 = 'a';

    char c1;

    // verificar si es mayuscula, minuscula, o caracter no alfabetico

    if(isalpha(c0))
    {
        if(islower(c0))
        {
            int position = c0 - 97;

            c1 = argv1[position];
        }
        else
        {
            int position = c0 - 65;

            c1 = argv1[position];
        }
    }
    else
    {
        c1 = c0;
    }

    printf("%c\n", c1);
    return c1;
}