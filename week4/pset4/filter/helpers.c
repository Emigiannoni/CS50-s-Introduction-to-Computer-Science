#include "helpers.h"

// Convert image to grayscale

#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float blue = nearbyintf(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3);

            float green = nearbyintf((float)(image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3);

            float red = nearbyintf(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3);

            image[i][j].rgbtBlue = (int)blue;

            image[i][j].rgbtGreen = (int)green;

            image[i][j].rgbtRed = (int)red;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float red = round(0.393 * (float)image[i][j].rgbtRed + 0.769 * (float)image[i][j].rgbtGreen + 0.189 * (float)image[i][j].rgbtBlue);

            float green = round(0.349 * (float)image[i][j].rgbtRed + 0.686 * (float)image[i][j].rgbtGreen + 0.168 *
                                (float)image[i][j].rgbtBlue);

            float blue = round(0.272 * (float)image[i][j].rgbtRed + 0.534 * (float)image[i][j].rgbtGreen + 0.131 * (float)image[i][j].rgbtBlue);

            if (blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = (int)blue;
            }

            if (green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = (int)green;
            }

            if (red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = (int)red;
            }

        }
    }

    return;
}

// Reflect image horizontally

#include <stdlib.h>
#include <stdio.h>

void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE imagebuffer = image[i][j];

            int rightpixel = width - (j + 1);

            image[i][j] = image[i][rightpixel];

            image[i][rightpixel] = imagebuffer;
        }

    }

    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE imagebuffer[height][width];

    //blur center

    for (int i = 1; i < (height - 1); i++)
    {

        for (int j = 1; j < (width - 1); j++)
        {

            int total_red = 0;

            for (int k = (i - 1); k < (i + 2); k++)
            {
                for (int l = (j - 1); l < (j + 2); l++)
                {
                    total_red += image[k][l].rgbtRed;
                }
            }

            float average_red = round((float)total_red / 9);

            imagebuffer[i][j].rgbtRed = (int)average_red;


            int total_blue = 0;

            for (int k = (i - 1); k < (i + 2); k++)
            {
                for (int l = (j - 1); l < (j + 2); l++)
                {
                    total_blue += image[k][l].rgbtBlue;
                }
            }

            float average_blue = round((float)total_blue / 9);

            imagebuffer[i][j].rgbtBlue = (int)average_blue;


            int total_green = 0;

            for (int k = (i - 1); k < (i + 2); k++)
            {
                for (int l = (j - 1); l < (j + 2); l++)
                {
                    total_green += image[k][l].rgbtGreen;
                }
            }

            float average_green = round((float)total_green / 9);

            imagebuffer[i][j].rgbtGreen = (int)average_green;

        }
    }

    //blur left

    for (int i = 1; i < (height - 1); i ++)
    {
        int total_red = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = 0; l < 2; l++)
            {
                total_red += image[k][l].rgbtRed;
            }
        }

        float average_red = round((float)total_red / 6);

        imagebuffer[i][0].rgbtRed = (int)average_red;



        int total_blue = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = 0; l < 2; l++)
            {
                total_blue += image[k][l].rgbtBlue;
            }
        }

        float average_blue = round((float)total_blue / 6);

        imagebuffer[i][0].rgbtBlue = (int)average_blue;



        int total_green = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = 0; l < 2; l++)
            {
                total_green += image[k][l].rgbtGreen;
            }
        }

        float average_green = round((float)total_green / 6);

        imagebuffer[i][0].rgbtGreen = (int)average_green;

    }

    //blur right

    for (int i = 1; i < (height - 1); i ++)
    {
        int total_red = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = width; l > (width - 2); l--)
            {
                total_red += image[k][l].rgbtRed;
            }
        }

        float average_red = round((float)total_red / 6);

        imagebuffer[i][width].rgbtRed = (int)average_red;



        int total_blue = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = width; l > (width - 2); l--)
            {
                total_blue += image[k][l].rgbtBlue;
            }
        }

        float average_blue = round((float)total_blue / 6);

        imagebuffer[i][width].rgbtBlue = (int)average_blue;



        int total_green = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = width; l > (width - 2); l--)
            {
                total_green += image[k][l].rgbtGreen;
            }
        }

        float average_green = round((float)total_green / 6);

        imagebuffer[i][width].rgbtGreen = (int)average_green;

    }

    //blur upper

    for (int i = 1; i < (width - 1); i ++)
    {

        int total_red = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = 0; l < 2; l++)
            {
                total_red += image[l][k].rgbtRed;
            }
        }

        float average_red = round((float)total_red / 6);

        imagebuffer[0][i].rgbtRed = (int)average_red;



        int total_blue = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = 0; l < 2; l++)
            {
                total_blue += image[l][k].rgbtBlue;
            }
        }

        float average_blue = round((float)total_blue / 6);

        imagebuffer[0][i].rgbtBlue = (int)average_blue;



        int total_green = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = 0; l < 2; l++)
            {
                total_green += image[l][k].rgbtGreen;
            }
        }

        float average_green = round((float)total_green / 6);

        imagebuffer[0][i].rgbtGreen = (int)average_green;

    }

    //blur bottom

    for (int i = 1; i < (width - 1); i ++)
    {

        int total_red = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = height; l > (height - 2); l--)
            {
                total_red += image[l][k].rgbtRed;
            }
        }

        float average_red = round((float)total_red / 6);

        imagebuffer[height][i].rgbtRed = (int)average_red;



        int total_blue = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = height; l > (height - 2); l--)
            {
                total_blue += image[l][k].rgbtBlue;
            }
        }

        float average_blue = round((float)total_blue / 6);

        imagebuffer[height][i].rgbtBlue = (int)average_blue;



        int total_green = 0;

        for (int k = (i - 1); k < (i + 2); k++)
        {
            for (int l = height; l > (height - 2); l--)
            {
                total_green += image[l][k].rgbtGreen;
            }
        }

        float average_green = round((float)total_green / 6);

        imagebuffer[height][i].rgbtGreen = (int)average_green;

    }

    // corner1

    int total_red = 0;
    float average_red;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            total_red += image[i][j].rgbtRed;
        }
    }

    average_red = round((float)total_red / 4);

    imagebuffer[0][0].rgbtRed = (int)average_red;


    int total_green = 0;
    float average_green;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            total_green += image[i][j].rgbtGreen;
        }
    }

    average_green = round((float)total_green / 4);

    imagebuffer[0][0].rgbtGreen = (int)average_green;


    int total_blue = 0;
    float average_blue;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            total_blue += image[i][j].rgbtBlue;
        }
    }

    average_blue = round((float)total_blue / 4);

    imagebuffer[0][0].rgbtBlue = (int)average_blue;



    // corner2

    total_red = 0;
    total_green = 0;
    total_blue = 0;

    for (int i = height; i > (height - 2); i--)
    {
        for (int j = 0; j < - 2; j++)
        {
            total_red += image[i][j].rgbtRed;
        }
    }

    average_red = round((float)total_red / 4);

    imagebuffer[height][0].rgbtRed = (int)average_red;



    for (int i = height; i > (height - 2); i--)
    {
        for (int j = 0; j < - 2; j++)
        {
            total_green += image[i][j].rgbtGreen;
        }
    }

    average_green = round((float)total_green / 4);

    imagebuffer[height][0].rgbtGreen = (int)average_green;



    for (int i = height; i > (height - 2); i--)
    {
        for (int j = 0; j < - 2; j++)
        {
            total_blue += image[i][j].rgbtBlue;
        }
    }

    average_blue = round((float)total_blue / 4);

    imagebuffer[height][0].rgbtBlue = (int)average_blue;



    // corner3

    total_red = 0;
    total_green = 0;
    total_blue = 0;

    for (int i = height; i > (height - 2); i--)
    {
        for (int j = width; j > (width - 2); j--)
        {
            total_red += image[i][j].rgbtRed;
        }
    }

    average_red = round((float)total_red / 4);

    imagebuffer[height][width].rgbtRed = (int)average_red;



    for (int i = height; i > (height - 2); i--)
    {
        for (int j = width; j > (width - 2); j--)
        {
            total_green += image[i][j].rgbtGreen;
        }
    }

    average_green = round((float)total_green / 4);

    imagebuffer[height][width].rgbtGreen = (int)average_green;



    for (int i = height; i > (height - 2); i--)
    {
        for (int j = width; j > (width - 2); j--)
        {
            total_blue += image[i][j].rgbtBlue;
        }
    }

    average_blue = round((float)total_blue / 4);

    imagebuffer[height][width].rgbtBlue = (int)average_blue;



    // corner4

    total_red = 0;
    total_green = 0;
    total_blue = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = width; j > (width - 2); j--)
        {
            total_red += image[i][j].rgbtRed;
        }
    }

    average_red = round((float)total_red / 4);

    imagebuffer[0][width].rgbtRed = (int)average_red;



    for (int i = 0; i < 2; i++)
    {
        for (int j = width; j > (width - 2); j--)
        {
            total_green += image[i][j].rgbtGreen;
        }
    }

    average_green = round((float)total_green / 4);

    imagebuffer[0][width].rgbtGreen = (int)average_green;



    for (int i = 0; i < 2; i++)
    {
        for (int j = width; j > (width - 2); j--)
        {
            total_blue += image[i][j].rgbtBlue;
        }
    }

    average_blue = round((float)total_blue / 4);

    imagebuffer[0][width].rgbtBlue = (int)average_blue;



    //insert calculated values into main array

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = imagebuffer[i][j].rgbtGreen;
            image[i][j].rgbtGreen = imagebuffer[i][j].rgbtGreen;
            image[i][j].rgbtBlue = imagebuffer[i][j].rgbtBlue;
        }
    }

    return;
}
