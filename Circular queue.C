#include <stdio.h>
#include <conio.h>
#define SIZE 5

typedef struct queue
{
 int front,rear;
 int items[SIZE];
}queue;

queue q;
int count=0;

void insert(int x)
{
 if(count==SIZE)
	printf("Queue overflow\n");
 else
 {
  if(q.rear==SIZE-1)
	q.rear=0;
  else
	q.rear++;
  q.items[q.rear]=x;
  count++;
 }
}

void removes()
{
 if(count==0)
	printf("Queue underflow\n");
 else
 {
  printf("Deleted element is %d",q.items[q.front]);
  if(q.front==SIZE-1)
	q.front=0;
  else
	q.front++;
  count--;
 }
}

void display()
{
 int i;
 if(q.front>q.rear)
 {
  for(i=q.front;i<SIZE;i++)
	printf("%d  ",q.items[i]);
  for(i=0;i<=q.rear;i++)
	printf("%d  ",q.items[i]);
 }
 else if(q.front<=q.rear)
 {
  for(i=q.front;i<=q.rear;i++)
	printf("%d  ",q.items[i]);
}
}
void main()
{
 int choice,x;
 q.front=0;
 q.rear=-1;
 clrscr();
 do
 {
  printf("\n1.Insert\n2.Remove\n3.Dispaly\n4.Exit\n");
  printf("Enter your choice:\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
    printf("Enter number to be inserted:\n");
    scanf("%d",&x);
    insert(x);
    break;
   case 2:
    removes();
    break;
   case 3:
    display();
    break;
  }
 }while(choice!=4);
}