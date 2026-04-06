#include <stdlib.h>
#include<stdio.h>
#include <inttypes.h>
#include<sys/time.h>
#include<time.h>

int comp(const int * a,const int * b)
{
  if (*a==*b)
    return 0;
  else
    if (*a < *b)
        return -1;
     else
      return 1;
}

int main(int argc, char* argv[])
{
   int numbers[10]={1892,45,200,-98,4087,5,-12345,1087,88,-100000};
   int i;
   uint64_t tick1, tick2;
   unsigned c,d;
asm volatile("rdtsc" : "=a" (c), "=d" (d));
tick1 = (((uint64_t)c) | (((uint64_t)d) << 32));
printf("time %llu",tick1);  

/* Sort the array */
  qsort(numbers,10,sizeof(int),comp) ;
  for (i=0;i<9;i++)
    printf("Number = %d\n",numbers[ i ]) ;

asm volatile("rdtsc" : "=a" (c), "=d" (d));
tick2 = (((uint64_t)c) | (((uint64_t)d) << 32));
printf("time %llu",tick2-tick1);



  return 0;


} 	
