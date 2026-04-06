#include<stdio.h>
#include<omp.h>

main()
{

int i,n=3,a;
#pragma omp parallel for private(i,a)  
for (i=0; i<n; i++)
   {
       a = i+1;
       printf("Thread %d has a value of a = %d for i = %d\n",omp_get_thread_num(),a,i);
   }
}

