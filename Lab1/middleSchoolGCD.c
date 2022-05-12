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
        for (int j = 2 * i; j <= n; j += i)
        {
            prime[j] = 0;
        }
    }
    return prime;
}

int gcd(int m, int n)
{
    if (m == n)
        return n;
    int *primes = sieve(m > n ? n : m);
    int i = 0, answer = 1;
    while (i < sizeof(primes))
    {
        while (!(m % primes[i]) && !(n % primes[i]))
        {
            answer *= primes[i];
            m /= primes[i];
            n /= primes[i];
        }
        i++;
    }
    return answer;
}

int main()
{
    printf("%d", gcd(36, 60));
    return 0;
}