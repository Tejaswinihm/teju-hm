#include<stdio.h>
 void main()
{
int n,incoming,outgoing,buffersize,store=0;
printf("enter number of packets");
scanf("%d",&n);
printf("enter number of outgoing");
scanf("%d",&outgoing);
printf("enter a buffersize");
scanf("%d",&buffersize);
while(n!=0)
{
printf("enter a  incoming value");
scanf("%d",&incoming);
if(incoming<=(buffersize-store))
{
store+=incoming;
}
else
{
int drp=incoming-(buffersize-store);
printf("dropped packets are %d", drp);
store=buffersize;
}
store=store-outgoing;
n--;
}
}


