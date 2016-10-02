#include <iostream>
using namespace std;
int b[100],top=-1,k=0;
char c[100];
struct node
{
char c;
node *l;
node *r;
node *p;
}*root=NULL,*x,*q;
void etree(char a[])
{
int i=1;
root=new node;
root->c=a[0];
root->l=NULL;
root->r=NULL;
root->p=NULL;
q=root;
while(a[i]!='\0')
{
x=new node;
x->c=a[i];
i++;
x->l=NULL;
x->r=NULL;
x->p=q;
label:if(!q->l)
q->l=x;
else if(!q->r)
q->r=x;
else
{
q=q->p;
goto label;
}
if(x->c=='+'||x->c=='-'||x->c=='*'||x->c=='/')
q=x;
}
}
void postorder(node *x)
{
 if(x!=NULL)
{
 postorder(x->l);
 postorder(x->r);
 cout<<x->c;
 c[k++]=x->c;
}
}
void inorder(node *x)
{
 if(x!=NULL)
{
  inorder(x->l);
  cout<<x->c;
  inorder(x->r);
} 
}
void push(int n)
{
top++;
b[top]=n;
}
int pop()
{
return b[top--];
} 
int main()
{
char exp[30];
int a,b;
cout<<"ENTER PREFIX EXPRESSION-";
cin>>exp;
etree(exp);
postorder(root);
cout<<"\n";
inorder(root);
cout<<"\n";
int i=0;
//for(i=0;c[i]!='\0';i++)
//cout<<c[i];
while(c[i]!='\0')
{
if(c[i]=='+')
{
a=pop();
b=pop();
push(b+a);
}
else
if(c[i]=='-')
{
a=pop();
b=pop();
push(b-a);
}
else
if(c[i]=='*')
{
a=pop();
b=pop();
push(b*a);
}
else
if(c[i]=='/')
{
a=pop();
b=pop();
push(b/a);
}
else
{
push(c[i]-48);
}
i++;
}
cout<<::b[0];
system("pause");
return 0;
}
