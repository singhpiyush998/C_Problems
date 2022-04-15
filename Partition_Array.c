/*
Take the first number of an array and put it at a postion where all the numbers left to it are less than itself
 and all the numbers right to it are greater than itself
*/

#include <stdio.h>

void input_n(int* n)
{
    printf("Enter the length of the array:\n");
    scanf("%d", n);
}

void input_data(int n, int data[n])
{
    printf("Enter all elements of the array separated by spaces:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
}

void partition_array(int length, int data[length])
{
    int pivot_ptr = 0;
    int large_el_ptr = length - 1;

    while (pivot_ptr != large_el_ptr)
    {
        int temp = data[pivot_ptr + 1];
        if (temp <= data[pivot_ptr])
        {
            data[pivot_ptr + 1] = data[pivot_ptr];
            data[pivot_ptr] = temp;;
            pivot_ptr++;
        }
        else
        {
            data[pivot_ptr + 1] = data[large_el_ptr];
            data[large_el_ptr] = temp;
            large_el_ptr--;
        }
    }
}

/*
void partition_array(int length, int data[length])
{
    int small_el_count = 0;
    int curr_el_ptr = 1;
    int next_el_ptr = 2;
    while (next_el_ptr != length)
    {
        if (data[curr_el_ptr] > data[next_el_ptr] && data[next_el_ptr] < data[0])
        {
            int temp = data[next_el_ptr];
            data[next_el_ptr] = data[curr_el_ptr];
            data[curr_el_ptr] = temp;
            small_el_count++;
            curr_el_ptr++;
        }
        else if (data[curr_el_ptr] <= data[next_el_ptr] && data[curr_el_ptr] <= data[0])
        {
            curr_el_ptr++;
            small_el_count++;
        }
        next_el_ptr++;
    }
    int temp = data[0];
    data[0] = data[small_el_count];
    data[small_el_count] = temp;
}
*/

void output(int length, int result[length])
{
    printf("The partitioned array using the first element is:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main()
{
    int length;
    input_n(&length);

    int data[length];
    input_data(length, data);

    partition_array(length, data);

    output(length, data);

    return 0;
}