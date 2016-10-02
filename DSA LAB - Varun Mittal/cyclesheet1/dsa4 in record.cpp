/*Consider a library application which maintains the list of books. The application
contains the following information about the books: Title of the book, Author
name, ISBN and Year of publication. Create a Linked List to maintain the list of
books also to perform the following operations: Insert a book at any desired
position and to delete or search for a book given the ISBN
*/
#include<conio.h>
#include<iostream.h>
#include<string.h>
int n=1;
class book
{     char title[50],author[50];
       int year;
      public:
             int isbn;
      void accept()
      {
             cout<<"\nEnter Title of book: ";
             fflush(stdin);
             gets(title);
             cout<<"\nEnter Author of book: ";
             fflush(stdin);
             gets(author);
             cout<<"\nEnter ISBN of book: ";
             cin>>isbn;
             cout<<"\nEnter Year of publication of book: ";
             cin>>year;
      }
      void display()
      {
             cout<<"\nTitle of book: ";
             fflush(stdin);
             puts(title);
             cout<<"\nAuthor of book: ";
             fflush(stdin);
             puts(author);
             cout<<"\nISBN of book: "<<isbn;
             cout<<"\nYear of publication of book: "<<year;        
      }
};
struct node{
       book b;
       node *next;
}*temp,*ptr,*front=NULL,*rear=NULL;
void push()
{            ptr=new node;
             ptr->b.accept();
             if(front==NULL&& rear==NULL)
             {
              cout<<"\n1st Book entered!\n";
              front=ptr;
              rear=ptr;
             }
             else
             {
                 rear->next=ptr;
                 rear=ptr;         
             }
             n++;
}
void display()
{    ptr=front;
     while(ptr!=NULL)
     {       ptr->b.display();        
             cout<<"\nPress a key to continue ...";
             getch();
             ptr=ptr->next;
     }
}
void search()
{    ptr=front;
     bool flag=false;
     int i;
     cout<<"\nEnter ISBN number :";
     cin>>i;
     while(ptr!=NULL)
     {      if(i==ptr->b.isbn)
            {
             cout<<"\nBOOK Found !!!";
             ptr->b.display();        
             flag=true;
             }
             ptr=ptr->next;
     }
     if(flag==false)
                    cout<<"\nBook not found !!!";
}
void insert()
{    int z;
     int i;
     cout<<"\nEnter Position to insert :";
     cin>>z;
     temp=new node;
     temp->b.accept();
          if(z==1)
          {
                  temp->next=front;
                  front=temp;
          }
          else if(z>=n)
          {
               temp->next=NULL;
               rear->next=temp;
               rear=temp;
          }
          else
          {   ptr=front;
              for(i=1;i<z-1;i++)
                ptr=ptr->next;
              temp->next=ptr->next;
              ptr->next=temp;
          }
          n++;
}  
void del()
{    
     int i,z;
     cout<<"\nEnter Position to delete :";
     cin>>z;
     if(z>n)
            cout<<"\nNumber Exceeds Total Books !!!";
     else 
     {   
          if(z==1)
          {       
                  temp=front;
                  front=front->next;
                  delete temp;
          }
          else 
          {    ptr=front;
               for(i=1;i<z-1;i++)
                ptr=ptr->next;
               if(z==n)
               { 
                 temp=ptr;
                 ptr=ptr->next;
                 delete ptr;
                 temp->next=NULL;
               }
               else
                  {   temp=ptr;
                      ptr=ptr->next;
                      temp->next=ptr->next;
                      delete ptr;
                  }
          cout<<"\nElement Deleted !!!";        
          n--;
          }
     }
}              
int main()
{
      int i,ch;
      push();
      while(1)
      {
      cout<<"\n1.PUSH\n2.DISPLAY\n3.SEARCH\n4.Delete\n5.Insert\n6.Exit :";
      cin>>ch;
      switch(ch)
      {
                case 1:cout<<"PUSH";
                        push();
                        break;
                case 2:cout<<"DISPLAY";
                        display();
                        break;
                case 3:cout<<"SEARCH";
                        search();
                        break;        
                case 4:cout<<"Delete";
                        del();
                        break;
                case 5:cout<<"INSERT";
                        insert();
                        break;
                case 6:cout<<"EXIT";
                        exit(0);
                default:cout<<"WRONG INPUT TRY AGAIN...";
      }
      }
      getch();
      return 1;
}
