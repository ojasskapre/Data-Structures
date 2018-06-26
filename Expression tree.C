/*..This program is implemented by Ojas Kapre.
   In this program we create an expression tree and convert postfix expression
   to prefix and infix form...*/

#include <stdio.h>
#include <conio.h>
/*..Structure specification of a node of an expression tree..*/
typedef struct node
{
 char data;
 struct node *left,*right;
}node;
/*..Structure specification of a stack..*/
typedef struct stack
{
 int top;
 node* items[50];
}stack;
/*..Function prototypes..*/
node* createtree(char ps[]);
void preorder(node *root);
void inorder(node *root);
void push(stack *ps,node *ptr);
node* pop(stack *ps);

void main()
{
 char ps[50];
 node *root=NULL;
 clrscr();
 printf("Enter the postfix string:\n");
 gets(ps);
 root=createtree(ps);
 printf("Given expression in infix form is \n");
 inorder(root);
 printf("\nGiven expression in prefix form is \n");
 preorder(root);
 getch();
}
/*..This function creates the expression tree..*/
node* createtree(char ps[])
{
 int i;
 node *pnode,*opr1,*opr2;
 stack stk;
 stk.top=-1;    /*..Initializing stack to be empty..*/

 for(i=0;ps[i]!='\0';i++)     /*Scanning the entered postfix string..*/
 {
  /*..If it is a operand , store it in a node and push it in the stack..*/
  if((ps[i]>='a'&&ps[i]<='z')||(ps[i]>='A'&&ps[i]<='Z'))
  {
   pnode=(node*)malloc(sizeof(node));
   pnode->data=ps[i];
   pnode->right=pnode->left=NULL;
   push(&stk,pnode);
  }
  /*..Else if it is an operator pop two operand nodes from the stack , perform
  required operation and push it in the stack..*/
  else
  {
   pnode=(node*)malloc(sizeof(node));
   pnode->data=ps[i];
   opr2=pop(&stk);
   opr1=pop(&stk);
   pnode->left=opr1;
   pnode->right=opr2;
   push(&stk,pnode);
  }
 }
 return(pop(&stk));
}
/*..This function inserts the node into the stack..*/
void push(stack *ps,node *ptr)
{
 ps->items[++(ps->top)]=ptr;
}
/*..This function pops node from the stack..*/
node* pop(stack *ps)
{
 return(ps->items[(ps->top)--]);
}
/*..This function traverses the expression tree in preorder i.e. it converts
    postfix to prefix..*/
void preorder(node *root)
{
 if(root!=NULL)
 {
	printf("%c",root->data);  /*Visit the root*/
	preorder(root->left);     /*Traverse left subtree in preorder*/
	preorder(root->right);    /*Traverse right subtree in preorder*/
 }
}
/*..This function traverses the expression tree in inorder i.e. it converts
    postfix to infix..*/
void inorder(node *root)
{
 if(root!=NULL)
 {
	if(root->left!=NULL&&root->right!=NULL)
		printf("(");
	inorder(root->left);      /*Traverse left subtree in inorder*/
	printf("%c",root->data);  /*Visit the root*/
	inorder(root->right);     /*Traverse right subtree in inorder*/
	if(root->left!=NULL&&root->right!=NULL)
		printf(")");
 }
}