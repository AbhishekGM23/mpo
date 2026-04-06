/*
 * Write a multithreaded program to multiply every element of a large array by a constant value.
 * Create four threads and print the thread number for each multiplication performed.
 */

#include <stdio.h>
#include <omp.h>

#define N 10000

int a[N];
int c = 2;

int main()
{
    // Initialize array
    for(int i = 0; i < N; i++)
    {
        a[i] = i;
    }

    // Parallel region with 4 threads
    #pragma omp parallel for num_threads(4)
    for(int i = 0; i < N; i++)
    {
        int tid = omp_get_thread_num();
        a[i] = a[i] * c;
        printf("Thread no: %d | %d\n", tid, i);
    }

    return 0;
}
