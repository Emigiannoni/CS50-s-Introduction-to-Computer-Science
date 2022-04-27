#include <ctype.h> // isalpha
#include <cs50.h> // get_string, string
#include <stdio.h> // printf
#include <string.h> // strlen

int main(int argc, string argv[])
{

    int result = 1;
    int lenght = 0;

    //First, verify if user provide correct number of Command Line Arguments.
    if (argc == 2)
    {
        lenght = strlen(argv[1]);

        //Second, verify if introduced text contain 26 characters.
        if (lenght == 26)
        {
            //Third, verify if introduced text contain any character that is not an alphabetic character.
            for (int i = 0; i < lenght; i++)
            {
                if (isalpha(argv[1][i]))
                {
                    //do nothing, continue analizing for loop
                }
                else // if one or more characters are not alphabetical
                {
                    result = 0;
                }
            }
            if (result == 1) //Fourth, verify if introduced text contain any duplicated character.
            {
                int counter1 = 0;
                int counter2 = 0;

                for (int i = 0; i < lenght; i++)
                {
                    char c1 = toupper(argv[1][i]);

                    for (int j = 0; j < lenght; j++ )
                    {
                        if (c1 == argv[1][j])
                        {
                            counter1 += 1;
                        }
                    }

                    char c2 = tolower(argv[1][i]);

                    for (int k = 0; k < lenght; k++ )
                    {
                        if (c2 == argv[1][k])
                        {
                            counter2 += 1;
                        }
                    }

                }

                if (counter1 > 1 || counter2 > 1) // if there are duplicated characters in the key
                {
                    result = 0;
                    printf("Usage: ./substitution key\n");
                }
            }
        }
        else // if lenght != 26
        {
            printf("Key must contain 26 characters.\n");
            result = 0;
        }
    }
    else // if argc != 2
    {
       printf("Usage: ./substitution key\n");
       result = 0;
    }

    printf("%i\n", result);
    return result;
}
