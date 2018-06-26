/*This program is implemented by Ojas Kapre */

#include <stdio.h>
#include <conio.h>

int a[50],count=0;

void insert(int x)
{
 int i=count,temp;
 a[count++]=x;
 while(a[i]>a[(i-1)/2]&&i>=0)
 {
	temp=a[i];
	a[i]=a[(i-1)/2];
	a[(i-1)/2]=temp;
	i=(i-1)/2;
 }
}

void delete()
{
 if(count!=0)
 {
  int i=0,j,temp;
  a[0]=a[--count];
  if(a[1]>a[2])
 	j=1;
  else
	j=2;
  while(a[i]>a[j]&&i<=count)
  {
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	i=j;
	if(a[(2*i+1)/2]>a[(2*i+1)/2])
		j=(2*i+1)/2;
	else
		j=(2*i+2)/2;
  }
 }
}
void main()
{
 int choice,x,i;
 clrscr();
 do
 {
  printf("1.Insert\n");
  printf("2.Remove\n");
  printf("3.Display\n");
  printf("4.Exit\n");
  printf("Enter your choice:");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	printf("Enter number to be inserted:\n");
	scanf("%d",&x);
	insert(x);
	break;

   case 2:
	printf("Number deleted is %d\n",a[0]);
	delete();
	break;

   case 3:
	for(i=0;i<count;i++)
		printf("%d ",a[i]);
	printf("\n");
	break;

   case 4:
	exit(-1);
   }
   }while(choice!=4);
}