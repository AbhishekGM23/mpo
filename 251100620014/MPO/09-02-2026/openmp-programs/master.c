#include<stdio.h> 
#include<omp.h> 

main()
{
int a,i,n=3,b[4];
#pragma omp parallel shared(a,b) private(i)
 {
    #pragma omp master
     {
       a = 10;
       printf("Master construct is executed by thread %d\n",
               omp_get_thread_num());
     }
    #pragma omp barrier
    #pragma omp for
     for (i=0; i<n; i++)
          b[i] = a;
} /*-- End of parallel region --*/
printf("After the parallel region:\n");
for (i=0; i<n; i++)
     printf("b[%d] = %d\n",i,b[i]);

}
