#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void delay(int microseconds) {
    usleep(microseconds);
}

void selectionSort(int arr[], int n, int delay_us) {
    int i, j, min_idx;
    clock_t start_time, end_time;
    start_time = clock();

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap arr[i] and arr[min_idx]
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

        long delay= (delay_us*(CLOCKS_PER_SEC/1000))/n;
        clock_t current_time = clock();
        while(clock() < current_time + delay){}
    }

    end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTime taken by selection sort: %f seconds\n", time_taken);
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

    selectionSort(arr, n, delay_us);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}