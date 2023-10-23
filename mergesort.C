#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void delay(int microseconds) {
    usleep(microseconds);
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r, int delay_us) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, delay_us);
        mergeSort(arr, m + 1, r, delay_us);

        merge(arr, l, m, r);

        // Introduce a delay here if needed
        delay(delay_us);
    }
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

    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    clock_t start_time = clock();
    mergeSort(arr, 0, n - 1, delay_us);
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTime taken by merge sort: %f seconds\n", time_taken*10);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nSahib Preet Singh AI-ML 00713211621");
    return 0;
}
