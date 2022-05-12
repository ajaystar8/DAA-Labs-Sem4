#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *sieve(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));

    arr[0] = arr[1] = 0;
    // making an array of prime number from 2 to n
    for (int i = 2; i <= n; i++)
    {
        arr[i] = i;
    }

    // now start cancelling out the non prime numbers

    // start from 2 and go uptill sqrt(n)
    for (int i = 2; i < floor(sqrt(n)); i++)
    {
        // cancel out numbers starting from 2*i going upto n
        for (int j = 2 * i; j <= n; j += i)
        {
            arr[j] = 0;
        }
    }

    // return the array
    return arr;
}

int main()
{
    int *prime;
    prime = sieve(20);
    printf("Prime numbers are: \n");
    for (int i = 2; i <= 20; i++)
    {
        if (prime[i] != 0)
        {
            printf("%d ", i);
        }
    }

    return 0;
}