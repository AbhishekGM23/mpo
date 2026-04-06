#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
// create a array multiply it with constant number. for this utilise 4 threads and print the thread no that is computed the task
#define SIZE 10
int data[SIZE];

void generate_data() {
    for (int i = 0; i < SIZE; i++) {
        data[i] = i % 10;
    }
}

void task1() {
    for (int i = 0; i < SIZE/4; i++) {
        data[i]= data[i]*8;
    }
}

void task2() {
    for (int i = SIZE/4; i < SIZE/2; i++) {
        data[i]= data[i]*8;
    }
   
}

void task3() {
    for (int i = SIZE/2; i < (3*SIZE)/4; i++) {
        data[i]= data[i]*8;
    }
    
}
void task4() {
    for (int i =(3*SIZE)/4; i < SIZE; i++) {
        data[i]= data[i]*8;
    }
    
}

void* thread_task(void* arg) {
    int id = *((int*)arg);
    switch (id) {
        case 1:
            task1();
            printf("Thread %d completed. \n", id);
            break;
        case 2:
            task2();
            printf("Thread %d completed. \n", id);
            break;
        case 3:
            task3();
            printf("Thread %d completed. \n", id);
            break;
        case 4:
            task4();
            printf("Thread %d completed. \n", id);
            break;
    }
    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_ids[5];
    struct timespec start, end;

    generate_data();

    printf("Starting 5 Parallel Threads...\n");
    printf("Initial data\n");
    for(int i=0;i<SIZE;i++)
    	printf("%d  ",data[i]);
    printf("\n");
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_task, &thread_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Modified data\n");
        for(int i=0;i<SIZE;i++)
    	printf("%d  ",data[i]);
    printf("\n");

    printf("\nTotal Multitasked Time: %.4f seconds\n", time_taken);
    return 0;
}