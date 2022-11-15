#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = 0;

    // Prompting for input
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    // Printing a new line
    for (int i = 0; i < h; i++)
    {
        // Printing spaces
        for (int j = 0; j < (h - (i + 1)); j++)
        {
            printf(" ");
        }

        // Printing hashes
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }

        printf("\n");
    }
}