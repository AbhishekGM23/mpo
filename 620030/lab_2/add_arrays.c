#include <stdio.h>
#include <pthread.h>

#define SIZE 9000000    // 9 million elements
#define THREADS 3

int A[SIZE], B[SIZE], C[SIZE];

void* add(void* arg) {
    int thread_no = *(int*)arg;

    int start = thread_no * (SIZE / THREADS);
    int end   = (thread_no + 1) * (SIZE / THREADS);

    printf("Thread %d adding indexes %d to %d\n",
           thread_no + 1, start, end - 1);

    for (int i = start; i < end; i++) {
        C[i] = A[i] + B[i];


    }

    return NULL;
}

int main() {
    pthread_t t[THREADS];
    int thread_no[THREADS];

    // Initialize arrays
    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = SIZE - i;
    }

    // Create threads
    for (int i = 0; i < THREADS; i++) {
        thread_no[i] = i;
        pthread_create(&t[i], NULL, add, &thread_no[i]);
    }

    // Wait for threads
    for (int i = 0; i < THREADS; i++) {
        pthread_join(t[i], NULL);
    }

    printf("\nArray addition completed.\n");
    return 0;
}
