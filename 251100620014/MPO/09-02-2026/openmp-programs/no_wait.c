#include<omp.h>
#include<stdio.h>

main() 
{
int n=4,i=0,j=0;
omp_set_num_threads(2); 

#pragma omp parallel shared(n) private(i,j)
{
//printf("%d \n",i);
   #pragma omp for nowait
   for (i=0; i<n; i++)
      {	printf("Thread %d executes loop iteration %d\n",
             omp_get_thread_num(),i);
	}


printf("this thread finished executing %d\n", omp_get_thread_num());
}


}
