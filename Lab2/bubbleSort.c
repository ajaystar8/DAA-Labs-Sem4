#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
	int temp;
	int opcount = 0;
	int swap = 0;

	for (int i = 0; i < n - 1; i++)
	{
		swap = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			opcount++;
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swap = 1;
			}
		}

		if (!swap)
			break;
	}

	printf("\n");
	printf("opcount: %d : ", opcount);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

int main()
{

	// for best case
	for (int i = 0; i < 20; i++)
	{
		int *temp = (int *)calloc((i + 1), sizeof(int));
		for (int j = 0; j < i + 1; j++)
		{
			temp[j] = j + 1;
		}
		bubbleSort(temp, i + 1);
	}

	// for worst case
	printf("\n");
	printf("Worst Cases: \n");

	for (int i = 0; i < 20; i++)
	{
		int *temp2 = (int *)calloc((i + 1), sizeof(int));
		for (int j = 19; j > 0; j--)
		{
			temp2[20 - j - 1] = j + 1;
		}
		bubbleSort(temp2, i + 1);
	}

	return 0;
}