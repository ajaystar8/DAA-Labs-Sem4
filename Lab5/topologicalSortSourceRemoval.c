#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int visited[100] = {0};
int inDegree[100] = {0};
int count = 0;

void topologicalSortSourceRemoval(int graph[100][100], int nodes)
{
	// updating the inDegree array
	for (int i = 0; i < nodes; i++)
		for (int j = 0; j < nodes; j++)
			inDegree[i] += graph[j][i];

	printf("The topological sort of the array is: \n");

	for (int i = 0; i < nodes; i++)
	{
		for (int k = 0; k < nodes; k++)
		{
			if (inDegree[k] == 0 && visited[k] == 0)
			{
				printf("%d ", k);
				visited[k] = 1;

				for (int j = 0; j < nodes; j++)
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

	printf("Enter the number of nodes:\n");
	scanf("%d", &n);

	printf("Enter the adjacency matrix: \n");

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	topologicalSortSourceRemoval(graph, n);
}