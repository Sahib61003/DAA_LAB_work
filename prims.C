#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>

#define V 5

int find_min_key(int key[], int visited[], int n) {
    int min_key = INT_MAX, min_index;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && key[i] < min_key) {
            min_key = key[i];
            min_index = i;
        }
    }

    return min_index;
}

void prims_algorithm(int adjacency_matrix[][V], int n) {
    int key[V];
    int parent[V];
    int visited[V];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    clock_t start_time = clock();

    for (int i = 0; i < n - 1; i++) {
        int min_index = find_min_key(key, visited, n);
        visited[min_index] = 1;

        for (int j = 0; j < n; j++) {
            if (adjacency_matrix[min_index][j] != 0 && visited[j] == 0 && adjacency_matrix[min_index][j] < key[j]) {
                parent[j] = min_index;
                key[j] = adjacency_matrix[min_index][j];
            }
        }
    }

    clock_t end_time = clock();
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Edges in the Minimum Cost Spanning Tree:\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d\n", parent[i], i);
    }

    printf("Time taken: %f seconds\n", cpu_time_used);
}

int main() {
    int adjacency_matrix[][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    prims_algorithm(adjacency_matrix, V);
    printf("\nSahib Preet Singh 00713211622 AI-ML");
    return 0;
}
