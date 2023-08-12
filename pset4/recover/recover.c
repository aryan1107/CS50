#include <stdint.h>
#include <stdio.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("Could not open %s\n", argv[1]);
        return 2;
    }

    FILE *img = NULL;

    BYTE buffer[BLOCK_SIZE];

    char filename[8];

    int counter = 0;

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // checks if start of img in buffer
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if start of img and it's not first image i.e. counter != 0
            // closes the previous image
            if (counter != 0)
            {
                fclose(img);
            }

            // begins writing new image
            sprintf(filename, "%03i.jpg", counter);

            img = fopen(filename, "w");
            if (!img)
            {
                printf("Could not create %s\n", filename);
                return 3;
            }

            fwrite(&buffer, 1, BLOCK_SIZE, img);

            counter += 1;
        }

        // if not start of new img
        // then it keeps on writing the image

        else if (counter != 0)
        {
            fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    // Close file
    fclose(file);
    fclose(img);
    return 0;
}
