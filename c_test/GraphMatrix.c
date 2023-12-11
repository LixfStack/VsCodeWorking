#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int matrix[MAX_VERTICES][MAX_VERTICES];
} GraphMatrix;

void initGraphMatrix(GraphMatrix *graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->matrix[i][j] = 0;
        }
    }
}

void addEdgeMatrix(GraphMatrix *graph, int from, int to) {
    if (from >= 0 && from < graph->vertices && to >= 0 && to < graph->vertices) {
        graph->matrix[from][to] = 1;
        graph->matrix[to][from] = 1; // For undirected graph
    }
}

void printGraphMatrix(GraphMatrix *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    GraphMatrix myGraph;
    initGraphMatrix(&myGraph, 4);

    addEdgeMatrix(&myGraph, 0, 1);
    addEdgeMatrix(&myGraph, 0, 2);
    addEdgeMatrix(&myGraph, 0, 3);
    addEdgeMatrix(&myGraph, 1, 2);
    
    printGraphMatrix(&myGraph);

    system("pause");
}
