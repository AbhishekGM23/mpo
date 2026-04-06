/*
* Set-1
* Using POSIX threads (pthreads), solve the following:
*
* 1) Design and execute a single task using pthreads and observe the output.
* 2) Similar to the above task, create five different single-task programs using pthreads and observe their outputs.
*
* Set-2
* 1) Convert the single-task programs developed in Set-1 into a multitask program using pthreads.
*
* Note -
*    Calculate and record the execution time of each task.
*    The data used for the tasks should be of large size (minimum 1000 elements).
*    Do not use the random function; instead, write a custom function to generate the data.
*    Write a short observation note based on the execution results. 
*/

#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define SIZE 10000000

int data[SIZE];

//data generation
void generate_data() {
    for (int i = 0; i < SIZE; i++) {
        data[i] = i % 10;
    }
}

//task1 sum
void* task_sum(void* arg) {
    long long sum = 0;
    for (int i = 0; i < SIZE; i++)
        sum += data[i];

    printf("Task 1 (Sum) = %lld\n", sum);
    return NULL;
}

//task2 multiplication
void* task_mul(void* arg) {
    long long mul = 1;
    const long long MOD = 1000000007;

    for (int i = 0; i < SIZE; i++) {
        if (data[i] != 0)
            mul = (mul * data[i]) % MOD;
    }

    printf("Task 2 (Multiplication) = %lld\n", mul);
    return NULL;
}

//task3 average
void* task_avg(void* arg) {
    long long sum = 0;
    for (int i = 0; i < SIZE; i++)
        sum += data[i];

    printf("Task 3 (Average) = %.2f\n", (double)sum / SIZE);
    return NULL;
}

//task4 minimum
void* task_min(void* arg) {
    int min = data[0];
    for (int i = 1; i < SIZE; i++) {
        if (data[i] < min)
            min = data[i];
    }

    printf("Task 4 (Minimum) = %d\n", min);
    return NULL;
}

//task5 count>5
void* task_count(void* arg) {
    long long count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (data[i] > 5)
            count++;
    }

    printf("Task 5 (Count > 5) = %lld\n", count);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3, t4, t5;
    struct timespec start, end;

    generate_data();

    printf("Starting MULTI-TASK execution...\n");

    clock_gettime(CLOCK_MONOTONIC, &start);

    pthread_create(&t1, NULL, task_sum, NULL);
    pthread_create(&t2, NULL, task_mul, NULL);
    pthread_create(&t3, NULL, task_avg, NULL);
    pthread_create(&t4, NULL, task_min, NULL);
    pthread_create(&t5, NULL, task_count, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);

    clock_gettime(CLOCK_MONOTONIC, &end);

    double total_time =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("\nTotal Execution Time = %.4f seconds\n", total_time);

    return 0;
}
