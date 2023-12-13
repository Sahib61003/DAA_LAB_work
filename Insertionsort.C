#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for usleep

void delay(int microseconds) {
    usleep(microseconds);
}

void insertionSort(int arr[], int n, int delay_us) {
    int i, key, j;
    clock_t start_time, end_time;
    start_time = clock();
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Move the delay outside the inner loop
        delay(delay_us * (CLOCKS_PER_SEC / 1000));
    }
    
    end_time = clock(); // Record the ending time
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTime taken by insertion sort: %f seconds\n", time_taken);
}

int main() {
    int n, i;
    int delay_us = 10000;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n, delay_us);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
