#include <stdio.h>
#include <pthread.h>

#define SIZE 10000000   // 10 million
#define THREADS 4

int arr[SIZE];
int constant = 3;

void* multiply(void* arg) {
    int thread_no = *(int*)arg;

    int start = thread_no * (SIZE / THREADS);
    int end   = (thread_no + 1) * (SIZE / THREADS);

    printf("Thread %d working on indexes %d to %d\n",
           thread_no + 1, start, end - 1);

    for (int i = start; i < end; i++) {
        arr[i] *= constant;

	}
    return NULL;
}

int main() {
    pthread_t t[THREADS];
    int thread_no[THREADS];

    // Initialize array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < THREADS; i++) {
        thread_no[i] = i;
        pthread_create(&t[i], NULL, multiply, &thread_no[i]);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(t[i], NULL);
    }

    printf("\nAll threads completed.\n");
    return 0;
}
