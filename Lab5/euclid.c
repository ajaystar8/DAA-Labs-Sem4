#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int euclidGCD(int m, int n)
{
    if (n == 0)
        return m;

    else
        return euclidGCD(n, m % n);
}

int main()
{
    int m, n, gcd;
    printf("Enter the first number: ");
    scanf("%d", &m);

    printf("Enter the second number: ");
    scanf("%d", &n);

    gcd = euclidGCD(m, n);

    printf("The GCD of %d and %d is: %d", m, n, gcd);
    return 0;
}