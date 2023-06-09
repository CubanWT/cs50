#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


//creating new RGBTRIPLE struct for accurate values in blur (check50 was marking it incorrect over difference of 1)
typedef struct
{
    float rgbtRed;
    float rgbtGreen;
    float rgbtBlue;
} RGBFLOAT;

RGBFLOAT rowAvg(RGBTRIPLE row[2], bool onEdge);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
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
            {
                sepiaRed = 255;
            }
            else if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            else if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            else if (sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }

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

    //make copy of image for accurate blur values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    //iterate through pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            bool onEdge;
            RGBTRIPLE *row;
            RGBFLOAT avgAbove, avgLine, avgBelow;

            //check if edge case, then allocate memory for current row of pixel values needed to blur and initialize values
            if (j == 0)
            {
                onEdge = true;
                row = malloc(2 * sizeof(RGBTRIPLE));
                row[0] = copy[i][j];
                row[1] = copy[i][j + 1];
            }
            else if (j == width - 1)
            {
                onEdge = true;
                row = malloc(2 * sizeof(RGBTRIPLE));
                row[0] = copy[i][j - 1];
                row[1] = copy[i][j];
            }
            else
            {
                onEdge = false;
                row = malloc(3 * sizeof(RGBTRIPLE));
                row[0] = copy[i][j - 1];
                row[1] = copy[i][j];
                row[2] = copy[i][j + 1];
            }

            //average of top edge
            if (i == 0)
            {
                //average of current row of pixels
                avgLine = rowAvg(row, onEdge);

                //check if edge case (width) and assign values in row[] accordingly
                if (j == 0)
                {
                    row[0] = copy[i + 1][j];
                    row[1] = copy[i + 1][j + 1];
                }
                else if (j == width - 1)
                {
                    row[0] = copy[i + 1][j - 1];
                    row[1] = copy[i + 1][j];
                }
                else
                {
                    row[0] = copy[i + 1][j - 1];
                    row[1] = copy[i + 1][j];
                    row[2] = copy[i + 1][j + 1];
                }

                //average of row below
                avgBelow = rowAvg(row, onEdge);

                //calculate overall averages and save onto image
                image[i][j].rgbtRed = round((avgLine.rgbtRed + avgBelow.rgbtRed) / 2.0);
                image[i][j].rgbtBlue = round((avgLine.rgbtBlue + avgBelow.rgbtBlue) / 2.0);
                image[i][j].rgbtGreen = round((avgLine.rgbtGreen + avgBelow.rgbtGreen) / 2.0);

            }
            //average of bottom edge
            else if (i == height - 1)
            {
                //average of current row of pixels
                avgLine = rowAvg(row, onEdge);

                //check if edge case (width) and set values in row[] accordingly
                if (j == 0)
                {
                    row[0] = copy[i - 1][j];
                    row[1] = copy[i - 1][j + 1];
                }
                else if (j == width - 1)
                {
                    row[0] = copy[i - 1][j - 1];
                    row[1] = copy[i - 1][j];
                }
                else
                {
                    row[0] = copy[i - 1][j - 1];
                    row[1] = copy[i - 1][j];
                    row[2] = copy[i - 1][j + 1];
                }

                //average of row above
                avgAbove = rowAvg(row, onEdge);

                //calculate overall average and set values to image
                image[i][j].rgbtRed = round((avgLine.rgbtRed + avgAbove.rgbtRed) / 2.0);
                image[i][j].rgbtBlue = round((avgLine.rgbtBlue + avgAbove.rgbtBlue) / 2.0);
                image[i][j].rgbtGreen = round((avgLine.rgbtGreen + avgAbove.rgbtGreen) / 2.0);
            }
            //average of all middle (height) pixels
            else
            {
                //average of current row of pixels
                avgLine = rowAvg(row, onEdge);

                //check if edge case (width) and set values in row[] accordingly
                if (j == 0)
                {
                    row[0] = copy[i + 1][j];
                    row[1] = copy[i + 1][j + 1];
                }
                else if (j == width - 1)
                {
                    row[0] = copy[i + 1][j - 1];
                    row[1] = copy[i + 1][j];
                }
                else
                {
                    row[0] = copy[i + 1][j - 1];
                    row[1] = copy[i + 1][j];
                    row[2] = copy[i + 1][j + 1];
                }

                //average of row below
                avgBelow = rowAvg(row, onEdge);

                //check if edge case (width) again but set values for row above instead of below
                if (j == 0)
                {
                    row[0] = copy[i - 1][j];
                    row[1] = copy[i - 1][j + 1];
                }
                else if (j == width - 1)
                {
                    row[0] = copy[i - 1][j - 1];
                    row[1] = copy[i - 1][j];
                }
                else
                {
                    row[0] = copy[i - 1][j - 1];
                    row[1] = copy[i - 1][j];
                    row[2] = copy[i - 1][j + 1];
                }

                //average of row above
                avgAbove = rowAvg(row, onEdge);

                //calculate overall averages and set values on image
                image[i][j].rgbtRed = round((avgLine.rgbtRed + avgBelow.rgbtRed + avgAbove.rgbtRed) / 3.0);
                image[i][j].rgbtBlue = round((avgLine.rgbtBlue + avgBelow.rgbtBlue + avgAbove.rgbtBlue) / 3.0);
                image[i][j].rgbtGreen = round((avgLine.rgbtGreen + avgBelow.rgbtGreen + avgAbove.rgbtGreen) / 3.0);
            }

            free(row);
        }
    }

}


//function to calculate average of row of pixels for blur
RGBFLOAT rowAvg(RGBTRIPLE row[2], bool onEdge)
{
    RGBFLOAT avg;
    if (!onEdge)
    {
        avg.rgbtRed = (row[0].rgbtRed + row[1].rgbtRed + row[2].rgbtRed) / 3.0;
        avg.rgbtBlue = (row[0].rgbtBlue + row[1].rgbtBlue + row[2].rgbtBlue) / 3.0;
        avg.rgbtGreen = (row[0].rgbtGreen + row[1].rgbtGreen + row[2].rgbtGreen) / 3.0;
    }
    else
    {
        avg.rgbtRed = (row[0].rgbtRed + row[1].rgbtRed) / 2.0;
        avg.rgbtBlue = (row[0].rgbtBlue + row[1].rgbtBlue) / 2.0;
        avg.rgbtGreen = (row[0].rgbtGreen + row[1].rgbtGreen) / 2.0;
    }
    return avg;
}