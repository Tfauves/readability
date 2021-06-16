// Finding text grade level using the Coleman-Liau index
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");
    int lettercount = 0, sentcount = 0;
    int wordcount = 1;

    for (int t = 0; t < strlen(text); t++)
    {
        //Capturing lettercount by finding lower and uppercase letter
        if ((text[t] >= 'a' && text[t] <= 'z') || (text[t] >= 'A' && text[t] <= 'Z'))
        {
            lettercount++;
        }//Uses blank spaces to capture words
        else if (text[t] == ' ')
        {
            wordcount++;
        }// Finding sentences by locating punctuation
        else if (text[t] == '.' || text[t] == '!' || text[t] == '?')
        {
            sentcount++;
        }
    }//Casting denominators from ints to floats
    float L = (lettercount / (float) wordcount) * 100;
    float S = (sentcount / (float) wordcount) * 100;
    int C_L_index = round(0.0588 * L - 0.296 * S - 15.8);
    {
        printf("Grade %i\n", C_L_index);
    }
    if (C_L_index < - 1)
    {
        printf("Before Grade 1\n");
    }
    else if (C_L_index >= 16)
    {
        printf("Grade 16+\n");
    }

}