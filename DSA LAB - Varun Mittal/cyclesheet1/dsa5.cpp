/*
Assume that you have a singly linked list pointed at by the pointer variable
START. Each node consists of a search key KEY (Information field) and a
pointer to the next node NEXT. Formulate a logical function SEARCH() that
simultaneously searches and reorganizes the list in the following fashion : If the
node is found, it is deleted from its current position and moved to the start of the
list.
*/
#include<iostream.h>
#include<conio.h>
int n=1;
struct node
{
       int key;
       node *next;
}*temp,*ptr,*start=NULL;
void push()
{    ptr=new node;
     cout<<"\nEnter Key :";
     cin>>ptr->key;
     ptr->next=NULL;
     if(start==NULL)
          start=ptr;
     else
      {
          ptr->next=start;
          start=ptr;
      }
      n++;
}
void display()
{
     temp=start;
     while(temp!=NULL)
     {                cout<<"\t"<<temp->key;
                      temp=temp->next;
     }
}
void search()
{    int k,z=1;
     bool flag=false;
     cout<<"\nEnter Key to search :";
     cin>>k;
     temp=start;
     while(temp!=NULL)
     {  if(temp->key==k)
        {  cout<<"\nFound At Position :"<<z;
           flag=true;
           break;
        }             
           z++;      
         temp=temp->next;
     }
     if(!flag)
            cout<<"\nElement Not Found !!!";
     else
     {
         if(z==1)
          ;//cout<<"\nNo Change required !!!";
          else 
          {    ptr=start;
               for(k=1;k<z-1;k++)
                ptr=ptr->next;
               if(z==n)
               { 
                 temp=ptr;
                 ptr=ptr->next;
                 temp->next=NULL;
               }
               else
                  {   temp=ptr;
                      ptr=ptr->next;
                      temp->next=ptr->next;
                  }
          //cout<<"\nElement Deleted !!!";        
                ptr->next=start;
                start=ptr;
          }
     }
}
int main()
{   int ch;
    push();
    while(1)
    {
     cout<<"\n1.Push\n2.Display\n3.Search And Swap\n4.Exit :";
     cin>>ch;
     switch(ch)
     {
               case 1:cout<<"\nPush \n";
                                    push();
                                    break;
               case 2:cout<<"\nDisplay\n";
                                    display();
                                    break;
               case 3:cout<<"\nSearch & Swap \n";
                                    search();
                                    break;
               case 4:cout<<"\nExit!";
                                   exit(0);
               default:cout<<"\nWrong Input try again !!";
     }                      
    }
    getch();
    return 1;
}         
          
        
                     
         
         
