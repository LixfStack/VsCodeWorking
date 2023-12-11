#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    int vertices;
    Node *adjList[MAX_VERTICES];
} GraphList;

void initGraphList(GraphList *graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
}

void addEdgeList(GraphList *graph, int from, int to) {
    if (from >= 0 && from < graph->vertices && to >= 0 && to < graph->vertices) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = to;
        newNode->next = graph->adjList[from];
        graph->adjList[from] = newNode;

        // For undirected graph, add the reverse edge
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = from;
        newNode->next = graph->adjList[to];
        graph->adjList[to] = newNode;
    }
}

void printGraphList(GraphList *graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->vertices; i++) {
        Node *current = graph->adjList[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    GraphList myGraph;
    initGraphList(&myGraph, 4);

    addEdgeList(&myGraph, 0, 1);
    addEdgeList(&myGraph, 0, 2);
    addEdgeList(&myGraph, 0, 3);
    addEdgeList(&myGraph, 1, 2);
    
    printGraphList(&myGraph);

    system("pause");
}
