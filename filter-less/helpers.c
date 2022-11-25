#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
                sepiaRed = 255;
            else if (sepiaRed < 0)
                sepiaRed = 0;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            else if (sepiaGreen < 0)
                sepiaGreen = 0;
            if (sepiaBlue > 255)
                sepiaBlue = 255;
            else if (sepiaBlue < 0)
                sepiaBlue = 0;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }


}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (int) floor(width / 2); j++)
        {
            RGBTRIPLE temp;
            temp.rgbtRed = image[i][j].rgbtRed;
            temp.rgbtGreen = image[i][j].rgbtGreen;
            temp.rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = temp.rgbtRed;
            image[i][width - j - 1].rgbtGreen = temp.rgbtGreen;
            image[i][width - j - 1].rgbtBlue = temp.rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    //average of row above
    //average of current row
    //average of row below
}

float rowAvg(RGBTRIPLE row[2], int onEdge)
{
    RGBTRIPLE avg;
    if (onEdge == 0)
    {
        avg.rgbtRed = (row[0].rgbtRed + row[1].rgbtRed + row[2].rgbtRed) / 3;
        avg.rgbtBlue = (row[0].rgbtBlue + row[1].rgbtBlue + row[2].rgbtBlue) / 3;
        avg.rgbtGreen = (row[0].rgbtGreen + row[1].rgbtGreen + row[2].rgbtGreen) / 3;
    }
    else
    {
        avg.rgbtRed = (row[0].rgbtRed + row[1].rgbtRed) / 2;
        avg.rgbtBlue = (row[0].rgbtBlue + row[1].rgbtBlue) / 2;
        avg.rgbtGreen = (row[0].rgbtGreen + row[1].rgbtGreen) / 2;
    }
    return;
}