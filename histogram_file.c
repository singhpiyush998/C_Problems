/*
Develop a program that, given a collection of quiz scores, generates a histogram showing the
collection’s frequency distribution. Quiz scores will be in the range zero to twenty, inclusive.
Input: The first line contains a positive integer n indicating how many collections are to be
processed. Each collection is described on two or more lines, the first of which contains the
number of quiz scores m (m > 0) in that collection. The remaining lines contain the quiz scores
themselves, twenty scores per line up until the last one, which will have a number of scores
equal to the remainder obtained when m is divided by 20.
Output: For each collection of quiz scores, the program should generate a histogram indicating
the frequency with which each of the values zero through twenty occurs in that collection.
The histogram’s form should be as in the sample output below. Specifically, the only quiz
scores that should be mentioned explicitly in the histogram are those between the minimum
and maximum scores recorded, inclusive. (For the first example below, this range is ten through
nineteen.)
The number of lines generated for a histogram should be exactly k+3, where k is the maximum
number of occurrences of any of the quiz scores. This accounts for there being k asterisks in
the tallest column, one line for the scale (containing dashes and plus signs), one line containing
the quiz scores, and a blank line to separate one histogram from the next.
2
Sample input:
-------------
2
22
10 12 16 12 10 19 19 19 12 14 13 14 14 16 17 14 15 13 18 15
15 17
5
20 4 12 12 17
Resultant output:
-----------------
*
* * * *
* * * * * * * *
* * * * * * * * *
-+--+--+--+--+--+--+--+--+--+
10 11 12 13 14 15 16 17 18 19
*
* * * *
-+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct occurence
{
    int score, occurence;
} Occurence;

typedef struct histogram
{
    int score_count;
    int scores[100];
    Occurence occurence_per_score[100];
    int max_occurence;
    int range;
    int repeating_number_count;
} Histogram;

void input_n(int* n, FILE* fh_input)
{
    fscanf(fh_input, "%d", n);
}

void input(Histogram* histogram, FILE* fh_input)
{
    fscanf(fh_input, "%d", &histogram->score_count);
    for (int j = 0; j < histogram->score_count; j++)
    {
        fscanf(fh_input, "%d", &histogram->scores[j]);
    }
    histogram->repeating_number_count = 0;
}

void input_n_histograms(int n, Histogram histograms[n], FILE* fh_input)
{
    for (int i = 0; i < n; i++)
    {
        input(&histograms[i], fh_input);
    }
}

// Insertion sort
void sort_scores(int length, int data[length])
{
    int curr_el_index = 1;
    int last_el_index = 0;

    for (int i = 0; i < length - 1; i++)
    {
        int current_el = data[curr_el_index];
        int shift_index = 0;
        for (int j = 0; j < curr_el_index; j++)
        {
            if (current_el < data[last_el_index])
            {
                // Shifting the bigger element one place to the right
                data[last_el_index + 1] = data[last_el_index];
                last_el_index--;
                shift_index++;
            }
            else
            {
                break;
            }
        }
        // Shifting the current element to its correct place
        if (shift_index)
            data[curr_el_index - shift_index] = current_el;
        curr_el_index++;
        last_el_index = curr_el_index - 1;
    }
}

// Counts the number of occurences for a given number in an array
void count_occurences(Histogram* histogram)
{
    int occurence_tracker = 0;
    int i = 0;
    while (i < histogram->score_count)
    {
        int curr_el = histogram->scores[i];
        histogram->occurence_per_score[occurence_tracker].score = curr_el;
        int count = 1;

        while (curr_el == histogram->scores[++i])
        {
            count++;
            histogram->repeating_number_count++;
        }
        histogram->occurence_per_score[occurence_tracker].occurence = count;
        occurence_tracker++;
    }
}

int get_max_occurence(int length, Occurence data[length])
{
    int maximum = 0;
    for (int i = 0; i < length; i++)
    {
        if (maximum < data[i].occurence)
        {
            maximum = data[i].occurence;
        }
    }
    return maximum;
}

void analyse_histogram(Histogram* histogram)
{
    sort_scores(histogram->score_count, histogram->scores);
    histogram->range = histogram->scores[histogram->score_count - 1] - histogram->scores[0];
    count_occurences(histogram);
    histogram->max_occurence = get_max_occurence(histogram->score_count - histogram->repeating_number_count, histogram->occurence_per_score);
}

void analyse_n_histograms(int n, Histogram histograms[n])
{
    for (int i = 0; i < n; i++)
    {
        analyse_histogram(&histograms[i]);
    }
}

void output(Histogram* histogram)
{
    int row_count = histogram->max_occurence;
    while (row_count)
    {
        printf(" ");
        int col_index = 0, occurence_index = 0;
        while (col_index <= histogram->range)
        {
            int next_score = histogram->occurence_per_score[occurence_index + 1].score;
            int curr_score = histogram->occurence_per_score[occurence_index].score;

            if (occurence_index < histogram->score_count - histogram->repeating_number_count)
            {
                int current_score_occurences = histogram->occurence_per_score[occurence_index].occurence;
                if (current_score_occurences >= row_count)
                {
                    printf("*  ");
                }
                else
                {
                    printf("   ");
                }
                occurence_index++;
                col_index++;
            }

            if (next_score <= 20 && curr_score < next_score - 1)
            {
                while (curr_score < next_score - 1)
                {
                    printf("   ");
                    curr_score++;
                    col_index++;
                }
            }
        }
        row_count--;
        printf("\n");
    }

    // Printing a line of white spaces
    for (int col_index = 0; col_index <= histogram->range; col_index++)
    {
        printf(" ");
    }

    // Printing the Scale line (dashes and plus)
    printf("\n-+");
    for (int col_index = 0; col_index < histogram->range; col_index++)
    {
        printf("--+");
    }
    printf("\n");

    // Printing the scores
    int score = histogram->scores[0];
    for (int col_index = 0; col_index <= histogram->range; col_index++)
    {
        if (score < 10)
            printf(" %d ", score);
        else
            printf("%d ", score);
        score++;
    }
    printf("\n\n");
}

void output_n_histograms(int n, Histogram histograms[n])
{
    for (int i = 0; i < n; i++)
    {
        output(&histograms[i]);
    }
}

int main(void)
{
    FILE* fh_input = fopen("histogram_in.txt", "r");
    if (fh_input == NULL) {
        printf("Failed to read the file\n");
        exit(EXIT_FAILURE);
    }
    int ques_count;
    input_n(&ques_count, fh_input);
    Histogram histograms[ques_count];

    input_n_histograms(ques_count, histograms, fh_input);
    analyse_n_histograms(ques_count, histograms);
    output_n_histograms(ques_count, histograms);

    fclose(fh_input);
    return 0;
}