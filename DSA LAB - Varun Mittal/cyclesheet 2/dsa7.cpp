/*
7. Write a C++ programs that use (a) non-recursive (b) recursive functions to
traverse the given binary tree in .
• preorder
• inorder
• postorder
*/
#include <iostream>
using namespace std;
struct node
{
 int val;
 node *l;
 node *r;
 int flag;
 int flag1;
 int flag2;
 node(){flag=0;
        flag1=0;
        flag2=0;}
}*root=NULL,*p,*q,*x,*pt[50];
void add()
{
 int key,flag;
 cout<<"Value to be added-";
 cin>>key;
 if(root==NULL)
 {
  root=new node;
  root->val=key;
  root->l=NULL;
  root->r=NULL;
 }
 else
{
  p=root;
  while(p!=NULL)
 {
   q=p;
   if(key<p->val)
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
  x->val=key;
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
void nrpre(int n)
{
x=root;
int count=0,i=0;
while(count<n)
{
if(x->flag==0)
{
cout<<" "<<x->val<<" ";
pt[i++]=x;
x->flag=1;
count++;
}
else
if((x->l!=NULL)&&(x->l->flag==0))
{
x=x->l;
}
else
if((x->r!=NULL)&&(x->r->flag==0))
{
x=x->r;
}
else
{
i=i-1;
x=pt[i];
}
}
}
void nrin(int n)
{
x=root;
int count=0,i=0;
while(count<n)
{
if((x->l!=NULL)&&(x->l->flag1==0))
{
pt[i++]=x;
x=x->l;
}
else
if(x->flag1==0)
{
cout<<" "<<x->val<<" ";
count++;
x->flag1=1;
}
else
if((x->r!=NULL)&&(x->r->flag1==0))
{
x=x->r;
i=i+1;
pt[i]=x;
}
else
{
i=i-1;;
x=pt[i];
}
}
}
void nrpost(int n)
{
int count=0,i=0;
x=root;
while(count<n)
{
if((x->l!=NULL)&&(x->l->flag2==0))
{
pt[i++]=x;
x=x->l;
}
else
if((x->r!=NULL)&&(x->r->flag2==0))
{
x=x->r;
i++;
pt[i]=x;
}
else
if(x->flag2==0)
{
cout<<" "<<x->val<<" ";
count++;
x->flag2=1;
}
else
{
i--;
x=pt[i];
}
}
}
int main()
{
 int n=0;
 char c='y';
 while(c=='y'||c=='Y')
 {
          n++;
          add(); 
    cout<<"Do you want to continue-";
    cin>>c;
 }
cout<<"\nPreorder :";
nrpre(n);
cout<<"\n";
cout<<"\nInorder :";
nrin(n);
cout<<"\n";
cout<<"\nPostorder :";
nrpost(n);
system("pause");
return 0;
}
