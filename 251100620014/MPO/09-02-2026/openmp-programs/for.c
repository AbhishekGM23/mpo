#include<omp.h>
#include<stdio.h>

main() 
{
int n=10000,i=0,j=0;

#pragma omp parallel shared(n) private(i)
{
printf("%d \n",i);
  #pragma omp for
   for (i=0; i<n; i++);
      
	printf("Thread %d executes loop iteration %d\n",
           omp_get_thread_num(),i);
}

}
