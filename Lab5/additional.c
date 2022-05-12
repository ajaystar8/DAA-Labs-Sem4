#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int visited[100] = {0};
int inDegree[100] = {0};
int count = 0;

void taskOrdering(int graph[100][100], int tasks)
{
    // updating the inDegree array
    for (int i = 0; i < tasks; i++)
        for (int j = 0; j < tasks; j++)
            inDegree[i] += graph[j][i];

    printf("The order of tasks to be performed is: \n");

    for (int i = 0; i < tasks; i++)
    {
        for (int k = 0; k < tasks; k++)
        {
            if (inDegree[k] == 0 && visited[k] == 0)
            {
                printf("%d ", k + 1);
                visited[k] = 1;

                for (int j = 0; j < tasks; j++)
                    if (graph[k][j] == 1)
                        inDegree[j]--;
            }
        }
    }
    printf("\n");
}

int main()
{
    int n;

    printf("Enter the number of tasks:\n");
    scanf("%d", &n);

    printf("Enter the task dependencies in a %d x %d matrix format: \n", n, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    taskOrdering(graph, n);
}