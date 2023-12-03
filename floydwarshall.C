#include <stdio.h>

// Define infinity as a large value
#define INF 99999
#define V 4  // Number of vertices in the graph

// Function to print the solution matrix
void printSolution(int dist[][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd Warshall algorithm function
void floydWarshall(int graph[][V]) {
    int dist[V][V];

    // Initialize the solution matrix with the same values as the input graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update dist[][] with the shortest path between every pair of vertices
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the solution
    printSolution(dist);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, INF, 0, 3},
        {2, 0, INF, INF},
        {0, 7, INF, 1},
        {4, INF, INF, 2}
    };
    printf("\nSahib Preet Singh 00713211621 AI-ML");
    printf("\n\n");
    // Call the Floyd-Warshall algorithm function
    floydWarshall(graph);

    return 0;
}