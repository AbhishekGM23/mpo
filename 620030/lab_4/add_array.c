#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define SIZE 9000
#define THREADS 4

int A[SIZE], B[SIZE], C[SIZE];

int main() {

    for (int i = 0; i < SIZE; i++) {
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    #pragma omp parallel for num_threads(THREADS)
    for (int i = 0; i < SIZE; i++) {
        int tid = omp_get_thread_num();
        C[i] = A[i] + B[i];


            printf("Thread %d handled index %d -> A=%d B=%d C=%d\n",
                   tid, i, A[i], B[i], C[i]);

    }

    printf("\nArray addition completed.\n");
    return 0;
}
