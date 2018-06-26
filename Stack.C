// Stack Data Structure
#include <stdio.h>
#include <conio.h>
#define ST_SIZE 5
int top=-1;
int stack[ST_SIZE];
void push();
int pop();
void display();

void main()
{
 int choice;
 clrscr();
 while(1)
  {
   printf("1.Push an element in the stack\n2.Pop an element from the stack\n3.Display\n4.Exit\n");
   printf("Enter your choice : ");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:// Inserting an element in the stack
	   push();
	   break;
    case 2:// Deleting an element from the stack
	   pop();
	   break;
    case 3://Dislay the elements of the stack
	   display();
	   break;
    case 4:
	   exit(1);
    default:
	    printf("Invalid choice\n");
    }      //End of switch
   }      //End of while
  }   //End of main
//Function for inserting an element in the stack
void push()
{
 if(top>=ST_SIZE-1)
 {
  printf("Stack is full\nRemove some elements\n\n");
  }
 else
 {
  top++;
  printf("Enter element to be inserted : ");
  scanf("%d",&stack[top]);
  }
 }

//Function for deleting an element from the stack
int pop()
{
 if(top==-1)
 {
  printf("Stack is empty\nInsert some elements\n\n");
  return(1);
  }
 else
 {
  printf("Number deleted is %d\n",stack[top]);
  top--;
  return(1);
  }
}

//Function to display the stack
void display()
{
 int i;
 printf("Stack is \n");
 for(i=top;i>=0;i--)
 {
  printf("%d\n",stack[i]);
  }
 }