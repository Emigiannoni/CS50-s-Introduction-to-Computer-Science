#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float quarter = 25, dime = 10, nickel = 5, penny = 1, change_d;
    int counter, change_c;

    // Promp for imput

    do
    {
        change_d = get_float("Change Owed: ");
    }
    while (change_d < 0);

    // Convert Dollar to Cents

    change_c = round(change_d * 100);

    // Computing coins

    counter = change_c / 25;

    change_c = change_c - (25 * counter);

    while (change_c > 0)
    {
        if (change_c >= dime)
        {
            change_c = change_c - dime;
            counter += 1;
        }

        else if (change_c >= nickel)
        {
            change_c = change_c - nickel;
            counter += 1;
        }

        else
        {
            change_c = change_c - penny;
            counter += 1;
        }
    }


    // Show results

    printf("%i\n", counter);

}