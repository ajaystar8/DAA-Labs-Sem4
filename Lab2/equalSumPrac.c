#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bitVectorGenerate(int arr[], int n, int num)
{
    for (int i = n - 1; i >= 0; i--)
    {

        arr[i] = num % 2;
        num /= 2;
    }
}

void equalSumSets(int arr[], int n)
{
    int bitVector[n];
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2)
    {
        printf("Not Possible!\n");
        return;
    }

    sum /= 2;

    for (int i = 1; i < pow(2, n); i++)
    {
        int subsetSum = 0;
        bitVectorGenerate(bitVector, n, i);
        for (int j = 0; j < n; j++)
        {
            if (bitVector[j])
                subsetSum += arr[j];
        }

        if (subsetSum == sum)
        {
            printf("Sets possible: \n");
            printf("Set-1: { ");
            for (int j = 0; j < n; j++)
            {
                if (bitVector[j])
                    printf("%d,", arr[j]);
            }
            printf(" }\n");
            printf("Set-2: { ");
            for (int j = 0; j < n; j++)
            {
                if (!bitVector[j])
                    printf("%d,", arr[j]);
            }
            printf(" }\n");
            return;
        }
    }
    printf("Equal partitions not possible!\n");
}

int main()
{
    int n;

    printf("Number of elements: \n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    equalSumSets(arr, n);

    return 0;
}