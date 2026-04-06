#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define SIZE 10
#define THREADS 2

int A[SIZE], B[SIZE], C[SIZE], D[SIZE];

int main() {

    for (int i = 0; i < SIZE; i++) {
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    #pragma omp parallel num_threads(THREADS)
    {
        int tid = omp_get_thread_num();

        if (tid == 0) {
            for (int i = 0; i < SIZE; i++) {
                C[i] = A[i] + B[i];
                printf("Thread %d handled index %d -> A=%d B=%d C=%d\n",
                       tid, i, A[i], B[i], C[i]);
            }
        }

        if (tid == 1) {
            for (int i = 0; i < SIZE; i++) {
                D[i] = A[i] * B[i];
                printf("Thread %d handled index %d -> A=%d B=%d D=%d\n",
                       tid, i, A[i], B[i], D[i]);
            }
        }
    }

    printf("\nArray addition and multiplication completed.\n");
    return 0;
}

