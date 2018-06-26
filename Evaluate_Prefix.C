// Evaluation of prefix expression
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define ST_SIZE 20
int top=-1;
int stack[ST_SIZE];
void push(int );
int pop();

void main()
{
 int i,length,result,value,opr1,opr2;
 char prefix[10];
 clrscr();
 printf("Enter the prefix expression in the given form (+-341) : ");
 gets(prefix);
 length=strlen(prefix);
 for(i=length-1;i>=0;i--)
  {
   if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/')
    {
     opr1=pop();
     opr2=pop();
     switch(prefix[i])
      {
       case '+':
		result=opr1+opr2;
		break;
       case '-':
		result=opr1-opr2;
		break;
       case '*':
		result=opr1*opr2;
		break;
       case '/':
		result=opr1/opr2;
		break;
	}  // End of switch
       push(result);
       }  // End of if statement
   else
    {

     value=prefix[i]-'0';
     push(value);
     }
    }  // End of for loop
 printf("result is %d",stack[0]);
 getch();
 }
void push(int value)
 {
  top++;
  stack[top]=value;
  }

int pop()
 {
  return(stack[top--]);
  }

