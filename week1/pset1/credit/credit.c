#include <stdio.h>
#include <cs50.h>

int main (void)
{
    // Variable's declaration

    long c_c_number;
    int  checksum = 0;
    bool validation;

    // Promp for imput

    do
    {
        c_c_number = get_long("Enter Credit Card Number: ");
    }
    while(c_c_number<0);


    // Calculate the checksum

    int     individual_number_wo_decimals;
    float   individual_number;
    int     number_to_sum;
    
    individual_number = (float) c_c_number / 10;
    individual_number_wo_decimals = c_c_number / 10;
    num = ((individual_number - individual_number_wo_decimals) * 10);
    num = num * 2
    
    for (i=0, i<=16, i++)
    {
        case (i==1 || i==3 || i==5 || i==7 || i==9 || i==11 || i==13 || i==15)
        {
            individual_number = individual_number / 10;
            individual_number_wo_decimals = individual_number_wo_decimals / 10;
            num = ((individual_number - individual_number_wo_decimals) * 10);
            num = num * 2;
            checksum = checksum + num;
        }
        case (i==0 || i==2 || i==4 || i==6 || i==8 || i==10 || i==12 || i==14 || i==16)
        {
            individual_number = individual_number / 10;
            individual_number_wo_decimals = individual_number_wo_decimals / 10;
            num = ((individual_number - individual_number_wo_decimals) * 10);
            checksum = checksum + num;
        }
    }

    if (checksum = 10 || checksum = 20 || checksum = 30 || checksum = 40 || checksum = 50 || checksum = 60 || checksum = 70 || checksum = 80 || checksum = 90)
    {
        validation = TRUE;
    }
    else
    {
        validation = FALSE;
    }
    
    
    // Check for card lenght and starting digits



    // Print result (VISA, AMEX, MASTERCARD or INVALID)

    if (validation)
    {
        case printf("VISA");
        case printf("AMEX");
        case printf("MASTERCARD");
    }
    else
    {
        printf("INVALID");
    }
}
