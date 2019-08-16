//Program to implement DIJKSTRA's Algorithm using Adjacency Matrix representation of graphs
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#define V 9

void dijkstra(int graph[V][V], int src);
int MinDist(int dist[V], bool sptSet[V]);
void printSol(int dist[V]);
int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},{4, 0, 8, 0, 0, 0, 0, 11, 0},{0, 8, 0, 7, 0, 4, 0, 0, 2},{0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},{0, 0, 4, 0, 10, 0, 2, 0, 0},{0, 0, 0, 14, 0, 2, 0, 1, 6},{8, 11, 0, 0, 0, 0, 1, 0, 7},{0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}

void dijkstra(int graph[V][V], int src)
{
    bool sptSet[V];
    int dist[V];
    int v, i;

    for(v=0; v<V; v++)
    {
        dist[v] = INT_MAX;
        sptSet[v] = false;
    }
    dist[src]= 0;

    for(i=0; i<V; i++)
    {
        int u = MinDist(dist, sptSet);
        sptSet[u] = true;

        for(v=0; v<V; v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[v]>dist[u]+graph[u][v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSol(dist);
    return;
}

int MinDist(int dist[V], bool sptSet[V])
{
    int minimum = INT_MAX;
    int min_index, i;
    for(i=0; i<V; i++)
    {
        if(!sptSet[i] && dist[i]<=minimum)
        {
            minimum= dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printSol(int dist[V])
{
    int i;
    printf("Vertex    Distance from Source\n");
    for(i=0; i<V; i++)
    {
        printf("%6d    %10d\n", i, dist[i]);
    }
    return;
}






