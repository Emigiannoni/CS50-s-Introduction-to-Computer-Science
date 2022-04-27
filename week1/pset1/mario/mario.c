#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt user for imput

    int Height;

    do
    {
        Height = get_int("Please, enter the number of bricks (between 1 and 8): \n");
    }
    while (Height < 1 || Height > 8);

    //Building the pyramid

    for (int i = 1; i <= Height; i++)
    {
        //Prints left blank space
        for (int j = i; j < Height; j++)
        {
            printf(" ");
        }

        //Prints left blocks
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        //Prints gap
        printf("  ");

        //Prints right blocks
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        //Move prompt to the next line
        printf("\n");
    }
}
