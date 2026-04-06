/*
* Create two separate functions, one for adding two arrays and another for multiplying two arrays.
* Write a program that executes these two functions using two separate threads.
*/

#include <stdio.h>
#include <pthread.h>

#define N 10000

int a[N], b[N], sum[N], mul[N];

//Function to add two arrays
void* add_array(void* arg)
{
    for(int i = 0; i < N; i++)
    {
        sum[i] = a[i] + b[i];
        printf("Add Thread | %d\n", i);
    }
    return NULL;
}

//Function to multiply two arrays
void* mul_array(void* arg)
{
    for(int i = 0; i < N; i++)
    {
        mul[i] = a[i] * b[i];
        printf("Mul Thread | %d\n", i);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    //Initialize large input arrays
    for(int i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = i;
    }

    //Create two separate threads
    pthread_create(&t1, NULL, add_array, NULL);
    pthread_create(&t2, NULL, mul_array, NULL);

    //Wait for threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
