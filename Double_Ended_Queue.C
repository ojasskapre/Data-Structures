/*1611022          Ojas kapre       A2*/

//Double Ended Queue data structure
#include <stdio.h>
#include <conio.h>
#define Q_SIZE 5
int front=-1;			/*Since they are globally declared there is no need
			  of passing it to a function*/
int rear=-1;
int queue[Q_SIZE];

void insertFront();           //Function declaration
void insertRear();            //Function declaration
void deleteFront();           //Function declaration
void deleteRear();            //Function declaration
void display();               //Function declaration

void main()
{
 int choice,i,temp,temp1;
 clrscr();
 while(1)
 {
  printf("1.Insert an element from rear end\n2.Delete an element from front end\n3.Insert an element from front end\n4.Delete an element from rear end\n5.Display the queue\n6.Exit\n");
  printf("Enter your choice : ");
  scanf("%d",&choice);
  switch(choice)
   {
   case 1://Insertion from rear end
	 insertRear();	        //Function call
	 break;
   case 2://Deletion from front end
	 deleteFront();		//Function call
	 break; 
   case 3://Insertion from front end
	  insertFront();	//Function call
	  break;
   case 4://Deletion from rear end
	 deleteRear();		//Function call
	 break;
    case 5://Display the queue
	  display();		//Function call
	     break;
    case 6://Exit
	   exit(1);
    default :
	     printf("Invalid choice\n");
    }    //switch case ends
  }     //while loop ends
}      //end of main
void insertFront()			//Function Declaration
{
  if(front==0)       //Condition to check if the queue is full
	   {
	    printf("Queue is full from front end\nDelete some elements from front end\n\n");
	     }
	  else
	   {
	    front--;
	    printf("Enter element to be inserted : ");
	    scanf("%d",&queue[front]);
	     }
 }
void insertRear()			//Function Declaration
{
  if(rear>=Q_SIZE-1)       //Condition to check if the queue is full
	   {
	    printf("Queue is full from rear end\nDelete some elements from rear end\n\n");
	     }
	  else
	   {
	    front=0;
	    rear++;
	    printf("Enter element to be inserted : ");
	    scanf("%d",&queue[rear]);
	    }
  }
void deleteFront()			//Function Declaration
{
  int temp;
  if(front>rear||front==-1)   //Condition to check if the queue is empty from front end
	   {
	     printf("Queue is empty from front end\nInsert some elements from front end\n\n");
	     }
	  else
	   {
	    temp=queue[front];
	    front++;
	    printf("Deleted element is %d\n\n",temp);
	     }
  }
void deleteRear()			//Function Declaration
{
  int temp1;
  if(rear<front||front==-1)    //Condition to check if the queue is empty from rear end
	   {
	    printf("Queue is empty from rear end\nInsert element to the rear end\n");
	     }
	  else
	   {
	    temp1=queue[rear];
	    rear--;
	    printf("Number deleted is %d\n",temp1);
	    }
  }
void display()			//Function Declaration
{
  int i;
  printf("Entered queue is \n");
	   for(i=front;i<=rear;i++)
	    {
	     printf("%d\t",queue[i]);
	     }
	     printf("\n\n");
 }