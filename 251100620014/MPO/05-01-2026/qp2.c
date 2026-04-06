/*
* Write a multithreaded program to add two large arrays. 
* Create four threads and print the thread number for every computation carried out.
*/

#include <stdio.h>
#include <pthread.h>

#define N 10000

int a[N], b[N], sum[N];

//Thread function
void* add(void* arg)
{
    int tid = *(int*)arg;

    for(int i = tid; i < N; i += 4)
    {
        sum[i] = a[i] + b[i];
        printf("Thread no: %d | %d\n", tid, i);
    }

    return NULL;
}

int main()
{
    pthread_t threads[4];
    int thread_id[4];

    //Initialize large input arrays
    for(int i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = i;
    }

    //Create 4 threads
    for(int i = 0; i < 4; i++)
    {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, add, &thread_id[i]);
    }

    //Wait for all threads to finish
    for(int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
