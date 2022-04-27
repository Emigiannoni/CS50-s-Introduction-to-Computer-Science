#include <stdio.h>
#include <cs50.h>

int main (void)
{
    // Variable's declaration

    long c_c_number;
    int  checksum = 0;
    bool validation;

    // Promp for imput

   // do
   // {
   //     c_c_number = get_long("Enter Credit Card Number: ");
   // }
   //  while(c_c_number<0);

    c_c_number = 4003600000000014;

    // Calculate the checksum

    int     individual_number_wo_decimals;
    float   individual_number;
    int     number_to_sum, num;

    individual_number = (float) c_c_number / 10;
    individual_number_wo_decimals = c_c_number / 10;
    num = ((individual_number - individual_number_wo_decimals) * 10);
    num = num * 2;

    for (int i = 0; i <= 16; i++)
    {
        if (i==1 || i==3 || i==5 || i==7 || i==9 || i==11 || i==13 || i==15)
        {
            individual_number = individual_number / 10;
            individual_number_wo_decimals = individual_number_wo_decimals / 10;
            num = ((individual_number - individual_number_wo_decimals) * 10);
            num = num * 2;
            checksum = checksum + num;
        }
        else
        {
            individual_number = individual_number / 10;
            individual_number_wo_decimals = individual_number_wo_decimals / 10;
            num = ((individual_number - individual_number_wo_decimals) * 10);
            checksum = checksum + num;
        }
    }

    if (checksum == 10 || checksum == 20 || checksum == 30 || checksum == 40 || checksum == 50 || checksum == 60 || checksum == 70 || checksum == 80 || checksum == 90)
    {
        validation = true;
    }
    else
    {
        validation = false;
    }

    if (validation)
    {
       printf("Ok");
    }
    else
    {
        printf("NO Ok");
    }
}

