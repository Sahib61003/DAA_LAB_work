#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear search function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found in the array
}

// Function to analyze time complexity
void analyzeTimeComplexity(int arr[], int n, int key) {
    clock_t start_time, end_time;
    double time_taken;

    // Best-case scenario
    start_time = clock();
    int best_case = linearSearch(arr, n, arr[0]); // Searching for the first element
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Best Case - Time taken: %f seconds\n", time_taken);

    // Worst-case scenario
    start_time = clock();
    int worst_case = linearSearch(arr, n, key + 1); // Searching for an element not in the array
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Worst Case - Time taken: %f seconds\n", time_taken);

    // Average-case scenario
    start_time = clock();
    int avg_case = linearSearch(arr, n, key); // Searching for a random element
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Average Case - Time taken: %f seconds\n", time_taken);
}

int main() {
    srand(time(NULL)); // Seed for random numbers

    // Array size and key
    int n = 100000; // Modify this for different array sizes
    int arr[n];

    // Filling the array with random values
    for (int j = 0; j < n; j++) {
        arr[j] = rand() % 1000; // Generating random numbers between 0 to 999
    }

    int key = rand() % 1000; // Generating a random key to search

    printf("Array Size: %d\n", n);
    analyzeTimeComplexity(arr, n, key);

    return 0;
}
