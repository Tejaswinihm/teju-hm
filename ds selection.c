#include <stdio.h>
#include <stdlib.h>
int main()
{
int a[100],i,j,n,min,t;
printf("enter he number of elements\n");
scanf("%d",&n);
printf("enter the elements\n");
for(i=0;i<n;i++)
scanf("%d", &a[i]);
printf("\n the sorted lis is:");
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(a[min]>a[j])
{
min=j;
}
}
if(min!=i)
{
t=a[i];
a[i]=a[min];
a[min]=t;
}
}
for(i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;
}

