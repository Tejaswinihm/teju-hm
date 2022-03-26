#include <stdio.h>
void main()
{
int a[20], key, n=4, i;
printf(" enter the total numbers of array");
scanf( "%d" , &n);
for(i=0; i<n; i++)
scanf( "%d" , &a[i]);
printf(" enter the search key");
scanf( "%d" , &key);
for(i=0; i<n; i++)
if(key==a[i])
printf (" the search key is present at position %d ", i);
}



