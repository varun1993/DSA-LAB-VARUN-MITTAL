/*
8. Double order traversal of binary tree is defined as follows:
If the binary tree is empty, do nothing; otherwise:
Visit the root for the first time
Traverse the left sub tree in double order
Visit the root for the second time
Traverse the right sub tree in double order
Write a recursive algorithm to implement double order traversal of a binary tree
and implement the same in c++.
*/
#include <iostream>
using namespace std;
struct node
{
 int val;
 node *l;
 node *r;
}*root=NULL,*p,*q,*x;
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
void inorder(node *x)
{
 if(x!=NULL)
{
  inorder(x->l);
  cout<<"  "<<x->val<<"  ";
  inorder(x->r);
} 
}
void preorder(node *x)
{
 if(x!=NULL)
 {
  cout<<"  "<<x->val<<"  ";
  preorder(x->l);
  preorder(x->r);
   }
}
void postorder(node *x)
{
 if(x!=NULL)
{
 postorder(x->l);
 postorder(x->r);
 cout<<"  "<<x->val<<"  ";
}
}
void doubleorder(node *x)
{
 if(x!=NULL)
 {
  cout<<"  "<<x->val<<"  ";
  doubleorder(x->l);
  cout<<"  "<<x->val<<"  ";
  doubleorder(x->r);
}
}
int main()
{
 int n;
 char c='y';
 while(c=='y'||c=='Y')
 {
    add();
    cout<<"Do you want to continue-";
    cin>>c;
 }

 cout<<"\nIN ORDER :";
 inorder(root);
 cout<<"\nPRE ORDER";
 preorder(root);
 cout<<"\nPOST ORDER";
 postorder(root);
 cout<<"\nDOUBLE ORDER";
 doubleorder(root);
 cout<<"\n";
 system("pause");
 return 0;
}
