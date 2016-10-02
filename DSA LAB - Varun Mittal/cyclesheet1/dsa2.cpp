#include<iostream.h>
#include<conio.h>
struct node 
{
       char n;
       node* next;
}*temp,*ptr,*start=NULL;
char i;
void push(char i)
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
char pop()
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
{    int p;
     bool flag=true;
     char z,s[30];
     cout<<"\nEnter Expression :";
     fflush(stdin);
     gets(s);
     for(p=0;s[p]!='\0';p++)
     {
         if(s[p]=='{')
                      push(s[p]);
                      
         if(s[p]=='(')
                      push(s[p]);
                      
         if(s[p]=='[')
                      push(s[p]);
         
         if(s[p]=='}')
         {
                      z=pop();
                      if(z!='{')
                       flag=false;
         }
         if(s[p]==']')
         {             z=pop();
                       if(z!='[')
                       flag=false;
                      
         }
         if(s[p]==')')
         {
                       z=pop();
                       if(z!='(')
                       flag=false;
         
         }      
     }                      
     if(flag)
        cout<<"\nParanthesis Is Balanced ";
     else 
          cout<<"\nParanthesis Is Not Balanced ";
     getch();
     return 1;
}
     
     

       
