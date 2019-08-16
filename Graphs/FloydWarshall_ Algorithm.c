//Program to implement FLOYD WARSHALL ALGORITHM
#include<stdio.h>
#include<stdlib.h>
#define V 4
#define INF 999999

void FloydWarshall(int graph[V][V]);
void PrintSol(int dist[V][V]);
int main()
{
    int graph[V][V] = {{0, 5, INF, 10},{INF, 0, 3, INF},{INF, INF, 0, 1},{INF, INF, INF, 0}};

    //Print the solution matrix
    FloydWarshall(graph);
    return 0;
}

//Solves All-Pairs Shortest Path problem using Floyd Warshall Algorithm
void FloydWarshall(int graph[V][V])
{
    int dist[V][V], i, j, k;    //dist[V][V] is the solution matrix

    //Initialising the solution matrix same as the input matrix
    for(i=0; i<V; i++)
    {
        for(j=0; j<V; j++)
            dist[i][j] = graph[i][j];
    }

    for(k=0; k<V; k++)
    {
        for(i=0; i<V; i++)
        {
            for(j=0; j<V; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                   dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    //Print the shortest distance matrix
    PrintSol(dist);
}

void PrintSol(int dist[V][V])
{
    int i, j;
    printf("\nMatrix showing Shortest Distances between All Pairs of vertices :\n\n");
    for(i=0; i<V; i++)
    {
        for(j=0; j<V; j++)
        {
            if(dist[i][j] == INF)
                printf("%5s", "INF");
            else
                printf("%5d", dist[i][j]);
        }
        printf("\n\n");
    }
}



