// #include <stdio.h>
// #include <omp.h>

// #define N 50

// int main() {
//     int arr[N];
//     int sum = 0;

//     // Auto-fill array: 1 to 10
//     for(int i = 0; i < N; i++) {
//         arr[i] = i + 1;
//     }

//     // Parallel sum using OpenMP
//     #pragma omp parallel for reduction(+:sum)
//     for(int i = 0; i < N; i++) {
//         sum += arr[i];
//     }

//     printf("Sum = %d\n", sum);

//     return 0;
// }


#include <stdio.h>
#include <omp.h>

#define N 10

int main() {
    int arr[N];
    int sum = 0;

    // Auto-fill array
    for(int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    #pragma omp parallel
    {
        int local_sum = 0;

        #pragma omp for
        for(int i = 0; i < N; i++) {
            local_sum += arr[i];
        }

        // Critical section to update global sum
        #pragma omp critical
        {
            sum += local_sum;
        }
    }

    printf("Sum = %d\n", sum);

    return 0;
}