#include<stdio.h>
#include<ctype.h>
char stack[100],postfix[100],infix[100];
int top=-1;
void push(char);
char pop();
int preced(char);
void infixtopostfix();
void push(char symbol)
{
stack[++top]=symbol;
}
char pop()
{
char symbol;
symbol=stack[top--];
return symbol;
}
int preced(char symbol)
{
switch(symbol)
{
case '$':return -1;
case '(':return 0;
case '-':
case '+':return 1;
case '*':
case '/':return 2;
}
}
void infixtopostfix()
{
int i=0,k=0;
char symbol;
while((symbol=infix[i++])!='\0')
{
if(symbol=='(')
push(symbol);
else if(symbol==')')
{
while(stack[top]!='(')
postfix[k++]=pop();
}
else if(isalnum(symbol))
{
postfix[k++]=symbol;
}
else
{
while(preced(symbol)<=preced(stack[top]))
{
postfix[k++]=pop();
}
push(symbol);
}
}
while(stack[top]!='$')
{
if(stack[top]=='(')
pop();
else
postfix[k++]=pop();
}
}
void main()
{
printf("enter infix expression:");
scanf("%s",infix);
infixtopostfix();
printf("postfix expression is:");
puts(postfix);
}


