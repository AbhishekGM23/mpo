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
#include <time.h>

int main() {
    int M, N;

    printf("Enter rows and columns: ");
    scanf("%d %d", &M, &N);

    int matrix[M][N];

    // Input
    printf("Enter matrix elements:\n");
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    clock_t start, end;
    double time_taken;

    start = clock();

    // Row-wise computation
    printf("\nRow-wise results:\n");
    for(int i = 0; i < M; i++) {
        int pos = 0, neg = 0, zero = 0;

        for(int j = 0; j < N; j++) {
            if(matrix[i][j] > 0) pos++;
            else if(matrix[i][j] < 0) neg++;
            else zero++;
        }

        printf("Row %d -> Pos:%d Neg:%d Zero:%d\n", i, pos, neg, zero);
    }

    // Column-wise min
    printf("\nColumn-wise minimum:\n");
    for(int j = 0; j < N; j++) {
        int min = matrix[0][j];

        for(int i = 1; i < M; i++) {
            if(matrix[i][j] < min)
                min = matrix[i][j];
        }

        printf("Column %d -> Min:%d\n", j, min);
    }

    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSequential Execution Time: %f seconds\n", time_taken);

    return 0;
}