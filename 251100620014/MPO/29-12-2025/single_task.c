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
#include <time.h>
#include <pthread.h>

#define SIZE 10000000

int data[SIZE];

//data generation
void generate_data() {
    for (int i = 0; i < SIZE; i++) {
        data[i] = i % 10;
    }
}

//sinle task function
void* single_task_operations(void* arg) {

    long long sum = 0;
    long long product = 1;
    long long count_gt_5 = 0;
    const long long MOD = 1000000007;

    int min = data[0];

    for (int i = 0; i < SIZE; i++) {

        sum += data[i]; //sum

        //multiplication
        if (data[i] != 0)
            product = (product * data[i]) % MOD;

        //minimum
        if (data[i] < min)
            min = data[i];

        //count>5
        if (data[i] > 5)
            count_gt_5++;
    }

    //average
    double avg = (double)sum / SIZE;

    printf("Task 1   Sum = %lld\n", sum);
    printf("Task 2   Product (mod) = %lld\n", product);
    printf("Task 3   Average = %.2f\n", avg);
    printf("Task 4   Minimum = %d\n", min);
    printf("Task 5   Count > 5 = %lld\n", count_gt_5);

    return NULL;
}

int main() {

    struct timespec start, end;
    pthread_t t1;

    generate_data();
    printf("Single Task \n");

    clock_gettime(CLOCK_MONOTONIC, &start);

    pthread_create(&t1, NULL, single_task_operations, NULL);
    pthread_join(t1, NULL);

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Total Execution Time = %.4f seconds\n", time_taken);

    return 0;
}

