#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define N 1000000
#define THREADS 2

int arr[N];
long long sum_multi = 0;

// Thread function
void* partial_sum(void* arg) {
    int id = *(int*)arg;
    int start = id * (N / THREADS);
    int end = start + (N / THREADS);

    long long local = 0;
    for(int i = start; i < end; i++) {
        local += arr[i];
    }

    // Add safely (simple case: low contention)
    sum_multi += local;

    return NULL;
}

int main() {
    // Initialize data
    for(int i = 0; i < N; i++) {
        arr[i] = 1;
    }

    clock_t start, end;
    double time_single, time_multi;

    // ---------------- SINGLE THREAD ----------------
    long long sum_single = 0;

    start = clock();

    for(int i = 0; i < N; i++) {
        sum_single += arr[i];
    }

    end = clock();
    time_single = (double)(end - start) / CLOCKS_PER_SEC;

    // ---------------- MULTI THREAD ----------------
    pthread_t threads[THREADS];
    int ids[THREADS];

    start = clock();

    for(int i = 0; i < THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, partial_sum, &ids[i]);
    }

    for(int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    end = clock();
    time_multi = (double)(end - start) / CLOCKS_PER_SEC;

    // ---------------- OUTPUT ----------------
    printf("Single Thread Sum = %lld, Time = %f sec\n", sum_single, time_single);
    printf("Multi Thread Sum  = %lld, Time = %f sec\n", sum_multi, time_multi);

    return 0;
}