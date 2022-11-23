#include "helpers.h"
#include <math.h>

RGBTRIPLE rowAvg(int i, int j, int height, int width, RGBTRIPLE image[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; i++)
        {
            RGBTRIPLE avgAbove, avgLine, avgBelow;

            //average of 3 pixels above
            if (i != 0)
            {
                avgAbove = rowAvg(i - 1, j, height, width, image[height][width]);
            }
            //average of 3 pixels in line
            avgAbove = rowAvg(i, j, height, width, image[height][width]);
            //average of 3 pixels below
            if (i != height - 1)
            {
                avgAbove = rowAvg(i + 1, j, height, width, image[height][width]);
            }
            //average of 3 averages
        }
    }
}

RGBTRIPLE rowAvg(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE avg;
    if (j == width - 1)
    {
        avg.rgbtRed = round((image[i][j - 1].rgbtRed + image[i - 1][j].rgbtRed) / 2);
        avg.rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen) / 2);
        avg.rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue) / 2);
    }
    else if (j != 0)
    {
        avg.rgbtRed = round((image[i][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 3);
        avg.rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 3);
        avg.rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 3);
    }
    else
    {
        avg.rgbtRed = round((image[i][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 2);
        avg.rgbtGreen = round((image[i][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 2);
        avg.rgbtBlue = round((image[i][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 2);
    }

    return avg;
}
