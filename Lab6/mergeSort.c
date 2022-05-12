#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// int a[100];
int opcount = 0;

void merge(int *a, int s, int e)
{
    // find mid
    int mid = (s + e) / 2;

    // divide given array into two parts
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // to store first and second parts of the array
    int *first = (int *)malloc(len1 * sizeof(int));
    int *second = (int *)malloc(len2 * sizeof(int));

    // storing first part
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
        first[i] = a[mainArrayIndex++];

    // storing second part
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
        second[i] = a[mainArrayIndex++];

    // pointers to keep track of the 2 arrays
    int index1 = 0;
    int index2 = 0;

    // the sorted array will be placed in the same inputted array

    // keeps track of the indices of the sorted array
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        opcount++;
        if (first[index1] < second[index2])
            a[mainArrayIndex++] = first[index1++];
        else
            a[mainArrayIndex++] = second[index2++];
    }

    // if len(first) is greater than the second
    while (index1 < len1)
        a[mainArrayIndex++] = first[index1++];

    // if len(second) is greater than the first
    while (index2 < len2)
        a[mainArrayIndex++] = second[index2++];
}

void mergeSort(int *a, int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;

    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);

    merge(a, s, e);
}

int main()
{
    // int n;

    // printf("Enter number of elements in the array: \n");
    // scanf("%d", &n);

    // printf("Enter the elements: ");
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &a[i]);

    // mergeSort(a, 0, n - 1);

    // printf("\n");

    // printf("The array after performing Merge Sort is: \n");
    // for (int i = 0; i < n; i++)
    //     printf("%d ", a[i]);

    // printf("\n");
    // printf("\n");

    // printf("Opcount: %d", opcount);

    for (int i = 0; i < 20; i++)
    {
        opcount = 0;
        int arr[i + 1];
        for (int j = 0; j < i + 1; j++)
            arr[j] = j + 1;
        mergeSort(arr, 0, i);

        for (int j = 0; j < i + 1; j++)
            printf("%d ", arr[j]);

        printf("Opcount: %d", opcount);
        printf("\n");
    }

    return 0;
}