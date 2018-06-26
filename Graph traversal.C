/*...This program is implemented by Ojas Kapre .
     In this program, we have taken a graph in the form of adjacency matrix from the user
     and have traversed the graph using different techniques...*/

#include <stdio.h>
#include <conio.h>
#define Q_SIZE 50

typedef struct Graph
{
   int data[10];
   int v;
}Graph;

/*...Structure specification of a graph...*/
typedef struct Queue
{
int front, rear;
int items[Q_SIZE];
}queue;

/*...Function prototypes...*/
int contains (queue, int);
void enqueue (queue*, int);
int dequeue (queue*);
void Visited ();
void dfs (int);
void bfs (int);
void create ();
void display (int);
void createAdjMat ();

Graph G;
int adj[10][10], visited[10];

void main()
{
int i, j, k, ch;
clrscr();

do
{
   printf("\nMENU\n1.Create\n2.DFS\n3.BFS\n4.Exit\nEnter choice: ");
   scanf("%d", &ch);
   switch(ch)
   {
	  case 1 :
	  create();
	  createAdjMat();
	  break;

	  case 2 :
	  Visited();
	  for(i=0; i<G.v; i++)
		 if(!visited[i])
			dfs(i);
	  break;

	  case 3 :
	  Visited();
	  for(i=0; i<G.v; i++)
		 if(!visited[i])
			bfs(i);
   }
}while(ch!=4);
}

/*...Insert element from the rear end of the queue...*/
void enqueue(queue *p, int x)
{
   if(p->rear == Q_SIZE-1)
	  printf("Queue overflow\n");
   else
   {
	  p->items[++(p->rear)]=x;
	  if(p->front==-1);
		 p->front++;
   }
}

/*...Delete elements from the front of the queue...*/
int dequeue(queue *p)
{
   int temp = p->front++;
   if(p->front > p->rear)
	  p->front=p->rear=-1;
   return(p->items[temp]);
}

/*It returns 1 if the element is in the queue else it returns 0 if the element is not present...*/
int contains(queue q, int k)
{
   int i;
   for(i=q.front; i<q.rear; i++)
	  if(q.items[i]==k)
	 return 1;
   return 0;
}

/*...If the node is visited then it changes 1 to 0 in the visited array...*/
void Visited()
{
   int i,j;
   for(i=0; i<G.v; i++)
	  visited[i] = 0;
}

/*...This functions creates a Graph...*/
void create()
{
int i;
printf("Enter number of vertices in the graph: ");
scanf("%d", &G.v);
printf("Enter data of %d vertices:\n", G.v);
for(i=0; i<G.v; i++)
   scanf("%d", &G.data[i]);
}

/*...It displays the visited node...*/
void display (int i)
{
printf("%d ", G.data[i]);
}

/*...This function creates an adjacency of the graph...*/
void createAdjMat ()
{
int i, j;
printf("Enter 1 if yes, 0 if no\n");
for(i=0; i<G.v; i++)
   for(j=0; j<G.v; j++)
   {
	  printf("Is %d adjacent to %d? ", G.data[j], G.data[i]);
	  scanf("%d", &adj[i][j]);
   }
clrscr();
}

/*It traverses by using dfs technique...*/
void dfs (int k)
{
int i;
visited[k]=1;
display(k);
for(i=0; i<G.v; i++)
   if(adj[k][i] && !visited[i])
	  dfs(i);
}

/*It traverses by using bfs technique...*/
void bfs(int k)
{
int i;
queue q;
q.front=q.rear=-1;
enqueue(&q, k);
while(q.front!=-1)
{
   k = dequeue(&q);
   visited[k] = 1;
   display(k);
   for(i=0; i<G.v; i++)
	  if(adj[k][i] && !visited[i])
		 if(!contains(q, i))
			enqueue(&q, i);
}
}