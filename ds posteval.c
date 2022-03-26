#include<stdio.h>
#include<ctype.h>
#include<math.h>
char postfix[50],stack[50];
int top=-1;
void push(char);
char pop();
int eval();
int eval()
{
char symb;
int i=0,op1,op2;
while((symb=postfix[i++])!='\0')
{
if(isalnum(symb))
push(symb-'0');
else
{
op2=pop();
op1=pop();
switch(symb)
{
case'+':
push(op1+op2);
break;
case'-':
push(op1-op2);
break;
case'*':
push(op1*op2);
break;
case'/':
if(op2!=0)
{
push(op1/op2);
break;
}
else
{
printf("out of loop");
}
case '^':
push(pow(op1,op2));
break;
default :
printf("inavalid operator");
}
}
}
return(pop());
}
void push(char ele)
{
stack[++top]=ele;
}
char pop()
{
char ele;
ele=stack[top--];
return ele;
}
void main()
{
int val;
printf("enter the postfix expression:\t");
scanf("%s",postfix);
val=eval();
printf("Result:\t %d",val);
}
 
