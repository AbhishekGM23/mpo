#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define SIZE 100  // 10 million
#define THREADS 4

int arr[SIZE];
int constant = 3;

int main() {

    // Initialize array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand()%100;
    }

    #pragma omp parallel for num_threads(THREADS)
    for (int i = 1; i < SIZE; i++) {
        int tid = omp_get_thread_num();
	printf("Arr=%d\t",arr[i]);
        arr[i] *= constant;
        printf("Thread %d handled index %d -> Arr=%d\n",tid, i, arr[i]);
    }

    printf("\nAll threads completed.\n");
    return 0;
}
