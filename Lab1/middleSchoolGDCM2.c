#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *sieve(int n)
{
    int *prime = (int *)malloc((n + 1) * sizeof(int));
    prime[0] = prime[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        prime[i] = i;
    }

    for (int i = 2; i <= floor(sqrt(n)); i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            prime[j] = 0;
        }
    }
    return prime;
}

int gcd(int m, int n)
{
    int answer = 1;
    int i = 0;
    int j = 0;
    int k = 0;

    int *primes = sieve(m > n ? n : m);

    // arrays to store the common factors
    int mPrimes[100] = {0};
    int nPrimes[100] = {0};

    //  && !(n % primes[i])
    if (m == n)
        return n;

    while (i < sizeof(primes))
    {
        while (!(m % primes[i]))
        {
            mPrimes[j] = primes[i];
            m /= primes[i];
            j++;
        }
        while (!(n % primes[i]))
        {
            nPrimes[k] = primes[i];
            m /= primes[i];
            k++;
        }
        i++;
    }
}

int main()
{
    printf("%d", gcd(36, 60));
    return 0;
}