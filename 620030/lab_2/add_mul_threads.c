#include <stdio.h>
#include <pthread.h>

#define SIZE 6000000   // Large array size

int A[SIZE], B[SIZE], C[SIZE], D[SIZE];

void* add_array(void* arg) {
    printf("Add thread started\n");

    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];


    }

    printf("Add thread finished\n");
    return NULL;
}

void* multiply_array(void* arg) {
    printf("Multiply thread started\n");

    for (int i = 0; i < SIZE; i++) {
        D[i] = A[i] * B[i];

        // Print first few indexes only
        if (i < 3) {
            printf("Multiply thread computed index %d\n", i);
        }
    }

    printf("Multiply thread finished\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Initialize arrays
    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = SIZE - i;
    }

    // Create threads
    pthread_create(&t1, NULL, add_array, NULL);
    pthread_create(&t2, NULL, multiply_array, NULL);

    // Wait for threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\nBoth operations completed.\n");
    return 0;
}
