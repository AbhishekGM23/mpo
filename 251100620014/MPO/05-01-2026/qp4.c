/*
* Write a multithreaded program to multiply every element of a large array by a constant value such that:
* Even-numbered threads multiply elements at even indices
* Odd-numbered threads multiply elements at odd indices
* (Assume array indexing starts from 0.)
*/

#include <stdio.h>
#include <pthread.h>

#define N 10000

int a[N];
int c = 2;

//Thread function
void* mul(void* arg)
{
    int tid = *(int*)arg;

    for(int i = 0; i < N; i++)
    {
        /* Even thread → even index
           Odd thread  → odd index */
        if((tid % 2) == (i % 2))
        {
            a[i] = a[i] * c;
            printf("Thread no: %d | %d\n", tid, i);
        }
    }

    return NULL;
}

int main()
{
    pthread_t threads[4];
    int thread_id[4];

    //Initialize large array
    for(int i = 0; i < N; i++)
    {
        a[i] = i;
    }

    //Create 4 threads
    for(int i = 0; i < 4; i++)
    {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, mul, &thread_id[i]);
    }

    //Wait for all threads
    for(int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
