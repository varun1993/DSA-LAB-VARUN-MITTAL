#include<iostream.h>
#include<conio.h>
struct node 
{
       int isbn,yop;
       char title[30],author[30];
       node* next;
}*temp,*ptr,*front=NULL,*rear=NULL;
int size=0;
void push()
{
      ptr=new node ;
          cout<<"\nEnter ISBN No:";
              cin>>ptr->isbn;
          cout<<"Enter Title Of the Book :";
          fflush(stdin);
          gets(ptr->title);
          cout<<"Enter Year Of Publication :";
          cin>>ptr->yop;
          cout<<"Enter Author:";
          fflush(stdin);
          gets(ptr->author);
          ptr->next=NULL;
          size++;
     if(front==NULL&&rear==NULL)  
       {   
            front=rear=ptr;
       }
      else 
      {
           rear->next=ptr;
           rear=ptr;
      }
}
void pop()
{
     if(front==NULL&&rear==NULL)
                          cout<<"No More Registrations!! ";
     else
     {    cout<<"\n\n\n\nISBN No:"<<front->isbn;
          cout<<"\nTitle Of the Book :";
          puts(front->title);
          cout<<"Year Of Publication :"<<front->yop;
          cout<<"\nAuthor:";
          puts(front->author);
          front=front->next;
     }
     size--;
}
void display()
{     temp=front;
     if(temp==NULL)
         cout<<"\n\n\n NO BOOKS !!!!";
     else
         while(temp!=NULL)
         {               
          cout<<"\n\n\n\nISBN No:"<<temp->isbn;
          cout<<"\nTitle Of the Book :";
          puts(temp->title);
          cout<<"Year Of Publication :"<<temp->yop;
          cout<<"\nAuthor:";
          puts(temp->author); 
          temp=temp->next;
          }
}
void search(int n)
{   temp=front;
    int flag=0;
    while(temp!=NULL)
         {
            if(temp->isbn==n)
           {
               cout<<"\n\n\n\nISBN No:"<<temp->isbn;
               cout<<"\nTitle Of the Book :";
               puts(temp->title);
               cout<<"Year Of Publication :"<<temp->yop;
               cout<<"\nAuthor:";
               puts(temp->author); 
               flag=1;
           }
           temp=temp->next;
         }
    if(flag==0)
               cout<<"\nNOT FOUND !!!!!";
}
void insert()
{
     ptr=new node ;
          cout<<"\nEnter Details For New Book\n\nEnter ISBN No:";
              cin>>ptr->isbn;
          cout<<"\nEnter Title Of the Book :";
          fflush(stdin);
          gets(ptr->title);
          cout<<"Enter Year Of Publication :";
          cin>>ptr->yop;
          cout<<"\nEnter Author:";
          fflush(stdin);
          gets(ptr->author);
          ptr->next=NULL;
      int k,i;     
      temp=front;
           cout<<"\nEnter Position To Insert :";
            cin>>k;
            if(k<size)
            {
             if(k==1)
             {
                 ptr->next=front;
                 front=ptr;
             }
             if(k>1)
             { 
              for(i=1;i<k-1;i++)
                              temp=temp->next;     
               ptr->next=temp->next;
               temp->next=ptr;
               }
              }
             else
             {
               rear->next=ptr;
               rear=ptr;
             }  
      size++;
}
int main()
{
     int i,n;
     char ch='y';
     cout<<"\nEnter No of books :";
     cin>>n;
     for(i=0;i<n;i++)
         push();
     while(ch=='y'||ch=='Y')    
     {
         cout<<"\n1.Search\n2.Insert\n3.Display :";
         cin>>i;
         switch(i)
         {
                  case 1:cout<<"\nSEARCHING !!!";
                         cout<<"\nEnter ISBN to search :";
                         cin>>n;
                         search(n);
                         break;
                  case 2:cout<<"\nINSERTING !!!";
                         insert();
                         break;
                  case 3:cout<<"\nDISPLAYING !!!";
                         display();
                         break;
                default: cout<<"\nWRONG INPUT !!!!";
         }  
         cout<<"\nPress Y to continue...";
         cin>>ch;
     }
     getch();
     return 1;
}
     
                            
                            
