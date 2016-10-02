/*
Consider a railway reservation system. The system issues the tickets on the basis
of First come First serve. The issued ticket contains the following information:
The Train No, Passenger name (maximum of six),age, source, Destination,
Arrival and departure time. Write a C++ program to implement the data structure
that is used for the above system.
*/
#include<iostream.h>
#include<conio.h>
class railway
{
      int age,train;
      float arrival,departure;
      char name[6],source[10],destination[10];
      public:
      void accept()
      {
           cout<<"\nEnter your name: ";
           fflush(stdin);
           gets(name);
           cout<<"\nEnter your age: ";
           cin>>age;
           cout<<"\nEnter your train number: ";
           cin>>train;
           cout<<"\nEnter your source: ";
           fflush(stdin);
           gets(source);
           cout<<"\nEnter your departure time: ";
           cin>>departure;
           cout<<"\nEnter your destination: ";
           fflush(stdin);
           gets(destination);
           cout<<"\nEnter your arrival time: ";
           cin>>arrival;
           cout<<"\nThanks for giving details...\n";
      }
      void display()
      {
           cout<<"\nName: "<<name<<"\nAge: "<<age<<"\nTrain number: "<<train;
           cout<<"\nSource: "<<source<<"\nDeparture time: "<<departure;
           cout<<"\nDestination: "<<destination<<"\nArrival time: "<<arrival;
           cout<<"\nPress enter for displaying next ticket issued\n";
           getch();
      }
};
struct node
{
       railway r;
       node* next;
}*temp,*ptr,*front=NULL,*rear=NULL;
void push()
{
     if(front==NULL && rear==NULL)
     {
           front=new node;
           front->r.accept();
           front->next=NULL;
           rear=front;
     }
     else
     {
         ptr=new node;
         ptr->r.accept();
         ptr->next=NULL;
         rear->next=ptr;
         rear=ptr;
     }
}
void pop()
{
     if(front==NULL||rear==NULL)
                                cout<<"\nNo More Applications !!!";
     else
     {
         temp=front;
         front=front->next;  
         temp->r.display();
         delete temp;
     }
}
int main()
{
    int n=1,ch,i;
    while(1)
    {
    cout<<"\n1.Book Ticket\n2.Issue Tickets\n3.Exit :";
    cin>>ch;
    switch(ch)
    {
             case 1:cout<<"\nApplying For Reservation ";
                                      push();
                                    n++;
                                      break;
             case 2:cout<<"\nReservations ";
                     for(i=1;i<=n;i++)
                     {
                          pop();
                          if(i==3) 
                          {        cout<<"\nReservation Finished !!!";
                              break;
                          }
                      }
                      getch();
                      exit(0);
             case 3:exit(0);
             default :cout<<"\nWrong Choice....try again!!!";
    }
    }
}
             
