#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int start_size;

    do
    {
        printf("Please, enter a number that is greater than or equal to 9\n");
        start_size = get_int("Starting population size: \n");
    }
    while (start_size < 9);

    // TODO: Prompt for end size

    int final_size;

    do
    {
        printf("Please, enter a number that is greater than or equal to the start size\n");
        final_size = get_int("Final population size: \n");
    }
    while (final_size < start_size);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;

    while (start_size < final_size)
    {
        int llamas_born = start_size / 3;

        int llamas_pass = start_size / 4;

        start_size = start_size + llamas_born - llamas_pass;

        years = years + 1;
    }

    // TODO: Print number of years

    printf("Years: %i\n", years);
}