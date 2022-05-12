#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;

    printf("Enter the first number: ");
    scanf("%d", &m);

    printf("Enter the second number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    printf("The GCD of the two numbers is: %d", m);

    return 0;
}
