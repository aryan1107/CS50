#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    // asks users for height
    do
    {
        height = get_int("Height: ");
    }
    // asks height if height < 1 and Height > 8
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        // adds space which starts by one less than height
        for (int j = i; j < height - 1; j++)
        {
            printf(" ");
        }
        // prints mario blocks according to height starts from 1
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("  ");
        // prints mario blocks according to height starts from 1
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // Adds new line to the code
        printf("\n");
    }
}