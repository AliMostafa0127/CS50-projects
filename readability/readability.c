#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentence(string text);

int main(void)
{
    string n = get_string("Text: ");
    int x = count_letters(n);
    int w = count_words(n);
    int c = count_sentence(n);
    float L = (float) x * 100 / (float) w + 0.5;
    float S = (float) c * 100 / (float) w + 0.5;
    float index = ((0.0588 * L) - (0.296 * S) - 15.8);
    int index1 = round(index);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        // index = index + 0.5;
        printf("Grade %i\n", index1);
    }
}

int count_letters(string text)
{
    int f = strlen(text);
    int y = 0;
    for (int i = 0; i < f; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] <= 122 && text[i] >= 97))
        {
            y++;
        }
    }
    return y;
}

int count_words(string text)
{
    int f = strlen(text);
    int y = 0;
    for (int i = 0; i < f; i++)
    {
        if (text[i] == 32)
        {
            y++;
        }
    }
    return y + 1;
}

int count_sentence(string text)
{
    int f = strlen(text);
    int y = 0;
    for (int i = 0; i < f; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            y++;
        }
    }
    return y;
}
