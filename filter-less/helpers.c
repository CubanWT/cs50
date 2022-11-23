#include "helpers.h"
#include <math.h>

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
            
            image[i][j].rgbtRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            image[i][j].rgbtGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            image[i][j].rgbtBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (image[i][j].rgbtRed > 255)
                image[i][j].rgbtRed = 255;
            else if (image[i][j].rgbtRed < 0)
                image[i][j].rgbtRed = 0;
            if (image[i][j].rgbtGreen > 255)
                image[i][j].rgbtGreen = 255;
            else if (image[i][j].rgbtGreen < 0)
                image[i][j].rgbtGreen = 0;
            if (image[i][j].rgbtBlue > 255)
                image[i][j].rgbtBlue = 255;
            else if (image[i][j].rgbtBlue < 0)
                image[i][j].rgbtBlue = 0;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
