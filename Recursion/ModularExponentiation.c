#include <stdio.h>

void input(int* x, int* n, int* m)
{
    printf("Enter the number and it's power and the mod: ");
    scanf("%d%d%d", x, n, m);
}

int modPow(int x, int n, int m)
{
    if (n == 0) return 1;
    else if (n % 2)
    {
        return ((x % m) * modPow(x, n - 1, m)) % m;
    }
    else
    {
        int y = modPow(x, n / 2, m);
        return (y * y) % m;
    }
}

void output(int x, int n, int m, int res)
{
    printf("The remainder when %d raised to %d is divided by %d is %d\n", x, n, m, res);
}

int main()
{
    int num, exp, mod;
    input(&num, &exp, &mod);
    int res = modPow(num, exp, mod);
    output(num, exp, mod, res);
    return 0;
}