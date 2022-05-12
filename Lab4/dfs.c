#include <stdio.h>
#include <stdlib.h>

int pushStack[100];
int pushStackTop = -1;
int popStack[100];
int popStackTop = -1;

// adjacency matrix of the graph
int graph[100][100];
int visited[100] = {0};
int pushOrder[100] = {0};
// int graph[7][7] = {
//     {0, 1, 1, 1, 0, 0, 0},
//     {1, 0, 1, 0, 0, 0, 0},
//     {1, 1, 0, 1, 1, 0, 0},
//     {1, 0, 1, 0, 1, 0, 0},
//     {0, 0, 1, 1, 0, 1, 1},
//     {0, 0, 0, 0, 1, 0, 0},
//     {0, 0, 0, 0, 1, 0, 0},
// };

void DFS(int graph[100][100], int nodes, int startNode)
{
    printf("%d  ", startNode);
    pushStack[++pushStackTop] = startNode;
    visited[startNode] = 1;

    for (int i = 0; i < nodes; i++)
    {
        if (graph[startNode][i] == 1 && !visited[i])
            DFS(graph, nodes, i);
    }
    popStack[++popStackTop] = startNode;
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

    DFS(graph, nodes, 0);

    printf("\nPush Order: ");

    for (int i = 0; i <= pushStackTop; i++)
        printf("%d ", pushStack[i]);

    printf("\nPop Order: ");
    for (int i = 0; i <= popStackTop; i++)
        printf("%d ", popStack[i]);

    return 0;
}