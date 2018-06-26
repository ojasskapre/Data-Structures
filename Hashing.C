/*This program is implemented by Ojas Kapre*/
#include<stdio.h>
#include<conio.h>
int input()
{
	int ele;
	scanf("%d", &ele);
	return ele;
}
int hash(int ele, int m)
{
	int r = ele % m;
	return r;
}
int rehashq(int ele, int m, int j)
{
	int r = (ele+j*j) % m;
	return r;
}
int rehash(int ele, int m)
{
	int r = (ele+1) % m;
	return r;
}

void insertq(int a[], int m)
{
	int ele, r,j=1,k;
	ele = input();
	k = hash(ele, m);

	if(a[k] == -1)
		a[k] = ele;
	else
	{       r=k;
		while(a[r] != -1)
		       {
		       r = rehashq(k, m,j);
			j=j+1;}
		a[r] = ele;
	}
}
void insert(int a[], int m)
{
	int ele, r;
	ele = input();
	r = hash(ele, m);
	if(a[r] == -1)
		a[r] = ele;
	else
	{
		while(a[r] != -1)
			r = rehash(r, m);
		a[r] = ele;
	}
}

void searchq(int a[], int m)
{
	int data, r,s,n,j;
	printf("\nEnter the element to be searched: ");
	scanf("%d", &data);
	printf("\n");
	r = data % m;
	if(a[r]==data){
		printf("Position starts from 0\n");
		printf("Element found at position %d",r);
	}
	else
	{
	for(j=1;j<6;j++)
	{
	s=rehashq(r,m,j);
	if(a[s]==data)
	{
	printf("Position starts from 0\n");
	printf("Element found at position %d",s);
	break;
	}
	}
	}
}
void search(int a[], int m)
{
	int data, r;
	printf("\nEnter the element to be searched: ");
	scanf("%d", &data);
	printf("\n");
	r = data % m;
	if(data == a[r])
		printf("The element is found at position %d\n", r);
	else
	{
		while(a[r] != -1)
			r = rehash(r, m);
		if(a[r] != -1 || r != data % m)
			printf("Element found at position %d\n", r-1);
		else
			printf("Element not found");
	}
}

void display(int a[], int m)
{
	int i;
	for(i = 0; i < m; i++)
		printf("%d\t", a[i]);
}
void main()
{

	int a[11], i, m = 11, n,ch;
	clrscr();
	printf("Enter your choice");
	printf("\n1.Quadratic Probing \n2.Linear Probing\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:for(i = 0; i < m; i++)
		a[i] = -1;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for(i = 0; i < n; i++)
		insertq(a, m);
	display(a, m);
	searchq(a, m);
	break;
	case 2:for(i = 0; i < m; i++)
		a[i] = -1;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for(i = 0; i < n; i++)
		insert(a, m);
	display(a, m);
	search(a, m);
	break;
	case 3:break;
	}
	getch();
}
