#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// int a[100];
int opcount = 0;

void swap(int *a, int *b)
{

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lb, int ub)
{
    int pivot, start, end;

    // fixing the first element of the array as the pivot
    pivot = arr[lb];

    // to iterate the array
    start = lb;
    end = ub + 1;

    do
    {
        //  increment 'start' untill the pointing element is less than the pivot
        do
        {
            opcount++;
            start++;
        } while (arr[start] < pivot);

        // decrement 'end' untill the pointing element is greater then the pivot
        do
        {
            opcount++;
            end--;
        } while (arr[end] > pivot);

        // now, swap the start and end elements

        if (start < end)
            swap(&arr[start], &arr[end]);

    } while (start < end);

    // swap the lower bound element and the 'end' element
    swap(&arr[lb], &arr[end]);

    return end;
}

void quickSort(int arr[], int lb, int ub)
{
    int loc;

    if (lb < ub)
    {
        loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}

int main()
{
    for (int i = 0; i < 20; i++)
    {
        opcount = 0;

        int arr[i + 1];
        arr[i + 1] = INT16_MAX;

        for (int j = 0; j < i + 1; j++)
            arr[j] = 1;

        quickSort(arr, 0, i);

        for (int j = 0; j < i + 1; j++)
            printf("%d ", arr[j]);

        printf("Opcount: %d", opcount);
        printf("\n");
    }

    return 0;
}