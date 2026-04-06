#include<stdio.h>
#include<omp.h> 

main() 
 { 

int i,j; 
omp_set_num_threads(4);
#pragma omp parallel
{ 
printf("Thread %d Before barrier\n", omp_get_thread_num()); 

//#pragma omp barrier 

printf("Thread %d After the barrier\n",omp_get_thread_num());

}
} 
