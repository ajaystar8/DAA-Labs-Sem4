#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int opcount = 0;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i)
{
    // saving the indices of the node and its children on which heapification is to be performed
    int largestIdx = i;
    int leftChildIdx = 2 * i + 1;
    int rightChildIdx = 2 * i + 2;

    // first condition is to check whether left child exists or not
    opcount++;
    if (leftChildIdx < n && arr[leftChildIdx] > arr[largestIdx])
        largestIdx = leftChildIdx;

    opcount++;
    if (rightChildIdx < n && arr[rightChildIdx] > arr[largestIdx])
        largestIdx = rightChildIdx;

    if (largestIdx != i)
    {
        // if the node on which heapify ws called doesn't possess parental dominance, then
        // swap it with the largest value (of its children), and then call heapify() for the
        // corresponding left/ right child.

        // so, it is like, we are going on calling heapify() till we reach the last parental node
        // of the heap.

        swap(&arr[largestIdx], &arr[i]);
        heapify(arr, n, largestIdx);
    }
}

void buildHeap(int *arr, int n)
{
    int startIdx = n / 2 - 1;
    for (int i = startIdx; i >= 0; i--)
        heapify(arr, n, i);
}

void printHeap(int *arr, int n)
{
    printf("Array representation of the heap is: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nOpcount: %d\n", opcount);
}

int main()
{
    int n = 11;
    int heap[11] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    buildHeap(heap, n);
    printHeap(heap, n);

    return 0;
}