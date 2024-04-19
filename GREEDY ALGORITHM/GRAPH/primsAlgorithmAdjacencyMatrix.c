#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    Abouts limits.h
    The <limits.h> header file in C programming defines the characteristics of various variable types. The values are implementation specific, but may not be of lower magnitude than certain specified values in a conforming C implementation.

    For example, the minimum value for an object of type char is -127, and the maximum value is 127. These values are defined in the <limits.h> header file.

    The <limits.h> header file also defines the following macros:
        INT_MIN: The minimum value for an object of type int.
        INT_MAX: The maximum value for an object of type int.
        LONG_MIN: The minimum value for an object of type long.
        LONG_MAX: The maximum value for an object of type long.

    These macros can be used to determine the range of values that can be stored in a variable of a given type.
*/

// Function prototypes
int primsMST(int v, int edges[][v], int weight[][v]);

int main()
{
    // v is the number of vertex and e is the number of edge

    int v, e;
    printf("Enter the number of vertices:\t");
    scanf("%d", &v);
    printf("Enter the number of edges:\t");
    scanf("%d", &e);

    int edges[v][v];
    int weight[v][v];

    // Initializing the adjacency matrix and weight matrix
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = weight[i][j] = 0;
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

    int minCost = primsMST(v, edges, weight);
    printf("Minimum Cost for traversing the graph is: %d\n", minCost);
    return 0;
}

// Prim's algorithm for minimum spanning tree
int primsMST(int v, int edges[][v], int weight[][v])
{
    int selected[v]; // Array to track selected vertices
    int parent[v];   // Array to store parent of each vertex in MST
    int minCost = 0; // Total weight of MST

    // Initialize selected[] and parent[] arrays
    for (int i = 0; i < v; i++)
    {
        selected[i] = 0; // No vertex is selected initially
        parent[i] = -1;  // Initialize parent of each vertex as -1
    }

    // Start with the first vertex
    selected[0] = 1;

    // Loop to find MST with (v-1) edges beacuse we had already taken inputted of our 1st vertex i.e selected[0] = 1
    for (int count = 0; count < v - 1; count++)
    {
        int minWeight = INT_MAX;

        // u is the selected vertex, w is its neighbor
        int u, w;

        // Find the edge with minimum weight that connects a selected vertex to an unselected vertex
        for (int i = 0; i < v; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < v; j++)
                {
                    if (!selected[j] && edges[i][j] && weight[i][j] < minWeight)
                    {
                        minWeight = weight[i][j];
                        u = i;
                        w = j;
                    }
                }
            }
        }

        // Add the selected edge to MST
        selected[w] = 1;
        parent[w] = u;
        minCost += minWeight;
    }

    return minCost;
}