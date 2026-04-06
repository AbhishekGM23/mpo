/*
* Write a multithreaded program to add two large arrays. 
* Create four threads and print the thread number for every computation carried out.
* Using OpenMP
*/
#include <stdio.h>
#include <omp.h>

#define N 10000

int a[N], b[N], sum[N];

int main()
{

    for(int i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = i;
    }

    #pragma omp parallel for
    for(int i = 0; i < N; i++)
    {
        int tid = omp_get_thread_num();
        sum[i] = a[i] + b[i];
        printf("Thread no: %d | %d\n", tid, i);
    }

    return 0;
}












