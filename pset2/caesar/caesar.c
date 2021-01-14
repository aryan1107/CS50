// Aryan Chaurasia
// CS50 Pset 2 Caesar
// Jan 4, 2021
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // if arc doesn't has 2 argument prints error
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // if there are 2 arguments checks if all the second argument contains digits
        string k = argv[1];
        for (int i = 0; i < strlen(k); i++)
        {
            if (isdigit(k[i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;

            }
        }
        // print commands below for testing purpose

        // printf("Success\n");
        // printf("%s\n",k);

        // converts second argument to int
        int myKey = atoi(k);

        // asks users for plaintext to be ciphered
        string plaintext = get_string("Plaintext: ");

        // For loop to convert to ciphertext
        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isupper(plaintext[i]))
            {
                // by given formula need to change base so that A is 0
                // when you minus capital A ASCII value by 65 it becomes 0
                plaintext[i] = (plaintext[i] - 65);
                plaintext[i] = (plaintext[i] + myKey) % 26;
                plaintext[i] = (plaintext[i] + 65);
                // printf("%c",plaintext[i]);
            }
            if (islower(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] - 97);
                plaintext[i] = (plaintext[i] + myKey) % 26;
                plaintext[i] = (plaintext[i] + 97);
                // printf("%c",plaintext[i]);

            }
            if (isalpha(plaintext[i]) == 0)
            {
                plaintext[i] = plaintext[i];
                // printf("%c",plaintext[i]);
            }
        }
        printf("Ciphertext: %s", plaintext);
        printf("\n");

    }

}

