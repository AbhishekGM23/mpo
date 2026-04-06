/*
* Create two separate functions, one for adding two arrays and another for multiplying two arrays.
* Write a program that executes these two functions using two separate threads.
* Using OpenMP
*/

#include <stdio.h>
#include <omp.h>

#define N 10000

int a[N], b[N], sum[N], mul[N];

void add_array()
{
    #pragma omp parallel for
    for(int i = 0; i < N; i++)
    {
        sum[i] = a[i] + b[i];
        printf("Add Thread | %d\n", i);
    }
}

void mul_array()
{
    #pragma omp parallel for
    for(int i = 0; i < N; i++)
    {
        mul[i] = a[i] * b[i];
        printf("Mul Thread | %d\n", i);
    }
}

int main()
{

    for(int i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = i;
    }

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            add_array();
        }

        #pragma omp section
        {
            mul_array();
        }
    }

    return 0;
}

