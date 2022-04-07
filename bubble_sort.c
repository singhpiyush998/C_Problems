#include <stdio.h>

void input_length(int* n);
void input_data(int n, int* data);
void sort(int length, int* data);
void recursive_sort(int length, int* data);
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
        for (int j = 0; j < length - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void recursive_sort(int length, int* data)
{
    if (length == 1) return;
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (data[i] > data[i + 1])
            {
                int temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        }
        recursive_sort(length - 1, data);
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