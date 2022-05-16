#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i)
{
    int largestIndx = i;
    int leftChildIdx = 2 * i + 1;
    int rightChildIdx = 2 * i + 2;

    if (leftChildIdx < n && arr[leftChildIdx] > arr[largestIndx])
        largestIndx = leftChildIdx;

    if (rightChildIdx < n && arr[rightChildIdx] > arr[largestIndx])
        largestIndx = rightChildIdx;

    if (largestIndx != i)
    {
        swap(&arr[largestIndx], &arr[i]);
        heapify(arr, n, largestIndx);
    }
}

void buildHeap(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int *arr, int n)
{
    // perform heapification of the tree
    buildHeap(arr, n);

    // remove root node and then perform heapification
    // root node consists of the largest element of the array
    for (int i = n - 1; i >= 0; i--)
    {
        // swap the largest and the smallest element of the array
        swap(&arr[i], &arr[0]);

        // reduce size of heap by 1 (i = n - 1)
        heapify(arr, i, 0);
    }
}

void printHeap(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("Sorted array is \n");

    printHeap(arr, n);
    return 0;
}