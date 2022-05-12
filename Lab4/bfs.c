#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int visited[100] = {0};
int queue[100];
int front = 0;
int rear = 0;

// int graph[7][7] = {
//     {0, 1, 1, 1, 0, 0, 0},
//     {1, 0, 1, 0, 0, 0, 0},
//     {1, 1, 0, 1, 1, 0, 0},
//     {1, 0, 1, 0, 1, 0, 0},
//     {0, 0, 1, 1, 0, 1, 1},
//     {0, 0, 0, 0, 1, 0, 0},
//     {0, 0, 0, 0, 1, 0, 0},
// };

void BFS(int graph[100][100], int nodes, int startNode)
{
    printf("%d ", startNode);
    visited[startNode] = 1;

    do
    {
        int node = queue[++front];
        for (int j = 0; j < nodes; j++)
        {
            if (graph[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                queue[++rear] = j;
            }
        }
    } while (front != rear);
}

int main()
{
    int nodes;
    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    // fill in the adjacency matrix
    printf("Fill in the values of the adjacency matrix of the graph: ");
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            scanf("%d", &graph[i][j]);

    BFS(graph, nodes, 0);

    return 0;
}