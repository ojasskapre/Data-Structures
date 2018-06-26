//infix to prefix conversion
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 20
void convert(char infix[20], char prefix[20]);
void reverse(char a[30]);
char pop();
void push(char symbol);
int opr(char symbol);
int prcd(char symbol);
int top = -1;
char prefix[20];
int evaluate();
char stack[MAX];

void main()
{
 int a;
 char infix[20],temp;
 clrscr();

 printf("Enter infix expression: ");
 gets(infix);
 convert(infix, prefix);
 reverse(prefix);
 puts((prefix));
 a=evaluate();
 printf("Value of the expression is %d",a);
 getch();
 }    //End of main

void convert(char infix[20], char prefix[20]) //function to convert infix to prefix
{
int i, j = 0;
char symbol;
stack[++top] = ')';
reverse(infix);
for (i = 0; i < strlen(infix); i++) {
symbol = infix[i];
if (opr(symbol) == 0) {
  prefix[j] = symbol;
  j++;

} else {
  if (symbol == ')') {
    push(symbol);
  } else if (symbol == '(') {
    while (stack[top] != ')') {
      prefix[j] = pop();
      j++;
    }
    pop();
  } else {
    if (prcd(stack[top]) <= prcd(symbol)) {
      push(symbol);
    } else {
      while (prcd(stack[top]) > prcd(symbol)) {
	prefix[j] = pop();
	j++;
      }
      push(symbol);
    }
  //end for else
     }
   }
  //end for else
   }
  //end for for
  while (stack[top] != ')') {
    prefix[j] = pop();
    j++;
   }
  prefix[j] = '\0';
 }

 void reverse(char array[30])
 {
 // for reverse of the given expression
 int i, j;
 char temp[100];
 for (i = strlen(array) - 1, j = 0; i + 1 != 0; --i, ++j)
 {
  temp[j] = array[i];
 }
 temp[j] = '\0';
 strcpy(array, temp);//copying temp array to array
  // return array;
 }

  char pop()
  {
   return stack[top--];
   }

 void push(char symbol) {
 top++;
 stack[top] = symbol;
 }

 int prcd(char symbol) {
 // returns the value that helps in the precedence
 switch (symbol) {
  case '+':
   case '-':
    return 2;
    break;
  case '*':
   case '/':
    return 4;
    break;
    break;
   case '(':
   case ')':
    return 1;
    break;
  }
}

int opr(char symbol)
{
 switch (symbol) {
 case '+':
 case '-':
 case '*':
 case '/':
 case '(':
 case ')':
  return 1;
  break;
 default:
  return 0;
 // returns 0 if the symbol is other than given above
  }
 }

int evaluate()
{
 int stk[MAX];
 int i,result,value,opr1,opr2;
 for(i=strlen(prefix)-1;i>=0;i--)
  {
   if(opr(prefix[i])==1)
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
     printf("Enter the value of %c :",prefix[i]);
     scanf("%d",&value);
     push(value);
     }
    }  // End of for loop
 return result;
 }