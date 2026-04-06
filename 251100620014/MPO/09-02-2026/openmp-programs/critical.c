#include<stdio.h>
#include<omp.h>
main()
{
int sum,i,sumLocal,TID;
int a[]={1,2,3,4,5,6,7,8,9};

omp_set_num_threads(4);
sum = 0;
#pragma omp parallel shared(a,sum) private(TID,sumLocal)
  {
     TID = omp_get_thread_num();
     sumLocal = 0;
     #pragma omp for
        for (i=0; i<9; i++)
           sumLocal += a[i];
     #pragma omp critical (update_sum)
      {
        sum += sumLocal;
        printf("TID=%d: sumLocal=%d sum = %d\n",TID,sumLocal,sum);
      }
  } /*-- End of parallel region --*/
printf("Value of sum after parallel region: %d\n",sum);
}

