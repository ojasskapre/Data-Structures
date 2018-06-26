//Simple Queue data structure
#include <stdio.h>
#include <conio.h>
#define Q_SIZE 20
int front=-1;
int rear=-1;
int queue[Q_SIZE];
void main()
{
 int choice,i,temp;
 clrscr();
 while(1)
 {
  printf("1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
  printf("Enter your choice : ");
  scanf("%d",&choice);
  switch(choice)
   {
    case 1://Insertion of an element
	   if(rear>=Q_SIZE-1)       //Condition to check if the queue is full
	    {
	     printf("Queue is full\nDelete some elements\n\n");
	     }
	    else
	     {
	      front=0;
	      rear++;
	      printf("Enter element to be inserted : ");
	      scanf("%d",&queue[rear]);
	      }break;
    case 2://Deletion of an element
	   if(front>rear||front==-1)   //Condition to check if the queue is empty
	    {
	     printf("Queue is empty\nInsert some elements\n\n");
	     }
	    else
	     {
	      temp=queue[front];
	      front++;
	      printf("Deleted element is %d\n\n",temp);
	      }break;
    case 3://Display the queue
	   printf("Entered queue is \n");
	   for(i=front;i<=rear;i++)
	    {
	     printf("%d\t",queue[i]);
	     }
	     printf("\n\n");
	     break;
    case 4://Exit
	   exit(1);
    default :
	     printf("Invalid choice\n");
    }
  }
}