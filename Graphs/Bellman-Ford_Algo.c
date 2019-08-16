//Program to implement BELLMAN-FORD ALGORITHM
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Edge
          {
              int src,dest,weight;
          };

struct Graph
           {
               int V,E;
               struct Edge *edge;
           };

struct Graph* CreateGraph(int V, int E);
void BellmanFord(struct Graph *graph, int src);
void printSol(int dist[], int n);
int main()
{
    int V = 5;
    int E = 8;

    struct Graph *graph = CreateGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    BellmanFord(graph, 0);
    return 0;
}

struct Graph* CreateGraph(int V, int E)
{
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
}

void BellmanFord(struct Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int i,j,u,v, weight;

    for(i=0; i<V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for(i=0; i<V-1; i++)
    {
        for(j=0; j<E; j++)
        {
            u = graph->edge[j].src;
            v = graph->edge[j].dest;
            weight = graph->edge[j].weight;
            if(dist[v] > dist[u] + weight)
                dist[v] = dist[u] + weight;
        }
    }

    for(i=0; i<E; i++)
    {
        u = graph->edge[i].src;
        v = graph->edge[i].dest;
        weight = graph->edge[i].weight;
        if(dist[v] > dist[u] + weight)
        {
            printf("Graph contains NEGATIVE WEIGHT CYCLE.\nShortest Paths are not well-defined.");
            //return;
        }
    }

    printSol(dist, V);
    return;
}

void printSol(int dist[], int n)
{
    int i;
    printf("Vertex\tDistance from Source\n");
    for(i=0; i<n; i++)
        printf("%5d\t%10d\n", i, dist[i]);
    return;
}




