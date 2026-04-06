#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv) {
        int t_sum = 0;
        int thread_id;
        int p_sum = 0;

    #pragma omp parallel sections num_threads(4)
    {
        
        thread_id = omp_get_thread_num();  // Get thread id

        #pragma omp section
        {
            if (thread_id == 0) {
                for (int i = 0; i <= 25; i++) {
                    p_sum += i;
                }
                printf("Partial Sum from Thread %d = %d\n", thread_id, p_sum);
            }
        }

        #pragma omp section
        {
            if (thread_id == 1) {
                for (int i = 26; i <= 50; i++) {
                    p_sum += i;
                }
                printf("Partial Sum from Thread %d = %d\n", thread_id, p_sum);
            }
        }

        #pragma omp section
        {
            if (thread_id == 2) {
                for (int i = 51; i <= 75; i++) {
                    p_sum += i;
                }
                printf("Partial Sum from Thread %d = %d\n", thread_id, p_sum);
            }
        }

        #pragma omp section
        {
            if (thread_id == 3) {
                //int p_sum = 0;
                for (int i = 76; i <= 100; i++) {
                    p_sum += i;
                }
                printf("Partial Sum from Thread %d = %d\n", thread_id, p_sum);
            }
        }

        #pragma omp section
        t_sum = t_sum + p_sum;  // Add each thread's partial sum to the total su
        
    }

    #pragma omp barrier
    
    // Final result
    printf("Total Sum: %d\n", t_sum);
    return 0;
}

