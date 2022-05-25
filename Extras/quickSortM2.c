#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    int temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}
void quicksort(int *a, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(a, lb, ub);
        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}
int main()
{
    int a[5] = {2, 6, 8, 8, 1};
    int n = 5;
    quicksort(a, 0, n - 1);
    printf("The sorted array is \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}