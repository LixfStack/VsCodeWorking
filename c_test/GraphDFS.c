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
} Graph;

void initGraph(Graph *graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
}

void addEdge(Graph *graph, int from, int to) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = to;
    newNode->next = graph->adjList[from];
    graph->adjList[from] = newNode;
}

void DFSUtil(Graph *graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node *current = graph->adjList[vertex];
    while (current != NULL) {
        int neighbor = current->data;
        if (!visited[neighbor]) {
            DFSUtil(graph, neighbor, visited);
        }
        current = current->next;
    }
}

void DFS(Graph *graph, int start) {
    int visited[MAX_VERTICES] = {0};
    DFSUtil(graph, start, visited);
}


void BFS(Graph *graph, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[start] = 1;
    printf("%d ", start);
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        Node *temp = graph->adjList[current];

        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                printf("%d ", neighbor);
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
}

int main() {
    Graph myGraph;
    initGraph(&myGraph, 6);

    addEdge(&myGraph, 0, 1);
    addEdge(&myGraph, 0, 2);
    addEdge(&myGraph, 1, 3);
    addEdge(&myGraph, 2, 4);
    addEdge(&myGraph, 2, 5);

    printf("DFS starting from vertex 0:\n");
    DFS(&myGraph, 0);
    printf("\n");
    printf("BFS starting from vertex 0:\n");
    BFS(&myGraph, 0);

    system("pause");
}
