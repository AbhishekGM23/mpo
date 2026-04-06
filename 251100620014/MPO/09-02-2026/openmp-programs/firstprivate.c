#include<stdio.h>
#include<omp.h>

main()
{

int i,j,n=10,a[20];
for(i=0;i<n;i++)
	a[i]=i;
j=5;
#pragma omp parallel firstprivate(j)shared(a,n)
{
j=0;
#pragma omp for
for(i=j;i<n;i++)
printf("printing %d\n",a[i]);

}
}

