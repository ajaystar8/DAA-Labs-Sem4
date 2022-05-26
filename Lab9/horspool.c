#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int shiftTable[500];
char p[100];
char src[100];
int kc = 0; 

void shiftTableGenerate(char p[100])
{
    int m = strlen(p);

    for (int i = 0; i < 500; i++)
        shiftTable[i] = m;

    for (int j = 0; j < m - 1; j++)
        shiftTable[p[j]] = m - 1 - j;
}

int horspoolMatching(char src[100], char p[100])
{
    int m = strlen(p);
    int n = strlen(src);

    int i = m - 1;

    shiftTableGenerate(p);

    while (i < n)
    {
        int flag = 0; 
        int k = 0;
        
        while ((k <= m - 1) && (p[m - 1 - k] == src[i - k])){
            flag = 1;
            kc++;
            k++;
        }

        if(!flag)
            kc++;

        if (k == m)
            return i - m + 1;

        else
            i += shiftTable[src[i]];
    }

    return -1;
}

int main()
{
    int index;
    printf("Enter TEXT string: ");
    scanf("%s", src);

    printf("Enter PATTERN string: ");
    scanf("%s", p);

    index = horspoolMatching(src, p);

    if (index == -1)
        printf("Pattern not found!\n");

    else
        printf("Pattern found starting at index %d\n", index);

    printf("Comparisons: %d\n", kc);
    return 0;
}
