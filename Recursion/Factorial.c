#include <stdio.h>

void input(int* num)
{
    printf("Enter the number: ");
    scanf("%d", num);
}

int fact(int n)
{
    if (n > 0) return n * fact(n - 1);
    return 1;
}

void output(int n, int res)
{
    printf("The factorial of %d is %d\n", n, res);
}

int main()
{
    int num, result;
    input(&num);
    result = fact(num);
    output(num, result);
    return 0;
}