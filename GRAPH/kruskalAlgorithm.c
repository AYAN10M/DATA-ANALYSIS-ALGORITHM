/* C Program On Krushkal's Algorithm */
// Applied for weighted and undirected graph

#include <stdio.h>
#include <stdlib.h>

// basic structure of a edge of a graph
// node1 -> Source, node2 -> destination, wt = weight
typedef struct
{
    int node1;
    int node2;
    int wt;
} edge;

// bubble sort is taking place
// sorting the edge in ascending order, as we know Kruskal Algorithm is a minimization technique
// s is the no of edges
void sortedges(edge a[], int s)
{
    int i, j;
    edge temp;
    for (i = 1; i <= s; i++)
        for (j = i; j <= s; j++)
            if (a[i].wt > a[j].wt)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

// function to check whether the vertex are forming cycle or not
// i and j are source vertex and destination vertex respectively
int checkcycle(int p[], int i, int j)
{
    int v1, v2, b = 0;
    v1 = i;
    v2 = j;
    printf("v1 = %d v2 = %d", v1, v2);
    printf("\t\t\n\np[i]=%d", p[i]);
    while (p[i] > -1)
    {
        printf("\np[i]=%d", p[i]);
        i = p[i];
        printf("i=%d\t", i);
    }

    printf("\t\t\n\np[j]=%d", p[j]);
    while (p[j] > -1)
    {
        printf("\np[j]=%d", p[j]);
        j = p[j];
        printf("j=%d\t i=%d\t", j, i);
    }
    
    if (i != j)
    {
        p[j] = i;
        printf("p[j]=%d\t", p[j]);
        printf("\t\t%d %d\n", v1, v2);
        // b=1;
        return 1;
        // return b;
    }
    // b=0;
    return 0;
}
int main()
{
    printf("KRUSKAL's ALGORITHM\n");
    // declaring array of type edge to store the edges
    edge e[100];
    int parent[100];

    // n is number of vertex
    // m is number of edges
    int n, i, j, m, k = 1, cost = 0, b, t = 1;

    printf("Enter number of nodes:\t");
    scanf("%d", &n);

    // all are instialized to -1
    for (i = 1; i <= n; i++)
    {
        parent[i] = -1;
    }

    i = 1;
    printf("Enter number of edges:\t");
    scanf("%d", &m);

    // for inputing the edge info i.e Source vertex, Destination Vertex
    printf("\nEnter the details of vertex:\n");
    for (i = 1; i <= m; i++)
    {
        printf("\nEdge number :\t%d", i);
        printf("\tSource Vertex:\t");
        scanf("%d", &e[i].node1);
        printf("\tDestination Vertex:\t");
        scanf("%d", &e[i].node2);
        printf("\tWeight of given vertex %d ------ %d :\t", e[i].node1, e[i].node2);
        scanf("%d", &e[i].wt);
    }

    // sorting the edge in ascending order
    sortedges(e, m);

    printf("\n\nEdges of the tree\n");
    i = 1;

    // checking for cycle.
    while (k < m)
    {
        // printf("n=%d k=%d",n,k);
        b = checkcycle(parent, e[i].node1, e[i].node2);
        if (b != 0)
        {
            printf("e[i].node1 = %d    e[i].node2 = %d\n\n", e[i].node1, e[i].node2);
            k++;
            cost = cost + e[i].wt;
            i++;
            t++;
            printf("\n\ncost if=%d e[i].wt=%d", cost, e[i].wt);
        }
        else
        {

            k++;
            i++;
            // checkcycle(parent,e[i].node1,e[i].node2);
            // printf("b=%d",b);
            // if(b!=0)
            // cost=cost+e[i].wt;
            // printf("\n\ncost else=%d",cost);
        }
    }
    printf("cost = %d", cost);
    printf("\n\nk=%d", k);
}