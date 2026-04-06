#include<stdio.h>
#include<omp.h> 

int main() 
 { 

int i,j,TID; 
omp_set_num_threads(4);
#pragma omp parallel
{ 

TID = omp_get_thread_num();
if (TID < omp_get_num_threads()/2 ) 
system("sleep 3");

printf("Thread %d Before barrier\n", omp_get_thread_num()); 

system("date +%S");
#pragma omp barrier 

printf("Thread %d After the barrier\n",omp_get_thread_num());

}
} 
