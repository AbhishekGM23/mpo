/*
* Write a program that accepts two numbers from the user, num1 and num2.
* The program should list all numbers between 0 and num2 that are divisible by num1 using multithreading.
*/

#include <stdio.h>
#include <pthread.h>

int num1, num2;

//Thread function
void* list(void* arg)
{
    for(int i = 0; i <= num2; i++)
    {
        if(i % num1 == 0)
        {
            printf("%d\n", i);
        }
    }
    return NULL;
}

int main()
{
    pthread_t t;

    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    //Create one thread
    pthread_create(&t, NULL, list, NULL);

    //Wait for thread to finish
    pthread_join(t, NULL);

    return 0;
}
