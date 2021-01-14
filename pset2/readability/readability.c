// Aryan Chaurasia
// Pset2 readability | CS50
// Jan 3, 2021
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float average_letters(float myletters, float mywords);
float average_sentence(float mysentence, float mywords);
int main(void)
{
    // TODO: Prompt for start size
    string text;
    do
    {
        text = get_string("Text: ");
    }
    while (text < 0);

    // ints to calculate words, sentence and letters
    // int word is initialized as 1 because we are counting words by spaces: i.e. words would be: spaces + 1
    int letters = 0;
    int words = 1;
    int sentence = 0;

    // calculates number of sentences, words and letters
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters += 1;
        }
        else if (text[i] == ' ')
        {
            words += 1;
        }
        else if ((text[i] == '?') || (text[i] == '.') || (text[i] == '?'))
        {
            sentence += 1;
        }
    }

    float L = average_letters(letters, words);
    float S = average_sentence(sentence, words);
    float index;


    // Using Coleman-Liau index formula to get grade
    // L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text
    index = 0.0588 * L - 0.296 * S - 15.8;

    // Below have used printf to test and see codes result

    // printf("Letters: %i\n", letters);
    // printf("words: %i\n", words);
    // printf("sentence: %i\n", sentence);
    // printf("%i", index);

    // converted index to nearest whole number
    int grade = round(index);

    // prints grade according to the text
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

// Need to use float to get exact numbers that can be rounded
// if would have used int instead of float results would be truncated and not precise

// calculates average_letters in the text
float average_letters(float myletters, float mywords)
{

    float average_letters = (myletters * 100) / mywords ;
    return average_letters;
}

// calculates averege sentence in the text
float average_sentence(float mysentence, float mywords)
{

    float average_sentence = (mysentence * 100) / mywords;
    return average_sentence;
}