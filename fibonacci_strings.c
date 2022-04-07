/*
Problem 1: Fibonacci String Sequences
One of the most famous families of sequences in mathematics is the family of Fibonacci
sequences. A Fibonacci sequence begins with two chosen values and is such that every value
thereafter is the sum of the previous two. For example, if we choose to begin the sequence with
0 and 1, respectively, we get
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, . . .
The same idea can be applied to character strings. However, rather than adding two consecutive
elements of a sequence to compute the next one, we concatenate them. For example, if we start
with the strings a and ba, we get the sequence
a, ba, aba, baaba, ababaaba, baabaababaaba, ababaababaabaababaaba, . . .
Develop a program that, given a positive integer m and two character strings, s1 and s2,
displays the first m elements of the Fibonacci string sequence (as defined above) whose first
two elements are s1 and s2, respectively.
Input: The first line contains a positive integer n indicating how many instances of the problem
are described thereafter. Each instance of the problem is described on three lines, the first of
which contains a positive integer m, the second of which contains a string s1, and the third of
which contains a string s2. (Neither s1 nor s2 contains any spaces (or, more generally, “white
space”).)
Output: For each triple (m, s1, s2) given as input, display the first m elements of the Fibonacci
string sequence that begins with s1 and s2, respectively, one string per line, and followed by a
blank line.
Sample input and output are on next page.
1
Sample input
------------
2
6
a
ba
7
spock
kirk
Corresponding output
--------------------
a
ba
aba
baaba
ababaaba
baabaababaaba
spock
kirk
spockkirk
kirkspockkirk
spockkirkkirkspockkirk
kirkspockkirkspockkirkkirkspockkirk
spockkirkkirkspockkirkkirkspockkirkspockkirkkirkspockkirk
*/

#include <stdio.h>
#include <string.h>

typedef struct fibonacci_strings
{
    int limit;
    char str1[50];
    char str2[50];
} Sequence;

void input_n(int *n)
{
    printf("Input the number of string pairs you'll give:\n");
    scanf("%d", n);
}

void input(Sequence *seq)
{
    printf("How many elements do you want in the Fabonacci String Sequence:\n");
    scanf("%d", &seq->limit);

    printf("Enter the first string:\n");
    scanf("%s", seq->str1);
    printf("Enter the second string:\n");
    scanf("%s", seq->str2);
}

void input_n_seq(int n, Sequence seq[n])
{
    for (int i = 0; i < n; i++)
    {
        input(&seq[i]);
    }
}

void output_sequence(Sequence *seq)
{
    char res[100];
    char str[100];

    strcpy(res, seq->str1);
    strcpy(str, seq->str2);

    printf("\n\n%s\n%s\n", res, str);
    for (int i = 0; i < seq->limit - 2; i++)
    {
        strcat(res, str);
        printf("%s\n", res);
        // Swapping two strings
        char temp[100];
        strcpy(temp, res);
        strcpy(res, str);
        strcpy(str, temp);
    }
}

void output_n_sequence(int n, Sequence seq[n])
{
    for (int i = 0; i < n; i++)
    {
        output_sequence(&seq[i]);
    }
}

int main()
{
    int ques_count;
    input_n(&ques_count);
    Sequence seq[ques_count];

    input_n_seq(ques_count, seq);
    output_n_sequence(ques_count, seq);

    return 0;
}
