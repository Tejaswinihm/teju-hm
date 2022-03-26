#include <stdio.h>
#include <stdlib.h>
void main()
{
int a[20],key,i,n,low=0,high,mid;
printf("enter the total number of array");
scanf("%d", &n);
printf("enter the array elements");
for(i=0; i<n; i++)
scanf("%d", &a[i]);
printf("enter the key");
scanf("%d", & key);
high=n-1;
while (low<=high)
{
mid=(high + low)/2;
if(key==a[mid])
{
printf("item found");
exit(0);
}
else if (key > a[mid])
{
low=mid+1;
}
else
{
high=mid-1;
}
}
}

                                                             
