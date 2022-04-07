#include <stdio.h>

void input_length(int* n);
void input_data(int n, int* data);
void sort(int length, int* data);
void output(int n, int* data);

int main(void)
{
    int length;
    input_length(&length);
    int data[length];
    input_data(length, data);
    sort(length, data);
    output(length, data);

    return 0;
}

void input_length(int* n)
{
    printf("Enter the length of the array: ");
    scanf("%d", n);
}

void input_data(int n, int* data)
{
    printf("Enter the values of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
}

void sort(int length, int* data)
{
    for (int i = 0; i < length; i++)
    {
        int j = 0;
        int big_index = j;
        for (j += 1; j < length - i; j++)
        {
            if (data[j] > data[big_index])
                big_index = j;
        }
        int temp = data[big_index];
        data[big_index] = data[j - 1];
        data[j - 1] = temp;
    }
}


void output(int n, int* data)
{
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}