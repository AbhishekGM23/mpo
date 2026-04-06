// #include <stdio.h>
// #include <pthread.h>

// int arr[100], n;
// int sum = 0;

// // Thread function
// void* compute_sum(void* arg) {
//     for(int i = 0; i < n; i++) {
//         sum += arr[i];
//     }
//     return NULL;
// }

// int main() {
//     pthread_t t;

//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     printf("Enter elements:\n");
//     for(int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     // Create thread
//     pthread_create(&t, NULL, compute_sum, NULL);

//     // Wait for thread
//     pthread_join(t, NULL);

//     printf("Sum = %d\n", sum);

//     return 0;
// }


// #include <stdio.h>
// #include <pthread.h>

// int arr[10];
// int sum = 0;
// int n = 10;

// // Thread function
// void* compute_sum(void* arg) {
//     for(int i = 0; i < n; i++) {
//         sum += arr[i];
//     }
//     return NULL;
// }

// int main() {
//     pthread_t t;

//     // Auto-fill array
//     for(int i = 0; i < n; i++) {
//         arr[i] = i + 1;   // 1,2,3,...10
//     }

//     // Create thread
//     pthread_create(&t, NULL, compute_sum, NULL);

//     // Wait for thread
//     pthread_join(t, NULL);

//     printf("Sum = %d\n", sum);

//     return 0;
// }


#include <stdio.h>
#include <pthread.h>

#define N 10

int arr[N];
int sum1 = 0, sum2 = 0;

// Thread 1 → first half
void* part1(void* arg) {
    for(int i = 0; i < N/2; i++) {
        sum1 += arr[i];
    }
    return NULL;
}

// Thread 2 → second half
void* part2(void* arg) {
    for(int i = N/2; i < N; i++) {
        sum2 += arr[i];
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Auto-fill array: 1 to 10
    for(int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    // Create threads
    pthread_create(&t1, NULL, part1, NULL);
    pthread_create(&t2, NULL, part2, NULL);

    // Wait for threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    int total = sum1 + sum2;

    printf("Total Sum = %d\n", total);

    return 0;
}