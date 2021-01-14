// Aryan Chaurasia
// CS50 2021 Pset 4 filter less
// 13 Jan 2021
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // calculates average
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int averageValue = round(((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0));
            image[i][j].rgbtRed = averageValue;
            image[i][j].rgbtGreen = averageValue;
            image[i][j].rgbtBlue = averageValue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // calculates sepia according to the formular
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            // if value is greater than 255
            // then the value is set to 255 which is the max
            if (sepiaRed >= 255)
            {
                sepiaRed = 255;

            }
            if (sepiaGreen >= 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue >= 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        BYTE rgbtBlue;
        BYTE rgbtGreen;
        BYTE rgbtRed;
    }
    temp;
    temp tempimage[height][width];
    // uses tempimages to shift and reflect pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            tempimage[i][j].rgbtRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = tempimage[i][j].rgbtRed;

            tempimage[i][j].rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = tempimage[i][j].rgbtBlue;

            tempimage[i][j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = tempimage[i][j].rgbtGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        BYTE rgbtBlue;
        BYTE rgbtGreen;
        BYTE rgbtRed;
    }
    temp;
    temp tempimage[height][width];
    // copies image in tempimage so can calculate blur effect without modifying original RGB values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempimage[i][j].rgbtRed = image[i][j].rgbtRed;
            tempimage[i][j].rgbtBlue = image[i][j].rgbtBlue;
            tempimage[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // if the colour is in first line and left corner
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round(((tempimage[i][j].rgbtRed + tempimage[i][j + 1].rgbtRed + tempimage[i + 1][j].rgbtRed +
                                              tempimage[i + 1][j + 1].rgbtRed) / 4.0));
                image[i][j].rgbtGreen = round(((tempimage[i][j].rgbtGreen + tempimage[i][j + 1].rgbtGreen + tempimage[i + 1][j].rgbtGreen +
                                                tempimage[i + 1][j + 1].rgbtGreen) / 4.0));
                image[i][j].rgbtBlue = round(((tempimage[i][j].rgbtBlue + tempimage[i][j + 1].rgbtBlue + tempimage[i + 1][j].rgbtBlue +
                                               tempimage[i + 1][j + 1].rgbtBlue) / 4.0));
            }
            // if the pixel is in first line but on right corner
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round(((tempimage[i][j].rgbtRed + tempimage[i][j - 1].rgbtRed + tempimage[i + 1][j].rgbtRed +
                                              tempimage[i + 1][j - 1].rgbtRed) / 4.0));
                image[i][j].rgbtGreen = round(((tempimage[i][j].rgbtGreen + tempimage[i][j - 1].rgbtGreen + tempimage[i + 1][j].rgbtGreen +
                                                tempimage[i + 1][j - 1].rgbtGreen) / 4.0));
                image[i][j].rgbtBlue = round(((tempimage[i][j].rgbtBlue + tempimage[i][j - 1].rgbtBlue + tempimage[i + 1][j].rgbtBlue +
                                               tempimage[i + 1][j - 1].rgbtBlue) / 4.0));
            }
            // if the pixel is in last line and left corner
            else if (j == 0 && i == height - 1)
            {
                image[i][j].rgbtRed = round(((tempimage[i][j].rgbtRed + tempimage[i][j + 1].rgbtRed + tempimage[i - 1][j].rgbtRed +
                                              tempimage[i - 1][j + 1].rgbtRed) / 4.0));
                image[i][j].rgbtGreen = round(((tempimage[i][j].rgbtGreen + tempimage[i][j + 1].rgbtGreen + tempimage[i - 1][j].rgbtGreen +
                                                tempimage[i - 1][j + 1].rgbtGreen) / 4.0));
                image[i][j].rgbtBlue = round(((tempimage[i][j].rgbtBlue + tempimage[i][j + 1].rgbtBlue + tempimage[i - 1][j].rgbtBlue +
                                               tempimage[i - 1][j + 1].rgbtBlue) / 4.0));
            }
            // if the pixel is in last line and Right corner
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round(((tempimage[i][j].rgbtRed + tempimage[i][j - 1].rgbtRed + tempimage[i - 1][j].rgbtRed +
                                              tempimage[i - 1][j - 1].rgbtRed) / 4.0));
                image[i][j].rgbtGreen = round(((tempimage[i][j].rgbtGreen + tempimage[i][j - 1].rgbtGreen + tempimage[i - 1][j].rgbtGreen +
                                                tempimage[i - 1][j - 1].rgbtGreen) / 4.0));
                image[i][j].rgbtBlue = round(((tempimage[i][j].rgbtBlue + tempimage[i][j - 1].rgbtBlue + tempimage[i - 1][j].rgbtBlue +
                                               tempimage[i - 1][j - 1].rgbtBlue) / 4.0));
            }
            // if the pixel is in first line (this is for calculating blur in edge)
            else if (i == 0)
            {
                image[i][j].rgbtRed = round(((tempimage[i][j].rgbtRed + tempimage[i][j - 1].rgbtRed + tempimage[i][j + 1].rgbtRed + tempimage[i +
                                              1][j].rgbtRed +
                                              tempimage[i + 1][j - 1].rgbtRed  + tempimage[i + 1][j + 1].rgbtRed) / 6.0));
                image[i][j].rgbtGreen = round(((tempimage[i][j].rgbtGreen + tempimage[i][j - 1].rgbtGreen + tempimage[i][j + 1].rgbtGreen +
                                                tempimage[i + 1][j].rgbtGreen +
                                                tempimage[i + 1][j - 1].rgbtGreen  + tempimage[i + 1][j + 1].rgbtGreen) / 6.0));
                image[i][j].rgbtBlue = round(((tempimage[i][j].rgbtBlue + tempimage[i][j - 1].rgbtBlue + tempimage[i][j + 1].rgbtBlue + tempimage[i
                                               +
                                               1][j].rgbtBlue +
                                               tempimage[i + 1][j - 1].rgbtBlue  + tempimage[i + 1][j + 1].rgbtBlue) / 6.0));
            }
            // if the pixel is in last line (this is for calculating blur in edge)
            else if (i == height - 1)
            {
                image[i][j].rgbtRed = round(((tempimage[i][j].rgbtRed + tempimage[i][j - 1].rgbtRed + tempimage[i][j + 1].rgbtRed + tempimage[i -
                                              1][j].rgbtRed +
                                              tempimage[i - 1][j - 1].rgbtRed  + tempimage[i - 1][j + 1].rgbtRed) / 6.0));
                image[i][j].rgbtGreen = round(((tempimage[i][j].rgbtGreen + tempimage[i][j - 1].rgbtGreen + tempimage[i][j + 1].rgbtGreen +
                                                tempimage[i -
                                                        1][j].rgbtGreen +
                                                tempimage[i - 1][j - 1].rgbtGreen  + tempimage[i - 1][j + 1].rgbtGreen) / 6.0));
                image[i][j].rgbtBlue = round(((tempimage[i][j].rgbtBlue + tempimage[i][j - 1].rgbtBlue + tempimage[i][j + 1].rgbtBlue + tempimage[i
                                               -
                                               1][j].rgbtBlue +
                                               tempimage[i - 1][j - 1].rgbtBlue  + tempimage[i - 1][j + 1].rgbtBlue) / 6.0));
            }
            // If the pixel is in the left side and on edge
            else if (j == 0)
            {
                image[i][j].rgbtRed = round(((tempimage[i][j].rgbtRed + tempimage[i - 1][j].rgbtRed + tempimage[i + 1][j].rgbtRed + tempimage[i][j +
                                              1].rgbtRed +
                                              tempimage[i - 1][j + 1].rgbtRed  + tempimage[i + 1][j + 1].rgbtRed) / 6.0));
                image[i][j].rgbtGreen = round(((tempimage[i][j].rgbtGreen + tempimage[i - 1][j].rgbtGreen + tempimage[i + 1][j].rgbtGreen +
                                                tempimage[i][j + 1].rgbtGreen +
                                                tempimage[i - 1][j + 1].rgbtGreen  + tempimage[i + 1][j + 1].rgbtGreen) / 6.0));
                image[i][j].rgbtBlue = round(((tempimage[i][j].rgbtBlue + tempimage[i - 1][j].rgbtBlue + tempimage[i + 1][j].rgbtBlue +
                                               tempimage[i][j + 1].rgbtBlue +
                                               tempimage[i - 1][j + 1].rgbtBlue  + tempimage[i + 1][j + 1].rgbtBlue) / 6.0));
            }
            // if the pixel is on the right side and on the edge
            else if (j == width - 1)
            {
                image[i][j].rgbtRed = round(((tempimage[i][j].rgbtRed + tempimage[i - 1][j].rgbtRed + tempimage[i + 1][j].rgbtRed + tempimage[i][j -
                                              1].rgbtRed +
                                              tempimage[i - 1][j - 1].rgbtRed  + tempimage[i + 1][j - 1].rgbtRed) / 6.0));
                image[i][j].rgbtGreen = round(((tempimage[i][j].rgbtGreen + tempimage[i - 1][j].rgbtGreen + tempimage[i + 1][j].rgbtGreen +
                                                tempimage[i][j - 1].rgbtGreen +
                                                tempimage[i - 1][j - 1].rgbtGreen  + tempimage[i + 1][j - 1].rgbtGreen) / 6.0));
                image[i][j].rgbtBlue = round(((tempimage[i][j].rgbtBlue + tempimage[i - 1][j].rgbtBlue + tempimage[i + 1][j].rgbtBlue +
                                               tempimage[i][j - 1].rgbtBlue +
                                               tempimage[i - 1][j - 1].rgbtBlue  + tempimage[i + 1][j - 1].rgbtBlue) / 6.0));
            }
            // otherwise take all 9 side average to calculate blur
            else
            {
                image[i][j].rgbtRed = round(((tempimage[i][j].rgbtRed + tempimage[i][j - 1].rgbtRed + tempimage[i][j + 1].rgbtRed + tempimage[i -
                                              1][j].rgbtRed +
                                              tempimage[i - 1][j - 1].rgbtRed  + tempimage[i - 1][j + 1].rgbtRed + tempimage[i + 1][j].rgbtRed
                                              + tempimage[i + 1][j + 1].rgbtRed + tempimage[i + 1][j - 1].rgbtRed) / 9.0));
                image[i][j].rgbtGreen = round(((tempimage[i][j].rgbtGreen + tempimage[i][j - 1].rgbtGreen + tempimage[i][j + 1].rgbtGreen +
                                                tempimage[i - 1][j].rgbtGreen +
                                                tempimage[i - 1][j - 1].rgbtGreen  + tempimage[i - 1][j + 1].rgbtGreen + tempimage[i + 1][j].rgbtGreen
                                                + tempimage[i + 1][j + 1].rgbtGreen + tempimage[i + 1][j - 1].rgbtGreen) / 9.0));
                image[i][j].rgbtBlue = round(((tempimage[i][j].rgbtBlue + tempimage[i][j - 1].rgbtBlue + tempimage[i][j + 1].rgbtBlue +
                                               tempimage[i - 1][j].rgbtBlue +
                                               tempimage[i - 1][j - 1].rgbtBlue  + tempimage[i - 1][j + 1].rgbtBlue + tempimage[i + 1][j].rgbtBlue
                                               + tempimage[i + 1][j + 1].rgbtBlue + tempimage[i + 1][j - 1].rgbtBlue) / 9.0));
            }
        }
    }
    return;
}
// Comments
// comments
// comments