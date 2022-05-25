#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int arr[100] = {0};

void insertionSort(int arr[100], int n)
{
    int v, j;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        v = arr[i];
        while (j >= 0 && arr[j] > v)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;
    }
}

int main()
{
    int arr[5] = {9, 5, 4, 1, 7};
    int n = 5;

    printf("The input array is \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    insertionSort(arr, n);

    printf("\nThe sorted array is \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}