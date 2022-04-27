#include <ctype.h> // isalpha
#include <cs50.h> // get_string, string
#include <stdio.h> // printf
#include <string.h> // strlen

int key_validation(int argc, string argv);

char encipher(char c0, string argv1);

int main(int argc, string argv[])
{

    string plaintext;

    //if introduced key is correct, prompt user for word imput to cifer. Else, finish the program.

    if (key_validation(argc, argv[1]) == 1)
    {
        plaintext = get_string("plaintext: ");
    }
    else
    {
        return 1;
    }


    //Ciphering given plain text

    int lenght = strlen(plaintext);

    char ciphertext[lenght];

    ciphertext[lenght] = '\0';

    for (int i = 0; i < lenght; i++)
    {
        char c = encipher(plaintext[i], argv[1]);

        ciphertext[i] = c;
    }


    //print cipher text

    printf("ciphertext: %s\n", ciphertext);

}


// *** Encipher Function: *** //

char encipher(char c0, string argv1)
{
    char c1;

    // verificar si es mayuscula, minuscula, o caracter no alfabetico

    if (isalpha(c0))
    {
        if (islower(c0))
        {
            int position = c0 - 97;

            c1 = tolower(argv1[position]);
        }
        else
        {
            int position = c0 - 65;

            c1 = toupper(argv1[position]);
        }
    }
    else
    {
        c1 = c0;
    }

    return c1;
}


// *** Key validation Function: *** //

int key_validation(int argc, string argv1)
{

    int result = 1;
    int lenght = 0;

    //First, verify if user provide correct number of Command Line Arguments.
    if (argc == 2)
    {
        lenght = strlen(argv1);

        //Second, verify if introduced text contain 26 characters.
        if (lenght == 26)
        {
            //Third, verify if introduced text contain any character that is not an alphabetic character.
            for (int i = 0; i < lenght; i++)
            {
                if (isalpha(argv1[i]))
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
                    char c1 = toupper(argv1[i]);

                    for (int j = 0; j < lenght; j++)
                    {
                        if (c1 == argv1[j])
                        {
                            counter1 += 1;
                        }
                    }

                    char c2 = tolower(argv1[i]);

                    for (int k = 0; k < lenght; k++)
                    {
                        if (c2 == argv1[k])
                        {
                            counter2 += 1;
                        }
                    }
                }

                if (counter1 > 26 || counter2 > 26) // if there are duplicated characters in the key
                {
                    result = 0;
                    printf("Usage: ./substitution key\n");
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
    }
    return result;
}
