#include <stdio.h>
#include <cs50.h>

int main (void)
{

    //Prompt user for imput

    int Height;

    do
    {
        Height = get_int("Please, enter the number of bricks (between 1 and 8): \n");
    }
    while (Height < 1 || Height > 8);

    for(int i = 1; i <= Height; i++)
    {
        for(int j = i; j < Height; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}