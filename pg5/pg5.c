#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time;

    // Start time
    start = clock();

    // Code segment to measure
    int sum = 0;
    for(int i = 0; i < 1000000; i++) {
        sum += i;
    }

    // End time
    end = clock();

    // Calculate time
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sum = %d\n", sum);
    printf("Execution Time = %f seconds\n", cpu_time);

    return 0;
}