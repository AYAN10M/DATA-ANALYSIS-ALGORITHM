#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int kruskalAlgo(int v, int edges[v][v], int weight[v][v])
{
    int visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = -1;
    }

    int u, w, minCost = 0;

    for (int count = 0; count < v - 1; count++)
    {
        int min = INT_MAX;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (weight[i][j] < min && visited[j] == -1)
                {
                    min = weight[i][j];
                    u = i;
                    w = j;
                }
            }
        }

        if (visited[u] == -1 || visited[w] == -1)
        {
            visited[w] = u;
            minCost += min;
        }
        weight[u][w] = weight[w][u] = INT_MAX;
    }


    return minCost;
}

int main()
{
    int v, e;
    printf("Enter the number of vertices:\t");
    scanf("%d", &v);
    printf("Enter the number of edges:\t");
    scanf("%d", &e);

    // Edge case: No vertices
    if (v == 0)
    {
        printf("The graph has no vertices.\n");
        return 0;
    }

    // Edge case: Single vertex
    if (v == 1)
    {
        printf("The graph has only one vertex.\n");
        return 0;
    }

    int edges[v][v];
    int weight[v][v];

    // Initializing the adjacency matrix and weight matrix
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = weight[i][j] = INT_MAX;
        }
    }

    // Inputting the edges and weights
    for (int i = 0; i < e; i++)
    {
        printf("\nEdge no:\t%d\n", i + 1);
        int src, dest, wt;
        printf("Source vertex:\t");
        scanf("%d", &src);
        printf("Destination vertex:\t");
        scanf("%d", &dest);
        printf("Weight of the edge between %d and %d:\t", src, dest);
        scanf("%d", &wt);

        src--;  // Adjusting for 0-based indexing
        dest--; // Adjusting for 0-based indexing

        edges[src][dest] = edges[dest][src] = 1;
        weight[src][dest] = weight[dest][src] = wt;
    }

    int cost = kruskalAlgo(v, edges, weight);
    
    if (cost != -1)
    {
        printf("The minimum cost is :\t%d", cost);
    }

    return 0;
}
