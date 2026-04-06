// #include <stdio.h>
// #include <pthread.h>

// #define N 2   // matrix size (2x2 for simplicity)

// int A[N][N] = { {1, 2}, {3, 4} };
// int B[N][N] = { {5, 6}, {7, 8} };
// int C[N][N];

// // Thread function → computes one row of C
// void* multiply(void* arg) {
//     int row = *(int*)arg;

//     for(int j = 0; j < N; j++) {
//         C[row][j] = 0;
//         for(int k = 0; k < N; k++) {
//             C[row][j] += A[row][k] * B[k][j];
//         }
//     }

//     return NULL;
// }

// int main() {
//     pthread_t threads[N];
//     int row_id[N];

//     // Create one thread per row
//     for(int i = 0; i < N; i++) {
//         row_id[i] = i;
//         pthread_create(&threads[i], NULL, multiply, &row_id[i]);
//     }

//     // Wait for all threads
//     for(int i = 0; i < N; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     // Print result matrix
//     printf("Result Matrix:\n");
//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             printf("%d ", C[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }



// #include <stdio.h>
// #include <omp.h>

// #define N 2   // 2x2 matrix

// int main() {
//     int A[N][N] = { {1, 2}, {3, 4} };
//     int B[N][N] = { {5, 6}, {7, 8} };
//     int C[N][N];

//     // Parallel matrix multiplication
//     #pragma omp parallel for collapse(2)
//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             C[i][j] = 0;
//             for(int k = 0; k < N; k++) {
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }

//     // Print result
//     printf("Result Matrix:\n");
//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             printf("%d ", C[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }


#include <stdio.h>
#include <omp.h>

#define N 10

int main() {
    int arr[N];

    // Parallel loop
    #pragma omp parallel for
    for(int i = 0; i < N; i++) {
        arr[i] = i * i;   // example work (square)
        printf("Thread %d -> arr[%d] = %d\n",
               omp_get_thread_num(), i, arr[i]);
    }

    return 0;
}