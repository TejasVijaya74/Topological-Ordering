/* Design and implement C\C++ program to obtain the topological ordering of vertices in a given graph*/
#include <stdio.h>
#define MAX 10

void fn_topological(int a[MAX][MAX], int n);

int main(void)
{
    int a[MAX][MAX], n;
    int i, j;
    printf("Topological sorting algorithm \n");
    printf("\n Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    fn_topological(a, n);
    printf("\n");
    return 0;
}

void fn_topological(int a[MAX][MAX], int n)
{
    int in[MAX], out[MAX], stack[MAX], top = -1;
    int i, j, k = 0;
    for (i = 0; i < n; i++)
    {
        in[i] = 0;
        for (j = 0; j < n; j++)
            if (a[j][i] == 1) // Changed from a[i][j] to a[j][i]
                in[i]++;
    }
    while (1)
    {
        for (i = 0; i < n; i++)
        {
            if (in[i] == 0)
            {
                stack[++top] = i;
                in[i] = -1;
            }
        }
        if (top == -1)
            break;
        out[k] = stack[top--];
        for (i = 0; i < n; i++)
        {
            if (a[out[k]][i] == 1)
                in[i]--;
        }
        k++;
    }
    printf("Topological sorting (JOB SEQUENCE) is:\n");
    for (i = 0; i < k; i++) // Changed from i < 1 to i < k
        printf("%d ", out[i] + 1);
}