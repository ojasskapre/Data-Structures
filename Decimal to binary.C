/*...This program is implemented by Ojas Kapre 1611022.
   In this program we have converted decimal to binary using stack data structures...*/
#include  <stdio.h>
#include  <conio.h>
#define  STACKSIZE  50

struct  stack
{
  int  top ;
  int  items[STACKSIZE] ;
} ;
/* Assuming that stack consists of integers */

void  push(struct  stack  *ps , int  x)
{
  if(ps->top==STACKSIZE-1)
  {
    printf("Stack Overflow. Cannot push \n") ;
    getch() ;
    exit(1) ; /* terminates program */
  }
  ps->items[++(ps->top)]=x ;
}

int  empty(struct  stack  *ps)
{
  if(ps->top==-1)
    return  1 ;
  else
    return  0 ;
}

int  pop(struct  stack  *ps)
{
  return (ps->items[(ps->top)--]) ;
}

void main()
{
  int  n , r , x ;
  struct  stack  s ;

  clrscr() ;

  s.top=-1 ;

  printf("Enter an integer: ") ;
  scanf("%d",&n) ;

  while(n>0)
  {
    r = n % 2 ;    
    push(&s,r) ;	  
    n = n / 2 ;
  }

  printf("Binary equivalent is: ") ;
  while(!empty(&s))
  {
    x=pop(&s);	  
    printf("%d" , x) ;  
  }

  getch() ;
}