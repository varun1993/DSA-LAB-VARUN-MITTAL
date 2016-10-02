#include<iostream.h>
#include<conio.h>
struct node 
{
       int tno,age,arrival,depart;
       char name[30],source[30],dest[30];
       node* next;
}*temp,*ptr,*front=NULL,*rear=NULL;
void push()
{
      ptr=new node ;
          cout<<"\nEnter Ticket No:";
              cin>>ptr->tno;
          cout<<"\nEnter Name:";
          fflush(stdin);
          gets(ptr->name);
          cout<<"Enter Age :";
          cin>>ptr->age;
          cout<<"\nEnter Source:";
          fflush(stdin);
          gets(ptr->source);
          cout<<"\nEnter Destination:";
          fflush(stdin);
          gets(ptr->dest);
          cout<<"\nEnter Arrival time :";
          cin>>ptr->arrival;
          cout<<"\nEnter Departure time :";
          cin>>ptr->depart;
          ptr->next=NULL;
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
     if(front==rear==NULL)
                          cout<<"No More Registrations!! ";
     else
     {   cout<<"\nRegistered !!! ";
         cout<<"\n Ticket No:"<<front->tno;
          cout<<"\nName:";
          fflush(stdin);
          puts(front->name);
          cout<<"Source:";
          fflush(stdin);
          puts(front->source);
          cout<<"Destination:";
          fflush(stdin);
          puts(front->dest);
          cout<<"\nArrival time :"<<front->arrival;
          cout<<"\nDeparture time :"<<front->depart;
          front=front->next;
          cout<<"Registration Completed!!!";
     }
}
void display(node *temp)
{
     while(temp!=NULL)
     {               
          cout<<"\n\n\n\n\nTicket No:"<<temp->tno;
          cout<<"\nName:";
          fflush(stdin);
          puts(temp->name);
          cout<<"Source:";
          fflush(stdin);
          puts(temp->source);
          cout<<"Destination:";
          fflush(stdin);
          puts(temp->dest);
          cout<<"Arrival time :"<<temp->arrival;
          cout<<"\nDeparture time :"<<temp->depart;
          temp->next=NULL;       
     }
}
              
int main()
{
     char ch='y';
     int sw,i,count;
     cout<<"\nEnter Maximum Number Of Tickets Permitted :";
                    cin>>count;
     i=count;
     while(ch=='y'||ch=='Y')
     {
         cout<<"\n1.Buy Ticket\n2.Exit :";
                        cin>>sw;
         switch(sw)
         {         
                   case 1:if(count>0)
                           {
                                       cout<<"\nEnter Details For Passenger :";
                                       push();
                                       count--;
                           }
                           else
                             {  
                                 cout<<"\nReservation Full !!!!";
                                 goto lb;
                             }
                  case 2: goto lb;
                  default: cout<<"\nWrong Input !!!";
                           break;
         }
         cout<<"Press Y to continue.....";
         cin>>ch;          
     }
     lb:         
            cout<<"\n\t\tREGISTERED TRAVELLERS !!!";
                              
             for(count=0;count<i;count++)
                                         pop();
     getch();
     return 1;
}
     
                            
                            
