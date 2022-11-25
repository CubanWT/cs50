#include "helpers.h"
#include <math.h>

RGBTRIPLE rowAvg(int row, int column, int width, RGBTRIPLE *image[row + 1][column + 1]);

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
            RGBTRIPLE avgAbove, avgLine, avgBelow;
            copy[i][j] = image[i][j];

            if (i == 0)
            {
                avgAbove = NULL;
                avgLine = rowAvg(i, j, width, &copy);
                avgBelow = rowAvg(i + 1, j, width, &copy);
            }
            else if (i == height - 1)
            {
                avgAbove = rowAvg(i - 1, j, width, &copy);
                avgLine = rowAvg(i, j, width, &copy);
                avgBelow = NULL;
            }
            else
            {
                avgAbove = rowAvg(i + 1, j, width, &copy);
                avgLine = rowAvg(i, j, width, &copy);
                avgBelow = rowAvg(i + 1, j, width, &copy);
            }

            image[i][j].rgbtRed = round((avgAbove.rgbtRed + avgLine.rgbtRed + avgBelow.rgbtRed) / 3);
            image[i][j].rgbtBlue = round((avgAbove.rgbtBlue + avgLine.rgbtBlue + avgBelow.rgbtBlue) / 3);
            image[i][j].rgbtGreen = round((avgAbove.rgbtGreen + avgLine.rgbtGreen + avgBelow.rgbtGreen) / 3);

        }
    }
}

RGBTRIPLE rowAvg(int row, int column, int width, RGBTRIPLE *image[row + 1][column + 1])
{
    image = *image;
    RGBTRIPLE avg;

    //average current pixel and right pixel if on left edge
    if (column == 0)
    {
        avg.rgbtRed = round((image[row][column].rgbtRed + image[row][column + 1].rgbtRed) / 2);
        avg.rgbtGreen = round((image[row][column].rgbtGreen + image[row][column + 1].rgbtGreen) / 2);
        avg.rgbtBlue = round((image[row][column].rgbtBlue + image[row][column + 1].rgbtBlue) / 2);
    }
    //average current pixel and left pixel if on right edge
    else if (column == width - 1)
    {
        avg.rgbtRed = round((image[row][column].rgbtRed + image[row][column - 1].rgbtRed) / 2);
        avg.rgbtGreen = round((image[row][column].rgbtGreen + image[row][column - 1].rgbtGreen) / 2);
        avg.rgbtBlue = round((image[row][column].rgbtBlue + image[row][column - 1].rgbtBlue) / 2);
    }
    //average current pixel and two adjacent pixels
    else
    {
        avg.rgbtRed = round((image[row][column - 1].rgbtRed + image[row][column].rgbtRed + image[row][column + 1].rgbtRed) / 3);
        avg.rgbtGreen = round((image[row][column - 1].rgbtGreen + image[row][column].rgbtGreen + image[row][column + 1].rgbtGreen) / 3);
        avg.rgbtBlue = round((image[row][column - 1].rgbtBlue + image[row][column].rgbtBlue + image[row][column + 1].rgbtBlue) / 3);
    }

    return avg;
}