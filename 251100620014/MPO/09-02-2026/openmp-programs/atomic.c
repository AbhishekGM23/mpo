#include<stdio.h>
#include<omp.h> 

main()
{
int ic, i, n;
ic = 0;
#pragma omp parallel shared(n,ic) private(i)
   {
for (i=0; i<3; i++)
    {
      #pragma omp atomic
         ic = ic + 1;
    }
printf("counter = %d\n", ic);
}
}
