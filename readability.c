#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    // Prompt the user for a string
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int n_letters = count_letters(text);
    int n_words = count_words(text);
    int n_sentences = count_sentences(text);

    // Average letters per 100 words
    float L = (n_letters / (float) n_words) * 100;
    // Average sentences per 100 words
    float S = (n_sentences / (float) n_words) * 100;
    // Coleman-Liau index computation
    double index = 0.0588 * L - 0.296 * S - 15.8;

    // Check grade level
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }

}

// Count the letters in a sentence
int count_letters(string text)
{
    int count = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (isalpha(text[c]))
        {
            count ++;
        }
    }
    return count;
}

// Count the words in a sentence
int count_words(string text)
{
    int count = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (text[c] == ' ' || (text[c] == '.' && text[c + 1] == '\0'))
        {
            count ++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (text[c] == '.' || text[c] == '!' || text[c] == '?')
        {
            count ++;
        }
    }
    return count;
}
