#include<stdio.h>
#include<stdlib.h>
int n,cost[10][10],d[10],p[10];

 void diji(int source)
{
int s[10],i,j,u,v,min;
for(i=0;i<n;i++)
{
s[i]=0;
p[i]=source;
d[i]=cost[source][i];
}
s[source]=1;
for(i=1;i<n;i++)
{
min=99;
u=-1;
for(j=0;j<n;j++)
{
if(s[j]==0)
{
if(d[j]<min)
{
min=d[j];
u=j;
}
}
}
if(u==-1)
return;
s[u]=1;
for(v=0;v<n;v++)
{
if(s[v]==0)
{
if(d[u]+cost[u][v]<d[v])
{
d[v]=d[u]+cost[u][v];
p[v]=u;
}
}
}
}
}
void print_path(int source,int destination)
{
int i;
i=destination;
while(i!=source)
{
printf("%d<--",i);
i=p[i];
}
printf("%d=%d",i,d[destination]);
}
void main()
{
int i,j,source;
printf("\n enter the number of vertices\n");
scanf("%d",&n);
printf("enter the matrix\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d", &cost[i][j]);
printf("adjcency matrix is:");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t", cost[i][j]);
}
printf("\n");
}
printf("\n enter the source vertex");
scanf("%d",&source);
diji(source);
printf("\nthe shortest path and distance are shown below\n");
for(j=0;j<n;j++)
{
if(d[j]==99)
printf("is not reachable from%d-->%d",source,j);
else
print_path(source,j);
printf("\n");
}
}

