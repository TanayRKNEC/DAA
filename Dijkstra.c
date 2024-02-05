#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define V 6

int minDistance(float dist[], int visited[])
{
    float min = INFINITY; 
    int min_index;
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(float graph[V][V], int start)
{
    float dist[V];
    int visited[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INFINITY;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (visited[v] == 0 && graph[u][v] && dist[u] != INFINITY && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Minimum Distance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d %d\n", i, (int)dist[i]);
    }
}

int main()
{
    float graph[V][V] = {
        {0, 8, 5, INFINITY, INFINITY, 50},
        {INFINITY, 0, INFINITY, 10, INFINITY, INFINITY},
        {INFINITY, INFINITY, 0, 20, 30, INFINITY},
        {INFINITY, INFINITY, INFINITY, 0, INFINITY, 9},
        {INFINITY, INFINITY, INFINITY, INFINITY, 0, 15},
        {INFINITY, INFINITY, INFINITY, INFINITY, 12, 0}};

    dijkstra(graph, 0);

    return 0;
}
