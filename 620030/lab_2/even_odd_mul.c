#include <stdio.h>
#include <pthread.h>

#define SIZE 10000000   // 10 million elements
int arr[SIZE];
int constant = 5;

void* multiply_even(void* arg) {
    int start = 0;           // even indexes
    int end = SIZE - 1;      // last index

    printf("Even thread multiplying indexes 0 to %d\n", SIZE - 1);

    for (int i = start; i < SIZE; i += 2) {
        arr[i] *= constant;
    }

    printf("Even thread finished\n");
    return NULL;
}

void* multiply_odd(void* arg) {
    int start = 1;           // odd indexes
    int end = SIZE - 1;

    printf("Odd thread multiplying indexes 1 to %d\n", SIZE - 1);

    for (int i = start; i < SIZE; i += 2) {
        arr[i] *= constant;
    }

    printf("Odd thread finished\n");
    return NULL;
}

int main() {
    pthread_t even_thread, odd_thread;

    // Initialize array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    // Create threads
    pthread_create(&even_thread, NULL, multiply_even, NULL);
    pthread_create(&odd_thread, NULL, multiply_odd, NULL);

    // Wait for threads to finish
    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    printf("\nMultiplication completed for large array.\n");

    return 0;
}
