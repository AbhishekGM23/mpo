/*Write a multithreaded program that will find the repetition of a number in a nXn matrix.Initialization of the matrix shd be done in the parallel region,but done by one thread.The num to be searched shd be entered by the user before entering the parallel region*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX_SIZE 1000 // Maximum matrix size

// Function to initialize the matrix with random numbers
void initializeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;  // Random numbers between 0 and 99
        }
    }
}

// Function to count occurrences of a number in the matrix
int countOccurrences(int matrix[MAX_SIZE][MAX_SIZE], int n, int search_num) {
    int count = 0;

    #pragma omp parallel for reduction(+:count)  // Parallelize the loop and use reduction to safely update count
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == search_num) {	//if matrix element is same as the element to be searched
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n, search_num;

    // Get the size of the matrix and the number to search for from the user
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Matrix size exceeds the maximum allowed size.\n");
        return -1;
    }

    printf("Enter the number to search for: ");
    scanf("%d", &search_num);

    // Declare the matrix
    int matrix[MAX_SIZE][MAX_SIZE];

    // Set the number of threads
    int num_threads = 4;  // Example: You can adjust this based on your hardware capabilities

    // Start OpenMP parallel region
    #pragma omp parallel num_threads(num_threads)
    {
        // Initialize the matrix in parallel, but only one thread does the actual initialization
        #pragma omp single
        {
            initializeMatrix(matrix, n);
            printf("Matrix initialized.\n");
        }

        // After initialization, search for the number in parallel
        #pragma omp barrier  // Ensure that the initialization is completed before the search

        int count = countOccurrences(matrix, n, search_num);

        // Only one thread prints the result after the search is complete
        #pragma omp single
        {
            printf("The number %d occurred %d times in the %d x %d matrix.\n", search_num, count, n, n);
        }
    }

    return 0;
}

