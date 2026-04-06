/*
* Write a program that accepts two numbers from the user, num1 and num2.
* The program should list all numbers between 0 and num2 that are divisible by num1 using multithreading.
* Using OpenMP
*/

/*
#include <stdio.h>
#include <omp.h>

int main()
{
    int num1, num2;

    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    #pragma omp parallel for
    for(int i = 0; i <= num2; i++)
    {
        if(i % num1 == 0)
        {
            #pragma omp critical
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}
*/











































#include <stdio.h>
#include <omp.h>

int main()
{
    int num1, num2;

    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    double start_time = omp_get_wtime();

    #pragma omp parallel for
    for(int i = 0; i <= num2; i++)
    {
        if(i % num1 == 0)
        {
            #pragma omp critical
            {
                printf("%d\n", i);
            }
        }
    }

    double end_time = omp_get_wtime();

    printf("Time taken: %f seconds\n", end_time - start_time);

    return 0;
}