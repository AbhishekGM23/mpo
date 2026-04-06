#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define SIZE 10
#define THREADS 2
int constant=12;
int arr[SIZE];

int main() {

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10;
        
    }

    #pragma omp parallel num_threads(THREADS)
    {
        int tid = omp_get_thread_num();

        if (tid == 0) {
             int start = 0;           // even indexes
    		int end = SIZE - 1;      // last index

    	printf("Even thread multiplying indexes 0 to %d\n", SIZE - 1);

    	for (int i = start; i < SIZE; i += 2) {
   	  	   arr[i] *= constant;
 	  }
   	     }

        if (tid == 1) {
           int start = 1;           // odd indexes
   	 int end = SIZE - 1;

   	 printf("Odd thread multiplying indexes 1 to %d\n", SIZE - 1);

  	  for (int i = start; i < SIZE; i += 2) {
        arr[i] *= constant;
   	 }
    }
	}
    printf("\nArray addition and multiplication completed.\n");
    return 0;
    
}
