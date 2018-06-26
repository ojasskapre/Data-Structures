//Depth first search
#include <stdio.h>
#include <conio.h>

typedef struct Graph
{
 int v;
 int data[10];
}graph;

typedef struct stack
{
 int top;
 int items[10];
}stack;

void push(stack *ps,int x)
{
 ps->items[++(ps->top)]=x;
}

int pop(stack *ps)
{
 return ps->items[(ps->top)--];
}

graph g;
int adj[10][10],visit[10];

int present(stack *ps,int j)
{
 int i;
 for(i=0;i<=ps->top;i++)
	if(ps->items[i]==j)
		return 1;
 return 0;

}

void dfs(int k)
{
 int i,j;
 stack s;
 s.top=-1;
 push(&s,k);
 while(s.top!=-1)
 {
  i=pop(&s);
  visit[i]=1;
  printf("%d ",g.data[i]);
  for(j=0;j<g.v;j++)
   if(adj[i][j]==1&&visit[j]==0&&!present(&s,j))
	push(&s,j);
 }
}

void main()
{
 int i,j;
 printf("Enter no of vertices:\n");
 scanf("%d",&g.v);
 printf("Enter data:\n");
 for(i=0;i<g.v;i++)
	scanf("%d",&g.data[i]);
 printf("Enter adj matrix:\n");
 for(i=0;i<g.v;i++)
 {
  for(j=0;j<g.v;j++)
  {
       /*	printf("Is %d adj to %d ?",g.data[j],g.data[i]);
	printf("Enter 1 if yes or 0 if No\n");     */
	scanf("%d",&adj[i][j]);
  }
 }

 for(i=0;i<g.v;i++)
	visit[i]=0;

 for(i=0;i<g.v;i++)
	if(visit[i]==0)
		dfs(i);
 getch();
}

