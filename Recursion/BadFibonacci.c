#include <stdio.h>

int input(int* n)
{
    printf("Enter n for Fibonnaci(n): ");
    scanf("%d", n);
}

/*
Bad Recurision -> Leads into big recurision tree hence multiple calculation of same input
int fibonacci(int n)
{
    if (n > 1) return fibonacci(n - 1) + fibonacci(n - 2);
    else return n;
}
*/

// 5 => 0 1 1 2 3 5
// Iteration (Better than Bad recursion)
int fibonacci(int n)
{
    if (n <= 1) return n;
    else
    {
        int num1 = 1, num2 = 0;
        while (--n)
        {
            int temp = num1;
            num1 = num1 + num2;
            num2 = temp;
        }
        return num1;
    }
}

void output(int n, int result)
{
    printf("The fibonacci of F(%d) is %d\n", n, result);
}

int main()
{
    int num;
    input(&num);
    int result = fibonacci(num);
    output(num, result);
    return 0;
}