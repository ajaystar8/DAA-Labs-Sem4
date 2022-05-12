#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bitVectorGenerate(int n, int arr[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i] = n % 2;
        n /= 2;
    }
}

void partitionSum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    if (sum % 2)
    {
        printf("Equal partitions not possible beacuse total sum is odd!\n");
        return;
    }

    sum /= 2;

    int bitVector[size];

    for (int i = 0; i < pow(2, size); i++)
    {
        int subsetSum = 0;
        bitVectorGenerate(i, bitVector, size);

        for (int j = 0; j < size; j++)
            if (bitVector[j])
                subsetSum += arr[j];

        if (subsetSum == sum)
        {
            printf("Two subsets generated are:\n");
            printf("{");
            for (int j = 0; j < size; j++)
                if (bitVector[j])
                    printf("%d,", arr[j]);

            printf("} {");

            for (int i = 0; i < size; i++)
                if (!bitVector[i])
                    printf("%d,", arr[i]);
            printf("}\n");
            return;
        }
    }
    printf("Such subsets can't be made in this case!\n");
}

int main()
{
    int size = 0;
    printf("Enter size of array : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter array elements : ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    partitionSum(arr, size);
    return 0;
}