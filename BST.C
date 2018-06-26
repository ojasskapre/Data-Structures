/*...This program is implemented by Ojas Kapre.
     In this program we have created a binary search tree and performed
     various operations on it...*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*...Structure specification of a node of BST...*/
typedef struct node
{
 int data;
 struct node *left,*right;
}node;

node *root=NULL;  /*root is globally declared. So it is not necessary to pass it to every function
		    because change made at one function will get reflected in entire program*/

/*Function prototypes*/
void createnode();
void deletenode();
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
void destroytree(node *root);

void main()
{
 int choice;
 clrscr();
 do
 {
  printf("\n--------Menu--------\n");
  printf("1.Insert\n");
  printf("2.Delete\n");
  printf("3.Traverse\n");
  printf("4.Exit\n");
  printf("Enter you choice:\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	createnode();
       break;
   case 2:
	deletenode();
	break;
   case 3:
	printf("BST in preorder form is \n");
	preorder(root);
	printf("\nBST in inorder form is \n");
	inorder(root);
	printf("\nBST in postorder form is \n");
	postorder(root);
	break;
   case 4:
	break;
  }
 }while(choice!=4);
  destroytree(root);
  getch();
}

void createnode()
{
 int i,n;
 node *pnode,*p,*follow;  /*pnode will always point to the new node ,
			    p will be used to find location where insertion is to be made,
			    follow will follow p*/
 printf("Enter no of nodes:\n");
 scanf("%d",&n);
 printf("Enter data of each node:\n");
 for(i=1;i<=n;i++)
 {
  pnode=(node*)malloc(sizeof(node));   /*Creating the new node*/
  if(pnode==NULL)
  {
	printf("Memory overflow.Unable to create!!!");
	return;
  }
  scanf("%d",&pnode->data);
  pnode->left=pnode->right=NULL;
  if(root==NULL)
	root=pnode;   /*New node will be te root if tree is empty */
  else
  {
   /*Searching the location to insert the node*/
   p=root;
   follow=NULL;
   while(p!=NULL)
   {
	follow=p;
	if(p->data>pnode->data)
		p=p->left;
	else
		p=p->right;
   }
   /*Actual Insertion*/
   if(pnode->data<follow->data)
	follow->left=pnode;
   else
	follow->right=pnode;
  }
 }
}

void deletenode()
{
 /*p will point to the node to be deleted and follow will follow p ,
   "is" will point to the inorder successor of p and "fis" will follow "is".*/
 node *p,*follow,*is,*fis;
 int key;  /*key is the element to be deleted*/
 printf("Enter the node to be deleted:\n");
 scanf("%d",&key);
 /*Searching the node to be deleted...*/
 p=root;
 follow=NULL;
 while(p!=NULL)
 {
	if(p->data==key)
		break;
	follow=p;
	if(p->data<key)
		p=p->right;
	else
		p=p->left;
 }
 if(p==NULL)
	printf("Node not found!!\n");
 else
 /*Deleting leaf node or node with empty left sub tree...*/
 if(p->left==NULL)
	if(p!=root)
		if(follow->left==p)
			follow->left=p->right;
		else
			follow->right=p->right;
	else
		root=p->right;
 /*Deleting node with empty right sub tree...*/
 else if(p->right==NULL)
		if(p!=root)
			if(follow->right==p)
				follow->right=p->left;
			else
				follow->left=p->left;
		else
			root=p->left;
 /*Deleting node having both non empty subtree*/
 else
 {
  /*The node to be deleted should be replaced by its inorder successor*/
  /*Finding inorder successor...*/
  is=p->right;
  fis=p;
  while(is->left!=NULL)
  {
	fis=is;
	is=is->left;
  }
  /*Now "is" will point to the inorder successor of p*/
  /*Storing inorder successor in node to be deleted*/
  p->data=is->data;
  if(fis!=p)
	fis->left=is->right;
  else
	fis->right=is->right;
  p=is;
 }
free(p); /*De-allocates the memory of node pointed by p.*/
}

void preorder(node *root)
{
 if(root!=NULL)
 {
	printf("%d ",root->data);  /*Visit the root*/
	preorder(root->left);     /*Traverse left subtree in preorder*/
	preorder(root->right);    /*Traverse right subtree in preorder*/
 }
}

void inorder(node *root)
{
 if(root!=NULL)
 {
	inorder(root->left);      /*Traverse left subtree in inorder*/
	printf("%d ",root->data);  /*Visit the root*/
	inorder(root->right);     /*Traverse right subtree in inorder*/
 }
}

void postorder(node *root)
{
 if(root!=NULL)
 {
	postorder(root->left);     /*Traverse left subtree in postorder*/
	postorder(root->right);    /*Traverse right subtree in postorder*/
	printf("%d ",root->data);   /*Visit the root*/
 }
}

void destroytree(node *root)
{
 if(root!=NULL)
 {
	destroytree(root->left);     /*Traverse left subtree in postorder*/
	destroytree(root->right);    /*Traverse right subtree in postorder*/
	free(root);                  /*Visit the root*/
 }
}


