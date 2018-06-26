//Reverse a lined list, concatenate two linked lists, count no of nodes of a linked list
#include  <stdio.h>
#include  <conio.h>

struct  node		/*Since node is a basic element of a Linked List 
                          we create a new datatype node using structures.*/
{ 
  int  data ;           
  struct  node  *next ;
} ;

struct  node *first=NULL ;
struct node *first1=NULL,*first2=NULL;  /*Pointers pointing head of respective Linked List.*/

/* This function creates the linked list. */
void create(int flag)     /*When flag=1 it creates first Linked list and if flag=2 it creates second Linked List.*/
{
  int  i , n ;
  struct  node  *pnode , *p ;

  first=NULL ;

  printf("Enter the number of nodes required:\n") ;
  scanf("%d",&n) ;

  printf("Enter the data value of each node:\n") ;
  for(i=1 ; i<=n ; i++)
  {
    pnode=(struct node*)malloc(sizeof(struct node)) ;  /*Dynamic memory allocation of new node.*/
    if(pnode==NULL)
    {
      printf("Memory overflow. Unable to create.\n") ;
      getch() ;
      exit(1);
    }

    scanf("%d",&pnode->data) ;

    /* New node will be the last node */
    pnode->next=NULL ;

    if(first==NULL)
      first=p=pnode ;
    else
    {
p->next=pnode ;
p=pnode ;   /* p keeps track of last node */
    }
  }
 if(flag==1)
	first1=first;
 else
	first2=first;
}

/* This function will display data value of each node */
void  display(int flag)
{
  struct  node  *p ;
  if(flag==1)
	first=first1;
  else
	first=first2;
  if(first==NULL)
    printf("Linked List Empty!!!\n") ;
  else
  {
    p=first ;
    while(p!=NULL)
    {
      printf("%d ",p->data) ;
      p=p->next ;
    }

    printf("\n") ;
  }
}

/* This function will concatenate contents of first and second linked list */
struct node*  concatenate(struct node *f1,struct node *f2)
{
  struct  node  *p;
  if(f1==NULL&&f2==NULL)
	return;
  else if(f1==NULL)
	f1=f2;
  else if(f2==NULL)
	return;
  else
  {
	p=f1;
	while(p->next!=NULL)
	p=p->next;       /*While loop will terminate when p will point to the last node.*/
	p->next=f2;
	return f1;
  }
}

/* This function will reverse a given linked list */
struct node* reverse(int flag)
{
  struct  node  *p , *rear , *front ;
  if(flag==1)
	first=first1;
  else
	first=first2;
  p=first ;
  rear=front=NULL ;
  while(p!=NULL)
  {
    front=p->next ;
    p->next=rear ;
    rear=p ;
    p=front ;
  }
  first=rear;
  return first;
}

/* This function will count the number nodes in Linked List */
void count(int flag)
{
  int  n=0 ;
  struct  node  *p ;
  if(flag==1)
	first=first1;
  else
	first=first2;
  p=first;
  while(p!=NULL)
  {
    n++ ;
    p=p->next ;
  }

  printf("%d \n",n) ;
}

 void main()
 {
  int ch,n;
  char c;
  clrscr();
  do
  {
  printf("\n\n-------MENU-------\n");
  printf("Enter your choice\n");
  printf("1.Create the linked list\n");
  printf("2.Dislay the linked list\n");
  printf("3.Count number of nodes in a linked list\n");
  printf("4.Concatenate two linked list\n");
  printf("5.Reverse a linked list\n");
  printf("6.Exit\n");
  scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      printf("Creating first Linked List!!!\n");
      create(1);
      printf("\nDo you want to create second Linked List (Y/N)???:\n");
      scanf("%s",&c);
      if(c=='Y'||c=='y')
	create(2);
      break ;

      case 2:
      printf("First Linked List is \n");
      display(1) ;
      printf("Second Linked List is \n");
      display(2);
      break ;

      case 3:
      if(first1==NULL)
	printf("Linked list 1 is empty!!!\n");
      else
	{
	 printf("Number of nodes in first Linked List is \n");
	 count(1) ;
	 }
      if(first2==NULL)
	printf("Linked list 2 is empty!!!\n");
      else
	{
	 printf("Number of nodes in second Linked List is \n");
	 count(2) ;
	 }
      break ;

      case 4:
	first1=concatenate(first1,first2) ;
      printf("Concatenated Linked List:\n") ;
      if(first1==NULL&&first2==NULL)
	{
	 printf("First create two Linked Lists!!!\n");
	 printf("Enter choice 1 to create...\n");
	 }
      display(1) ;
      break ;

      case 5:
      printf("Reversing first Linked List is \n");
      first1=reverse(1);
      if(first1==NULL)
	{
	 printf("First create a Linked List!!!\n");
	 printf("Enter choice 1 to create...\n");
	  }
      else
	 printf("First linked list is reversed\n");
      printf("Reversing second linked list\n");
      first2=reverse(2);
      if(first2==NULL)
	{
	 printf("First create a Linked List!!!\n");
	 printf("Enter choice 1 to create...\n");
	  }
      else
	printf("Second linked list is reversed\n");
      break;
      case 6:
      break ;
      }     //End of switch case
     } while(ch!=6);     //End of do-while loop
     getch();
    }       //End of main