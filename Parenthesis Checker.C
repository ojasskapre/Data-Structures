#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 50

typedef struct stack
{
 int top;
 char items[SIZE];
}stack;

void push(stack *ps,char x)
{
 ps->items[++(ps->top)]=x;
}

char pop(stack *ps)
{
 return ps->items[(ps->top)--];
}

int empty(stack *ps)
{
 if(ps->top==-1)
	return 0;
 else
	return 1;
}

void main()
{
 char a[50],x,y;
 int i,flag=1;
 stack s;
 s.top=-1;
 printf("Enter an expression:\n");
 gets(a);
 for(i=0;i<strlen(a)&&flag==1;i++)
 {
  x=a[i];
  if(x=='('||x=='['||x=='<'||x=='{')
	push(&s,x);
  if(empty(&s))
	printf("No parenthesis in expression\n");
  else
  {
   y=pop(&s);
   if((y=='('&&x=')')||(y=='{'&&x=='}')||(y=='['&&x==']')||(y=='<'&&x='>'))
	flag=1;
   else
	flag==0;
  }
 }
 if(flag)
	printf("Expression parenthesized\n");
 else
	printf("Expression not parenthesized\n");
}

