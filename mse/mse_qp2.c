/*
* Create an integer matrix of size M × N and populate it with values entered by the user.
* Create N threads such that each thread works on a distinct row and calculates the number of positive, negative, and zero elements present in that row.
* Create N threads such that each thread works on a distinct column and determines the smallest element in that column. Display all results both inside and outside the parallel region.
*
* a) Write the sequential program first.
* b) Modify the program using OpenMP by inserting the necessary pragmas, and also measure the execution time for both the sequential and parallel implementations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int M, N;

    printf("Enter rows and columns: ");
    scanf("%d %d", &M, &N);

    int matrix[M][N];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    double start, end;

    start = omp_get_wtime();

    printf("\n--- Row-wise (Parallel) ---\n");

    // Row-wise parallel
    #pragma omp parallel for
    for(int i = 0; i < M; i++) {
        int pos = 0, neg = 0, zero = 0;

        for(int j = 0; j < N; j++) {
            if(matrix[i][j] > 0) pos++;
            else if(matrix[i][j] < 0) neg++;
            else zero++;
        }

        printf("Thread %d -> Row %d: Pos:%d Neg:%d Zero:%d\n",
               omp_get_thread_num(), i, pos, neg, zero);
    }

    printf("\n--- Column-wise Min (Parallel) ---\n");

    // Column-wise parallel
    #pragma omp parallel for
    for(int j = 0; j < N; j++) {
        int min = matrix[0][j];

        for(int i = 1; i < M; i++) {
            if(matrix[i][j] < min)
                min = matrix[i][j];
        }

        printf("Thread %d -> Column %d Min:%d\n",
               omp_get_thread_num(), j, min);
    }

    end = omp_get_wtime();

    printf("\nParallel Execution Time: %f seconds\n", end - start);

    return 0;
}