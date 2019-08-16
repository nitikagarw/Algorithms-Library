//Program to implement ADJACENCY LIST REPRESENTATION of a graph(UNdirected)

#include<stdio.h>
#include<stdlib.h>

struct AdjListNode                             //To represent the node of an adjacency list
                 {
                     int dest;
                     struct AdjListNode *next;
                 };

struct AdjList                                 //To represent adjacency list
             {
                  struct AdjListNode *head;
             };
struct Graph                                   // To represent the graph with V vertices
           {
               int V;
               struct AdjList *Array;
           };

struct Graph* CreateGraph(int V);
void AddEdge(struct Graph *graph, int src, int dest);
struct AdjListNode* NewAdjlistNode(int value);
void printGraph(struct Graph *graph);

int main()
{
    int V = 5;
    struct Graph *graph = CreateGraph(V);

    //Adding edges to graph
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 4);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 4);

    //print the adjacency list representatin of the above graph
    printGraph(graph);

    return 0;
}

struct Graph* CreateGraph(int V)
{
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->Array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    int i ;
    for(i=0; i<V ; i++)
    {
        graph->Array[i].head = NULL;
    }
    return graph;
}

struct AdjListNode* NewAdjListNode(int value)
{
    struct AdjListNode *newNode;
    newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = value;
    newNode->next = NULL;
    return newNode;
}

void AddEdge(struct Graph *graph, int src, int dest)
{
    //Adding an edge from src to dest
    struct AdjListNode *newnode ;
    newnode = NewAdjListNode(dest);
    newnode->next = graph->Array[src].head;
    graph->Array[src].head = newnode;

    //since the graph is undirected , adding an edge from dest to src
    newnode = NewAdjListNode(src);
    newnode->next = graph->Array[dest].head;
    graph->Array[dest].head = newnode;

}

void printGraph(struct Graph *graph)
{
    int v;
    struct AdjListNode *tmphead;
    for(v=0; v<graph->V; v++)
    {
        tmphead = graph->Array[v].head;
        printf("Adjacency list of vertex %d : \n Head",v);
        while(tmphead!=NULL)
        {
            printf(" -> %d", tmphead->dest);
            tmphead = tmphead->next;
        }
        printf("\n");
    }
}











