#include <stdio.h>
int main()
{
int a[100],i,j,swap,n;
printf("enter the number of elements\n");
scanf("%d", &n);
printf("enter the elements:\n");
for(i=0; i<n; i++)
scanf("%d", &a[i]);
for(i=0; i<n; i++)
{
for(j=0; j<n-i-1; j++)
{
if(a[j]>a[j+1])
{
swap=a[j];
a[j]=a[j+1];
a[j+1]=swap;
}
}
}
printf("\n the sorted list is:");
for (i=0; i<n; i++)
printf("%d\f", a[i]);
return 0;
}

