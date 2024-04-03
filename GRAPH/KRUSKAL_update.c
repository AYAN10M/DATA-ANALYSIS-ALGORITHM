#include <stdio.h>

typedef struct
{
    int node1;
    int node2;
    int wt;
} edge;

// Function to sort edges based on weight
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

// Function to check if adding an edge will create a cycle
int checkcycle(int p[], int i, int j)
{
    int v1, v2;
    v1 = i;
    v2 = j;
    while (p[i] > -1)
        i = p[i];
    while (p[j] > -1)
        j = p[j];
    if (i != j)
    {
        p[j] = i;
        return 1; // Indicates the edge doesn't create a cycle
    }
    return 0; // Indicates the edge creates a cycle
}

int main()
{
    edge e[100];
    int parent[100];
    int n, i, m, k = 1, cost = 0, b;

    printf("KRUSKAL's ALGORITHM\n");
    printf("Enter number of nodes\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        parent[i] = -1;

    printf("Enter number of edges\n");
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
    {
        printf("Enter an edge and weight\n");
        scanf("%d %d %d", &e[i].node1, &e[i].node2, &e[i].wt);
    }
    sortedges(e, m);
    printf("\n\nEdges of the tree\n");

    i = 1;
    while (k < m)
    {
        b = checkcycle(parent, e[i].node1, e[i].node2);
        if (b != 0)
        {
            printf("Added edge: %d - %d (Weight: %d)\n", e[i].node1, e[i].node2, e[i].wt);
            k++;
            cost += e[i].wt;
        }
        i++;
    }
    printf("Total cost of the minimum spanning tree: %d\n", cost);

    return 0;
}
