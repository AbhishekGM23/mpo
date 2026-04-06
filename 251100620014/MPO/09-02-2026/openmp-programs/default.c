#include<stdio.h>
#include<omp.h> 

main() 
{ 

int i,j,k,l,m,n,o,p,q,r,s,t,u,v,x,y,z; 

#pragma omp parrallel shared(i,j,k,l,m,n,o,p,q,r,s,t,u,v,x,y) private(z) 
{
printf("hello");
}
}
