/*...This program is implemented by Ojas Kapre. In this program, we have added two polynomials using linked lists.
  We accept two unsorted polynomials from the user, then sort the polynomials and then add them...*/

#include <stdio.h>
#include <malloc.h>
#include <conio.h>

typedef struct nodes                   /*..Structure specification of nodes of the Linked List..*/
	{
		int c,pwx,pwy,pwz;   	       
		struct nodes *next;
	}node;

node* create(node* start)             //to create a linked list
{
	node *pnode,*prev;
	char ch='y';
	int count,c,pwx,pwy,pwz;
	count=0;
	prev=start;
	do
	{       count++;
		pnode=(node*)malloc(sizeof(node));               /*..memory allocation..*/
		if(pnode==NULL)
		{
		printf("Error in memory allocation\n");
		}
		else
		{
		printf("Enter values of coefficient and the degrees of x,y,z in order for term %d\n",count);
		scanf("%d%d%d%d",&c,&pwx,&pwy,&pwz);                 
		pnode->c=c;
		pnode->pwx=pwx;
		pnode->pwy=pwy;
		pnode->pwz=pwz;
		pnode->next=NULL;
		prev->next=pnode;
		prev=pnode;
		if(start==NULL)                      /*..for first node...start becomes the head..*/
		start=pnode;
		}
		printf("Do you want to make another entry (Y/N)\n");
		ch=getch();
	}while(ch=='y'||ch=='Y');
 return start;
}

void sort(node *start)          //Function to sort the user entered polynomial in decreasing order of degree
{
	node *i,*j;
	int swap;  	//temporary variable
	i=start;

	while(i!=NULL)
	{
	j=i->next;
	   while(j!=NULL)
	   {
	     if((j->pwx > i->pwx) || ((j->pwx==i->pwx)&&(j->pwy > i->pwy)) || ((j->pwx==i->pwx) && (j->pwy==i->pwy) &&(j->pwz > i->pwz)))
	     {
		swap=j->c;
		j->c=i->c;
		i->c=swap;
		swap=j->pwx;
		j->pwx=i->pwx;
		i->pwx=swap;
		swap=j->pwy;
		j->pwy=i->pwy;
		i->pwy=swap;
		swap=j->pwz;
		j->pwz=i->pwz;
		i->pwz=swap;
	     }
	     j=j->next;
	   }                                 //end of j loop
	     i=i->next;
	}                                    //end of i loop

}
node* add(node *start1,node *start2,node *start3)
{
node *pnode1=start1,*pnode2=start2,*pnode3=start3,*prev3;
	while(pnode1!=NULL||pnode2!=NULL)        //loop continues till both lists are empty
	{
	   pnode3=(node*)malloc(sizeof(node)); //memory allocation for answer node
		if(pnode3==NULL)
		{
		printf("Error in memory allocation\n");
		}
		else
		{
			if((pnode1!=NULL)&&(pnode2!=NULL)&&(pnode1->pwx==pnode2->pwx)&&(pnode1->pwy==pnode2->pwy)&&(pnode1->pwz==pnode2->pwz))
			{
				pnode3->c=pnode1->c+pnode2->c;     //  when the two terms have equal degree...we add the coefficients
				pnode3->pwx=pnode1->pwx;
				pnode3->pwy=pnode1->pwy;
				pnode3->pwz=pnode1->pwz;

				pnode1=pnode1->next;             //traverse forward in list 1
				pnode2=pnode2->next;             //traverse forward in list 2
			}
			else if((pnode2==NULL)||(pnode1->pwx>pnode2->pwx)||(pnode1->pwx==pnode2->pwx&&pnode1->pwy>pnode2->pwy)||(pnode1->pwx==pnode2->pwx&&pnode1->pwy==pnode2->pwy&&pnode1->pwz>pnode2->pwz))
			{

				pnode3->c=pnode1->c;       		//if term in list 1 is greater...copy in list 3
				pnode3->pwx=pnode1->pwx;
				pnode3->pwy=pnode1->pwy;
				pnode3->pwz=pnode1->pwz;

				pnode1=pnode1->next;
			}
			else if((pnode1==NULL)||(pnode2->pwx>pnode1->pwx)||(pnode2->pwx==pnode1->pwx&&pnode2->pwy>pnode1->pwy)||(pnode2->pwx==pnode1->pwx&&pnode2->pwy==pnode1->pwy&&pnode2->pwz>pnode1->pwz))
			{
				pnode3->c=pnode2->c;                //if term in list 2 is greater...copy in list 3
				pnode3->pwx=pnode2->pwx;
				pnode3->pwy=pnode2->pwy;
				pnode3->pwz=pnode2->pwz;

				pnode2=pnode2->next;
			}
			else
			{
				printf("Error");
				break;
			}

				pnode3->next=NULL;
				prev3->next=pnode3;
				prev3=pnode3;
				if(start3==NULL)
				start3=pnode3;
		}
	}
	return start3;
}

void print(node *start)       // function to print a particular list
{
	node *pnode;
	pnode=start;
	while(pnode!=NULL)
	{
		printf("[(%d).x^%d.y^%d.z^%d]",pnode->c,pnode->pwx,pnode->pwy,pnode->pwz);
		pnode=pnode->next;
		if(pnode!=NULL)
		printf("+");

	}
}


void main()
{
node *n1=NULL,*n2=NULL,*n3=NULL;
clrscr();
printf("Creating Polynomial 1\n");
	n1=create(n1);      //create list 1
	sort(n1);           //sort list 1
printf("Creating Polynomial 2\n");
	n2=create(n2);      //create list 2
	sort(n2);           //sort list 2
clrscr();
printf("\nPolynomial 1\n");
	print(n1);        //  print list 1
printf("\nPolynomial 2\n");
	print(n2);          // print list 2
	n3=add(n1,n2,n3);                     //add two polynomials and store result in list 3
printf("\nAddition of Polynomials 1 and 2 is\n");
	print(n3);          //display the answer stored in list 3
getch();

}