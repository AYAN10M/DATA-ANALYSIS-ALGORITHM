#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printSoln(int vertices, int color[vertices])
{
    printf("Solution Exists: Following are the assigned colors:\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
}

int isSafe(int vertices, int edges, int graph[vertices][vertices], int noOfColor, int color[vertices], int currentVertices, int trialColor)
{
    for (int i = 0; i < vertices; i++)
    {
        if (graph[currentVertices][i] == 1 && trialColor == color[i])
        {
            return 0;
        }
    }
    return true;
}

int graphColoringUtil(int vertices, int edges, int graph[vertices][vertices], int color[vertices], int noOfColor, int currentVertices)
{
    if (currentVertices == vertices)
    {
        return 1;
    }

    for (int trialColor = 1; trialColor <= noOfColor; trialColor++)
    {
        if (isSafe(vertices, edges, graph, noOfColor, color, currentVertices, trialColor) == 1)
        {
            color[currentVertices] = trialColor;

            if (graphColoringUtil(vertices, edges, graph, color, noOfColor, currentVertices + 1) == 1)
            {
                return 1;
            }

            color[currentVertices] = 0;
        }
    }
    return 0;
}

int graphColoring(int vertices, int edges, int graph[vertices][vertices], int noOfColor)
{
    // An array to keep track of the whether a given vertex is coloured or not
    int color[vertices];

    for (int i = 0; i < vertices; i++)
    {
        color[i] = 0;
    }

    if (graphColoringUtil(vertices, edges, graph, color, noOfColor, 0) == 0)
    {
        printf("Solution does not exist");
        return -1;
    }

    printSoln(vertices, color);
    return 1;
}

int main()
{
    int vertices, edges;
    printf("Enter the number of vertices:\t");
    scanf("%d", &vertices);

    printf("Enter the number of edges:\t");
    scanf("%d", &edges);

    int graph[vertices][vertices];

    // initialization of the graph
    // -1 indicates that two vertices are not connected
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        printf("\nEnter the vertices details for edge %d:\n", i + 1);
        printf("\tSource vertex:\t");
        scanf("%d", &src);
        printf("\tDestination Vertex:\t");
        scanf("%d", &dest);

        graph[src][dest] = graph[dest][src] = 1;
    }

    int noOfColor;
    printf("Enter the number of color:\t");
    scanf("%d", &noOfColor);

    graphColoring(vertices, edges, graph, noOfColor);
}