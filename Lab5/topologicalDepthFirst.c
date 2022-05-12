#include <stdio.h>
#include <stdlib.h>

int popStack[100];
int popStackTop = -1;

// adjacency matrix of the graph
int graph[100][100];
int visited[100] = {0};
int pushOrder[100] = {0};

void DFS(int graph[100][100], int nodes, int startNode)
{
    visited[startNode] = 1;

    for (int i = 0; i < nodes; i++)
    {
        if (graph[startNode][i] == 1 && !visited[i])
            DFS(graph, nodes, i);
    }
    // this line of code executes as soon as the control reaches a dead end
    // until then, the control stays in the for loop only
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

    // topological sort through DFS technique is the reverse of the pop order
    printf("\nTopological sort of the following graph is: ");
    for (int i = popStackTop; i >= 0; i--)
        printf("%d ", popStack[i] + 1);

    return 0;
}