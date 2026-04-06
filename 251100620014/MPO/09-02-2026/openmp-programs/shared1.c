#include<stdio.h>
#include<omp.h> 

main()
{
int a[10],i=2,n=3;

#pragma omp parallel for shared(a)
//{
for (i=0; i<n; i++)
   {
       a[i] += i;
   } /*-- End of parallel for --*/


for (i=0; i<n; i++)
	{
		printf("%d \n",a[i]);
	}

//}

}
