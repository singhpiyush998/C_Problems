#include <stdio.h>

void input(int* x, int* n)
{
    printf("Enter the number and it's power: ");
    scanf("%d%d", x, n);
}

int Pow(int x, int n)
{
    if (n == 0) return 1;
    else if (n % 2) // n is odd
    {
        return x * Pow(x, n - 1);
    }
    else // n is even
    {
        int y = Pow(x, n / 2);
        return y * y;
    }
}

void output(int x, int n, int res)
{
    printf("%d raised to %d is %d\n", x, n, res);
}

int main()
{
    int num, exp;
    input(&num, &exp);
    int res = Pow(num, exp);
    output(num, exp, res);
    return 0;
}