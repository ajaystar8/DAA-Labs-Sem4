#include <stdio.h>
#include <stdlib.h>

int minTime = INT16_MAX;
int minTimePermutation[100] = {0};
int opcount = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void timeCalculate(int *arr, int size, int **cost_matrix)
{
    int cost = 0;
    for (int i = 0; i < size; i++)
        cost += cost_matrix[i][arr[i] - 1];
    if (cost < minTime)
    {
        minTime = cost;

        for (int i = 0; i < size; i++)
            minTimePermutation[i] = arr[i];
    }
}

void assignment(int *arr, int start, int end, int **cost_matrix)
{
    if (start == end)
    {
        opcount++;
        timeCalculate(arr, end + 1, cost_matrix);
        return;
    }

    else
    {
        for (int i = start; i <= end; i++)
        {
            swap((arr + i), (arr + start));
            assignment(arr, start + 1, end, cost_matrix);
            swap((arr + i), (arr + start));
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of people: ");
    scanf("%d", &n);

    // array of people
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    // making the cost matrix
    int *cost_matrix[n];
    for (int i = 0; i < n; i++)
        cost_matrix[i] = (int *)malloc(n * sizeof(int));

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter time taken by person %d to do job %d: ", i + 1, j + 1);
            scanf("%d", &cost_matrix[i][j]);
        }
    }

    // calling the assignmentProlem function
    assignment(arr, 0, n - 1, cost_matrix);

    // printing out the minimum time
    printf("The minimum time taken to do the job is: %d\n", minTime);

    // printing the permuation giving the minimum cost
    printf("The job will be done in minimum time when: \n");
    for (int i = 0; i < n; i++)
        printf("Person %d does job %d\n", i + 1, minTimePermutation[i]);

    printf("\n%d\n ", opcount);

    return 0;
}