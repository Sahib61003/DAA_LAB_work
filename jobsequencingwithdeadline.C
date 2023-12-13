#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int id; // Job ID
    int deadline; // Deadline of the job
    int profit; // Profit of the job
};

// Function to compare jobs based on their profits (used for sorting)
int compare(const void* a, const void* b) {
    return (*(struct Job*)b).profit - (*(struct Job*)a).profit;
}

// Function to perform Job Sequencing with Deadlines
void jobSequencing(struct Job arr[], int n) {
    // Sort jobs based on their profits in non-increasing order
    qsort(arr, n, sizeof(arr[0]), compare);

    // Find the maximum deadline to allocate the array of slots accordingly
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > maxDeadline)
            maxDeadline = arr[i].deadline;
    }

    // Array to store the sequence of jobs
    int sequence[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        sequence[i] = -1; // Initialize all slots as empty

    // Fill the slots by allocating jobs in decreasing order of profit
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (sequence[j] == -1) {
                sequence[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    // Display the sequence of jobs and the total profit
    printf("Sequence of jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (sequence[i] != -1)
            printf("%d ", sequence[i]);
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    printf("\n\t\t Job Sequencing Problem with Deadline\n");
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];
    printf("Enter deadline and profit for each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
        jobs[i].id = i + 1; // Assigning job IDs
    }

    jobSequencing(jobs, n);
    return 0;
    
}
