#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int heap[100] = {0};
int opcount = 0;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyTopDown(int heap[], int currentIndex)
{
    int parent = (currentIndex - 1) / 2;
    // while parent exists
    while (parent >= 0)
    {
        opcount++;
        if (heap[parent] < heap[currentIndex])
        {
            // swap
            swap(&heap[parent], &heap[currentIndex]);
            currentIndex = parent;
            parent = (currentIndex - 1) / 2;
        }
        else
            return;
    }
    return;
}

int main()
{
    int n;
    printf("Enter the number of elements in heap: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        // start heapification from the last leaf node
        scanf("%d", &heap[i]);
        // top-down approach performs heapification from the last leaf node
        // that's why, current node(below) is the node which is inserted above
        heapifyTopDown(heap, i);
    }

    printf("Heapified Array: \n");

    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n");

    printf("Opcount: %d\n", opcount);

    return 0;
}