/*
11.Write a C++ program to traverse the below graph using Depth first traversal and
Breadth first traversal .
*/
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>

struct node  // Structure for elements in the graph
{  char data;
   int status;
   struct node *next;
   struct link *adj;
}*start,*p,*q;

struct link  // Structure for adjacency list
{
   struct node *next;
   struct link *adj;
}*l,*k;
void create()    // Creating a graph
{
   int flag=0;
   char dat;
   start=NULL;
   cout<<"Enter the nodes in the graph(0 to end): ";
   while(1)
   {
      cin>>dat;
      if(dat=='0')
      	 break;
      p=new node;
      p->data=dat;
      p->status=0;
      p->next=NULL;
      p->adj=NULL;
      if(flag==0)
      {
    	 start=p;
    	 q=p;
    	 flag++;
      }
      else
      {
    	 q->next=p;
    	 q=p;
      }
   }
   p=start;
   while(p!=NULL)
   {
      cout<<"Enter the links to "<<p->data<<" (0 to end) : ";
      flag=0;
      while(1)
      {
    	 cin>>dat;
    	 if(dat=='0')
    	    break;
    	 k=new link;
    	 k->adj=NULL;
    	 if(flag==0)
    	 {
    	    p->adj=k;
    	    l=k;
    	    flag++;
    	 }
    	 else
    	 {
    	    l->adj=k;
    	    l=k;
    	 }
    	 q=start;
    	 while(q!=NULL)
    	 {
    	    if(q->data==dat)
    	       k->next=q;
    	    q=q->next;
    	 }
          }
          p=p->next;
   }
   cout<<"-------------------------";
   return;
}


// Breadth First Search(DFS) Traversal.
void bfs()
{   char qu[20];
   int i=1,j=0;
   p=start;
   while(p!=NULL)
   {
      p->status=0;
      p=p->next;
   }
   p=start;
   qu[0]=p->data;
   p->status=1;
   while(1)
   {
      if(qu[j]==0)
	 break;
      p=start;
      while(p!=NULL)
      {
    	 if(p->data==qu[j])
    	     break;
    	 p=p->next;
      }
      k=p->adj;
      while(k!=NULL)
      {
	 q=k->next;
	 if(q->status==0)
	 {
	    qu[i]=q->data;
	    q->status=1;
	    qu[i+1]=0;
	    i++;
	 }
	 k=k->adj;
      }
      j++;
   }
   j=0;
   cout<<"Breadth First Search Results";
   cout<<"---------------------------";
   while(qu[j]!=0)
   {
      cout<<qu[j]<<"  ";
      j++;
   }
}
//Depth First Search(BFS) Traversal.
void dfs()
{  char stack[25];
   int top=1;
   cout<<"Depth First Search Results";
   cout<<"---------------------------";
   p=start;
   while(p!=NULL)
   {
      p->status=0;
      p=p->next;
   }
   p=start;
   stack[0]=0;
   stack[top]=p->data;
   p->status=1;
   while(1)
   {
      if(stack[top]==0)
	 break;
      p=start;
      while(p!=NULL)
      {
	 if(p->data==stack[top])
	    break;
	 p=p->next;
      }
      cout<<stack[top]<<"  ";
      top--;
      k=p->adj;
      while(k!=NULL)
      {
	 q=k->next;
	 if(q->status==0)
	 {
	    top++;
	    stack[top]=q->data;
	    q->status=1;
	 }
	 k=k->adj;
      }
   }
}

int main()
{
    create();
    bfs();
    cout<<"\n\n";
    dfs();
    getch();
    return 0;
}
