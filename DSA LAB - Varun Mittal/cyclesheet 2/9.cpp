#include <iostream>
using namespace std;
struct node
{
 char name[20];
 node *l;
 node*r;
}*root=NULL,*p,*q,*x,*y,*z,*w;
void insert()
{
char s[20];
int flag;
cout<<"Enter a string to insert-";
cin>>s;
if(root==NULL)
{
root=new node;
strcpy(root->name,s);
root->l=NULL;
root->r=NULL;
}
else
{
p=root;
while(p)
{
q=p;
if(strcmp(p->name,s)>0)
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
if(flag)
{
x=new node;
strcpy(x->name,s);
x->l=NULL;
x->r=NULL;
q->r=x;
}
else
{
x=new node;
strcpy(x->name,s);
x->l=NULL;
x->r=NULL;
q->l=x;
}
}
}
void inorder(node *p)
{
if(p)
{
inorder(p->l);
cout<<" "<<p->name<<" ";
inorder(p->r);
}
}
void search()
{
char s[20];
int flag=0;
cout<<"Enter the string to be searched-";
cin>>s;
if(!root)
cout<<"Tree is empty...Searching not possible...";
else
{
p=root;
while(p!=NULL)
{
if(strcmp(p->name,s)==0)
{
cout<<"Success....String ("<<p->name<<") found..";
flag++;
break;
}
else
if(strcmp(p->name,s)>0)
p=p->l;
else
p=p->r;
}
if(!flag)
cout<<"String not in the list...";
}
}
void del()
{
char s[20];
int flag=0,flag1=0;
if(!root)
cout<<"Nothing to delete...";
else
{
cout<<"Enter the name to be deleted from the tree-";
cin>>s;
p=root;
while(p!=NULL)
{
if(strcmp(p->name,s)==0)
{
flag++;
if((p->l==NULL)&&(p->r==NULL))
{
if(strcmp(q->l->name,p->name)==0)
{
delete p;
q->l=NULL;
}
else
{
delete p;
q->r=NULL;
}
}
else
if((p->l==NULL)&&(p->r!=NULL))
{
if(strcmp(q->l->name,p->name)==0)
{
q->l=p->r;
delete p;
}
else
{
q->r=p->r;
delete p;
}
}
else
{
if(p->l&&!p->r)
{
if(strcmp(q->l->name,p->name)==0)
{
q->l=p->l;
delete p;
}

else
{
q->r=p->l;
delete p;
}
}
}
if(p->l!=NULL&&p->r!=NULL)
{
z=p->l;
x=p;
while(p!=NULL)
{
w=y;
y=p;
if(flag1==0)
{
cout<<p->name<<"\n";
p=p->r;
flag1++;
}
else
{
cout<<p->name<<"\n";
p=p->l;
}
}
cout<<x->r->l->name<<"\n";
if(x->r->l!=NULL)
{
q->r=y;
y->l=z;
y->r=x->r;
w->l=NULL;
p=x;
delete p;
}
else
{
cout<<q->name<<"\n";
q->r=y;
cout<<y->name<<"\n";
y->l=z;
cout<<z->name<<"\n";
p=x;
delete p;
}
}
}
else
if(strcmp(p->name,s)>0)
{
q=p;
p=p->l;
}
else
{
q=p;
p=p->r;
}
}
if(!flag)
cout<<"The name you want to delete does not exist in the list...";
}
}
int main()
{
int ch;
char c='y';
while(c=='y')
{
cout<<"\t\t\t\t********MENU********\n";
cout<<"\t\t\t\t1.INSERT\n\t\t\t\t2.SEARCH\n\t\t\t\t3.DISPLAY\n\t\t\t\t4.DELETE\n";
cout<<"Enter your choice-";
cin>>ch;
switch(ch)
{
case 1:insert();break;
case 2:search();break;
case 3:inorder(root);break;
case 4:del();break;
default:cout<<"Wrong choice!!!!";break;
}
cout<<"Continue(y/n)-";
cin>>c;
}
cout<<"\n\n\n";
cout<<"Thank You...Press any key to exit..";
cin.get();
return 0;
}
