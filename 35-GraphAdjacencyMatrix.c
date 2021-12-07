#include <stdio.h>

#define MAX_VERTICES 10

void createGraph(int adj_matrix[MAX_VERTICES][MAX_VERTICES], int num_of_vertices)
{
    for (int i = 0; i < num_of_vertices; i++)
    {
        printf("Enter the number of neighbours of %d: ", i);
        int n;
        scanf("%d", &n);

        for (int j = 1; j <= n; j++)
        {
            printf("Enter the neighbour %d of %d: ", j, i);
            int val;
            scanf("%d", &val);

            adj_matrix[i][val] = 1;
        }
    }
}

void displayGraph(int adj_matrix[MAX_VERTICES][MAX_VERTICES], int num_of_vertices)
{
    for (int i = 0; i < num_of_vertices; i++)
    {
        printf("The neighbours of %d are: ", i);
        for (int j = 0; j < num_of_vertices; j++)
        {
            if (adj_matrix[i][j] == 1)
            {
                printf("%d  ", j);
            }
        }
        printf("\n");
    }
}

int main()
{
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    int num_of_vertices;
    scanf("%d", &num_of_vertices);

    for (int i = 0; i < num_of_vertices; i++)
        for (int j = 0; j < num_of_vertices; j++)
            adj_matrix[i][j] = 0;

    createGraph(adj_matrix, num_of_vertices);
    printf("\nThe graph is: \n");
    displayGraph(adj_matrix, num_of_vertices);
    return 0;
}