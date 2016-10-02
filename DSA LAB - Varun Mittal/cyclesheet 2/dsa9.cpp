/*
9. Write a C++ program to perform the following operations on binary search tree of
strings: {Dhanush, Bala, Elumalai, Arun, Bhuvanesh, Himanshu, Garima, Indrajit, Faisal,
James}
• Create a binary search tree
• Insert the following strings into a binary search tree {Harish,Ajay}
• Delete the following strings from above binary search tree{ Bhuvanesh,Arun,
Indrajit, Himanshu}
• Search for a string in a binary search tree {Ajay,Harish}
*/

#include <iostream>
using namespace std;
struct node
{
 char val[30];
 node *l;
 node *r;
}*root=NULL,*p,*q,*x;
void add()
{char key[30]; 
 int flag;
 cout<<"Enter Name to be added-";
 fflush(stdin);
 gets(key);
 if(root==NULL)
 {
  root=new node;
  strcpy(root->val,key);
  root->l=NULL;
  root->r=NULL;
 }
 else
{
  p=root;
  while(p!=NULL)
 {
   q=p;
   if(strcmp(key,p->val)<0)
   {
    flag=0;
    p=p->l;
   }
   else
   {
    flag=1;
    p=p->r;
   }
 }
  x=new node;
  strcpy(x->val,key);
  x->l=NULL;
  x->r=NULL;
 if(flag==0)
 {
  q->l=x;
 }
 else
 {
  q->r=x;
 }
}
}

void inorder(node *x)
{
 if(x!=NULL)
{
  inorder(x->l);
  cout<<"\n"<<x->val;
  inorder(x->r);
} 
}
int search(char s[30],node *y)
{
    if(strcmp(y->val,s)==0)
          return 1;
    else if(y->l==NULL && y->r==NULL)
         return -1;
    else if(strcmp(y->val,s)>0)
          return search(s,y->l);
    else if(strcmp(y->val,s)<0)   
         return search(s,y->r);
    
}
int main()
{
 int n,i;
 char c='y';
 cout<<"\nAdd Names Dhanush, Bala, Elumalai, Arun, Bhuvanesh, Himanshu, Garima, Indrajit, Faisal,James!!\n";
 for(i=0;i<10;i++)
    add();
 inorder(root);
 cout<<"\nAdd Names Harish And Ajay !!\n";
 add();
 add();
 inorder(root);
 x=root;
  cout<<"\nSearching for Harish !";
 i=search("harish",x);
 if(i==1)
         cout<<"\nHarish Found !!!";
 if(i==-1)
         cout<<"\nHarish Not Found !!!";
 cout<<"\nSearching for AJay !";
 x=root;
 i=search("ajay",x);
 if(i==1)
         cout<<"\nAjay Found !!!";
 if(i==-1)
         cout<<"\nAjay Not Found !!!\n";
 system("pause");
 return 0;
}
