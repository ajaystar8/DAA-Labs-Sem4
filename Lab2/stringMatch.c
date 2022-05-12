#include <stdio.h>
#include <stdlib.h>

int stringMatch(char *str, char *substr, int n, int m)
{
	int opcount = 0;
	int j = 0;
	int found = 1, pos = 0;
	for (int i = 0; i <= n - m; i++)
	{
		for (j = 0; j < m; j++)
		{
			opcount++;
			if (str[i + j] != substr[j])
			{
				found = 0;
				break;
			}
		}
		if (j == m)
		{
			pos = i;
			break;
		}
	}
	if (found)
		return pos;
	else
	{
		printf(" m+n: %d : opcount: %d\n", m + n, opcount);
		return -1;
	}

	return -1;
}

int main()
{
	// worst case scenario: Pattern Not found!!
	char main_string[21] = "aaaaaaaaaaaaaaaaaaaa\0";

	for (int i = 0; i < 20; i++)
	{
		if (i == 0)
		{
			char *search_string = (char *)calloc(i + 1, sizeof(char));
			search_string[i] = 'b';
			stringMatch(main_string, search_string, 20, i + 1);
			continue;
		}
		// generates: ab/aab/aaab/aaaab...
		char *search_string = (char *)calloc(i + 1, sizeof(char));
		for (int j = 0; j <= i; j++)
		{
			if (j == i)
			{
				search_string[j] = 'b';
				continue;
			}
			search_string[j] = 'a';
		}
		stringMatch(main_string, search_string, 20, i + 1);
	}
}