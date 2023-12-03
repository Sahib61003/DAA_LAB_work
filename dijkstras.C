
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define MAX_VERTICES 100

int minDistance(int dist[], int sptSet[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[], int vertices) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < vertices; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int src) {
    int dist[MAX_VERTICES]; // The output array dist[i] holds the shortest distance from src to i
    int sptSet[MAX_VERTICES]; // sptSet[i] will be true if vertex i is included in the shortest path tree or the shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance from the source vertex to itself is always 0
    dist[src] = 0;

    // Start timer
    clock_t start = clock();

    // Find the shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet, vertices);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update the dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < vertices; v++) {
            // Update dist[v] only if it's not in the sptSet, there's an edge from u to v,
            // and the total weight of the path from src to v through u is less than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Stop timer
    clock_t end = clock();

    // Calculate elapsed time in seconds
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the constructed distance array
    printSolution(dist, vertices);

    printf("Time complexity: %f seconds\n", elapsed_time);
}

int main() {
    int numVertices;

    // Input for the Dijkstra's algorithm
    printf("Enter the number of vertices for the graph: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;

    // Input for the source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    // Run Dijkstra's algorithm
    dijkstra(graph, numVertices, src);
    printf("\nSahib Preet Singh 00713211621 AI-ML");
    return 0;
}
