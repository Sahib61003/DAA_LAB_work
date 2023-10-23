#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void delay(int microseconds) {
    usleep(microseconds);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high, int delay_us) {
    if (low < high) {
        int pi = partition(arr, low, high);

        long delay = (delay_us * (CLOCKS_PER_SEC / 1000)) / (high - low + 1);
        clock_t current_time = clock();
        while (clock() < current_time + delay) {}

        quickSort(arr, low, pi - 1, delay_us);
        quickSort(arr, pi + 1, high, delay_us);
    }
}
int main() {
    int n, i;
    int delay_us = 2000;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array:\n");  
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    clock_t start_time = clock();
    quickSort(arr, 0, n - 1, delay_us);
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTime taken by quick sort: %f seconds\n", time_taken);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSahib Preet Singh AI-ML 00713211621");
    return 0;
}
