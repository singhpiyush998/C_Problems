#include </home/piyush/Documents/Coding/C/Problems/tst1.c>
#include <stdio.h>

extern int foo; // declaration

int main(void)
{
    print();
    foo = 10;
    printf("%d\n", foo);
    return 0;
}