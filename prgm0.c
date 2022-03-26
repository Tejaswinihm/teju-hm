#include<stdio.h>
#include<stdlib.h>
void main()
{
int *a,*b;
a=(int*)malloc(sizeof(int));
b=(int*)malloc(sizeof(int));
printf(" %p %p ", a,b);
*a=10,*b=20;
printf("\n  %d %d ",*a,*b); 
}

