#include<stdio.h>
#include<omp.h>
main()
{
int i=0,a,n=4;

#pragma omp parallel for private(i,a) 
  for (i=0; i<n; i++)
   {
       a = i+1;
       printf("Thread %d has a value of a = %d for i = %d\n",
              omp_get_thread_num(),a,i);
   } /*-- End of parallel for --*/
  printf("Value of a after parallel for: a = %d\n",a);
  
  printf("Value of i after parallel for: i = %d\n",i);
}
