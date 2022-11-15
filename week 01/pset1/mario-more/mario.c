#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = 0;

    // User input
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    // Printing new lines
    for (int i = 0; i < h; i++)
    {

        // Printing spaces before hashes
        for (int j = 0; j < (h - (i + 1)); j++)
        {
            printf(" ");
        }

        // Printing first set of hashes
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }

        // Printing the gap
        for (int j = 0; j < 2; j++)
        {
            printf(" ");
        }

        // Printing second set of hashes
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }

        printf("\n");
    }
}