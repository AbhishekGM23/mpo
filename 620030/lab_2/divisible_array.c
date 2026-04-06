#include <stdio.h>
#include <stdlib.h>

int main() {
    long long num1, num2;

    // Input two numbers
    printf("Enter the first number (size of array): ");
    scanf("%lld", &num1);
    printf("Enter the second number (divisor): ");
    scanf("%lld", &num2);

    // Allocate array dynamically (large array)
    long long *arr = (long long*) malloc(num1 * sizeof(long long));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize array
    for (long long i = 0; i < num1; i++) {
        arr[i] = i;
    }

    printf("Numbers divisible by %lld:\n", num2);
    for (long long i = 0; i < num1; i++) {
        if (arr[i] % num2 == 0) {
            printf("%lld ", arr[i]);
        }
    }

    printf("\n");

    free(arr); // free allocated memory
    return 0;
}
