#include <stdio.h>
#include <pthread.h>

#define N 6

int arr[N] = {6, 3, 8, 2, 9, 1};

// Bubble sort for part
void bubble(int start, int end) {
    for(int i = start; i < end-1; i++) {
        for(int j = start; j < end-1-(i-start); j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Thread functions
void* sort_first(void* arg) {
    bubble(0, N/2);
    return NULL;
}

void* sort_second(void* arg) {
    bubble(N/2, N);
    return NULL;
}

// Merge two sorted halves
void merge() {
    int temp[N];
    int i = 0, j = N/2, k = 0;

    while(i < N/2 && j < N) {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i < N/2)
        temp[k++] = arr[i++];

    while(j < N)
        temp[k++] = arr[j++];

    for(int x = 0; x < N; x++)
        arr[x] = temp[x];
}

int main() {
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, sort_first, NULL);
    pthread_create(&t2, NULL, sort_second, NULL);

    // Wait
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Merge
    merge();

    printf("Sorted array:\n");
    for(int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}