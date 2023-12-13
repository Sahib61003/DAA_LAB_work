#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary search function
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to analyze time complexity
void analyzeTimeComplexity(int arr[], int n, int key) {
    clock_t start_time, end_time;
    double time_taken;

    // Sorting the array (Binary search requires a sorted array)
    qsort(arr, n, sizeof(int), compare);

    // Best-case scenario
    start_time = clock();
    int best_case = binarySearch(arr, 0, n - 1, arr[0]); // Searching for the smallest element
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Best Case - Time taken: %f seconds\n", time_taken);

    // Worst-case scenario
    start_time = clock();
    int worst_case = binarySearch(arr, 0, n - 1, key + 1); // Searching for an element not in the array
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Worst Case - Time taken: %f seconds\n", time_taken);

    // Average-case scenario
    start_time = clock();
    int avg_case = binarySearch(arr, 0, n - 1, key); // Searching for a random element
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Average Case - Time taken: %f seconds\n", time_taken);
}

int main() {
    srand(time(NULL)); // Seed for random numbers

    // Array size and key
    int n = 200000; // Modify this for different array sizes
    int arr[n];
    printf("For Binary Search: \n");
    // Filling the array with random values
    for (int j = 0; j < n; j++) {
        arr[j] = rand() % 100000; // Generating random numbers between 0 to 999
    }

    int key = rand() % 100000; // Generating a random key to search

    printf("Array Size: %d\n", n);
    analyzeTimeComplexity(arr, n, key);

    return 0;
}
