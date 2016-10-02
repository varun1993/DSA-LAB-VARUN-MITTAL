#include<iostream.h>
#include<conio.h>
#include<ctype.h>
struct node 
{
       int n;
       node* next;
}*temp,*ptr,*start=NULL;
int i;
void push(int i)
{ 
    if(start==NULL)
    {      start=new node;        
          start->n=i;  
      }   
    else if(start!=NULL)
    {
          ptr= new node;
          ptr->n=i;
          ptr->next=start;
          start=ptr;
    }
    cout<<"\nPushed Into Stack ";
}
void display(node *temp)
{    if(temp==NULL)
                   cout<<"\nStack Empty ~~";
    else
    {
     while(temp!=NULL)
     {
         cout<<"\n"<<temp->n;
         temp=temp->next;
     }
    }
}
int pop()
{   if(start==NULL)
    {              cout<<"\nStack Empty !! ";
                   return -1;
    }
    if(start!=NULL)
    {
      i=start->n;
      temp=start;
      cout<<"\nDeleting Node ";
      start=start->next;
      delete temp;
      return i;
    } 
} 
int main()
{    int p,z1,z2;
     char s[30];
     cout<<"\nEnter Expression :";
     fflush(stdin);
     gets(s);
     for(p=0;s[p]!='\0';p++)
     {
         if(isdigit(s[p]))
                     push((int)(s[p])-48); 
         else 
         {   cout<<"\nPopping And Calculating ";
             switch(s[p])
             {
                 case'+': z1=pop();
                         z2=pop();
                         push(z1+z2);   
                         break;
                 case'-': z1=pop();
                         z2=pop();
                         push(z2-z1);
                         break;
                 case'*':z1=pop();
                         z2=pop();
                         push(z1*z2);
                         break;
                 case'/':z1=pop();
                         z2=pop();
                         push(z2/z1);
                         break;  
                default:cout<<"\nIncorrect Input !~!!! ";
                         return 0;
             }
         }  
     }     
     cout<<"\nResult :"<<pop();
         getch();
     return 1;
}
     
     

       
