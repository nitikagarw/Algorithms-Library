//Program to implement PRIM's MST Algorithm using Adjacency matrix representation of graphs
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#define V 5

void PrimMST( int graph[V][V]);
int MinKey(int key[], bool mstSet[]);
void printMST(int parent[], int n, int graph[V][V]);

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},{2, 0, 3, 8, 5},{0, 3, 0, 0, 7},{6, 8, 0, 0, 9},{0, 5, 7, 9, 0},};


    PrimMST(graph);
    return 0;
}

void PrimMST( int graph[V][V])
{
    int key[V];     //key values used to pick minimum weight edge in cut
    bool mstSet[V]; //to include set of vertices not yet included in MST
    int parent[V];  //Array to store constructed MST
    int i, k , v;


    //Initialisation
    for(i=0; i<V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -2;
    }

    //Including First vertex in MST
    key[0] = 0;
    parent[0] = -1; //First vertex is the Root of MST

    for(k=0; k<V-1; k++)
    {
        int u = MinKey(key, mstSet);

        mstSet[u] = true;  //adding the vertex 'u' to mstSet

        //update the key and parent indices of vrtices adjacent to 'u'
        for (v=0; v<V; v++)
        {
            //graph[u][v] is non-zero only for adjacent vertices of 'u'
            //mstSet[v] is false only for vertices not yet included in MST
            //update the key only if graph[u][v]<key[v]
            if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }

        }
    }

    printMST(parent, V, graph);
}

//Function to find the vertex with minimum value key not yet included in MST
int MinKey(int key[], bool mstSet[])
{
    int minimum = INT_MAX , min_index; //initialise the minimun value
    int v ;

    for(v=0; v<V ; v++)
    {
        if(mstSet[v] == false && key[v] < minimum)
        {
            minimum = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int n, int graph[V][V])
{
    int i ;
    printf("EDGE    WEIGHT\n");
    for(i = 1 ; i <V ; i++)
        printf("%4d -- %4d    %3d\n", parent[i], i , graph[i][parent[i]]);

}











