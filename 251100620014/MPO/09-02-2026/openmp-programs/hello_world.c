#include<stdio.h>
#include<omp.h> 
main()
{

#pragma omp parallel 
{
int ID = 0;
ID = omp_get_thread_num();
printf("Hello %d openmp...",ID);

}
}
