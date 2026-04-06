#include<stdio.h>
#include<omp.h>
main()
{

void funcA();
void funcB();
#pragma omp parallel
{
   #pragma omp sections
   {
      #pragma omp section
         funcA();
      #pragma omp section
        funcB();
   } /*-- End of sections block --*/
}

}

void funcA() {

printf("In function A %d\n ",omp_get_thread_num());
}


void funcB() {

printf("In function B %d \n ",omp_get_thread_num());
}
