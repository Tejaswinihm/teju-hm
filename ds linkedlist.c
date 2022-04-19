#include<stdio.h>
#include<stdlib.h>
typedef struct Node * lstptr;
struct Node
{
int data;
lstptr link;
};
lstptr first=NULL;
lstptr getnode()
{
lstptr node;
node=(lstptr)malloc(sizeof(struct Node));
return node;
}
void insertBegin(int ele)
{
lstptr new;
new=getnode();
new->data=ele;
new->link=NULL;
if(first!=NULL)
{
new->link=first;
}
first=new;
}

void insertEnd(int ele)
{
lstptr new,temp;
new=getnode();
new->data=ele;
new->link=NULL;
if(first!=NULL)
{
temp=first;
while(temp->link!=NULL)
temp=temp->link;
temp->link=new;
}
else
{
first=new;
}
}


void deleteBegin()
{
lstptr temp;
if(first==NULL)
{
printf("List is empty\n");
return;
}
temp=first;
if(first->link==NULL)
{
first=NULL;
}
else
{
first=first->link;
}
free(temp);
}


void deleteEnd()
{
lstptr temp,prev;
if(first==NULL)
{
printf("List is empty\n");
return;
}
temp=first;
if(first->link==NULL)
{
first=NULL;
}
else
{
prev=temp;
while(temp->link!=NULL)
{
prev=temp;
temp=temp->link;
}
prev->link=NULL;
}
free(temp);
}


void deleteSpecific(int ele)
{
lstptr temp,prev;
temp=first;
if(first==NULL)
{
printf("List is empty\n");
}
else if(first->data==ele)
{
if(first->link!=NULL)
first=first->link;
else
first=NULL;
}
else
{
while(temp->data!=ele&&temp->link!=NULL)
{
prev=temp;
temp=temp->link;
}
if(temp->link==NULL&&temp->data!=ele)
{
printf("Element in the list not found");
return;
}
else if(temp->link!=NULL)
prev->link=temp->link;
else
prev->link=NULL;
}
free(temp);
}

void display()
{
 lstptr temp;
   if(first==NULL)
{
  printf("List is empty\n");
   return;
  }
   temp=first;
   while(temp->link!=NULL)
{
  printf("%d\t",temp->data);
temp=temp->link;
}
printf("%d\t",temp->data);
}

void main()
{
int opt=1,ch,ele;
while(opt)
{
printf("\n1.Insert Begin\n2.Insert End\n3.Delete Begin\n4.Delete End\n5.Delete Specific\n6.Display\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element to be inserted:");
       scanf("%d",&ele);
       insertBegin(ele);
        break;
case 2:printf("Enter element to be inserted:");
       scanf("%d",&ele);
       insertEnd(ele);
        break;
case 3:deleteBegin();
       break;
case 4:deleteEnd();
       break;
case 5:printf("Enter element to be deleted:");
       scanf("%d\t",&ele);
       deleteSpecific(ele);
       break;
case 6:display();
       break;
 }
}
}
