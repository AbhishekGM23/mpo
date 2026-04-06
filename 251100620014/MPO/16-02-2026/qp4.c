/*
* Write a multithreaded program to multiply every element of a large array by a constant value such that:
* Even-numbered threads multiply elements at even indices
* Odd-numbered threads multiply elements at odd indices
* (Assume array indexing starts from 0.)
* Using OpenMP
*/

#include <stdio.h>
#include <omp.h>

#define N 10000

int a[N];
int c = 2;


void* mul(void* arg) {
int tid = *(int*)arg;
#pragma omp parallel for
  
  for(int i = 0; i < N; i++)
    {
        if((tid % 2) == (i % 2))
        {
            a[i] = a[i] * c;
            printf("Thread no: %d | %d\n", tid, i);
        }
    }

    return NULL;
}






int main() {

for(int i = 0; i < N; i++)
    {
        a[i] = i;
    }
    
    
    #pragma omp parallel for
    
        {
    void*  mul(void* arg);
        }
        
    return 0;
}
