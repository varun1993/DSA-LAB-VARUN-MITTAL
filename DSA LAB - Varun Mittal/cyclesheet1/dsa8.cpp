/*
Design a C++ Program to store the Employee records. Each record should contain
Emp.Id, Emp.Name, Designation ,Salary , years of experience and address (
Flat.No, Street,place,District,state, pincode). Sort the records using Insertion sort
based on emp.Id.Also calculate the number of comparisions required to sort the
records.
*/
#include <iostream.h>
struct address
{
     int f_no;
     char street[20];
     char city[20];
     char state[20];
     long int pincode; 
}a[20];
struct emp
{
     char e_name[20];
     char e_desig[20];
     int e_id;
     float sal;
     int y_exp;
}e[10];
int count=0;
void insert()
{
 cout<<"Enter the details-\n";
 cout<<"Name-";
 fflush(stdin);
 gets(e[::count].e_name);
 cout<<"Designation-";
 fflush(stdin);
 gets(e[::count].e_desig);
 cout<<"Employee ID-";
 cin>>e[::count].e_id;
 cout<<"Salary-";
 cin>>e[::count].sal;
 cout<<"Years of Experience-";
 cin>>e[::count].y_exp;
 cout<<"Address-\n";
 cout<<"Flat no-";
 cin>>a[::count].f_no;
 cout<<"Street-";
 fflush(stdin);
 gets(a[::count].street);
 cout<<"State-";
 fflush(stdin);
 gets(a[::count].state);
 cout<<"City-";
 fflush(stdin);
 gets(a[::count].city);
 cout<<"Pin code-";
 cin>>a[::count].pincode;
 ::count++;
}
void sort()
{
    int j,i,z=0;
    emp t;address a1;
    for(i=1;i<(::count);i++)
   {     a1=a[i];                   
         t=e[i];
        for(j=i;(j>0)&&(t.e_id<e[j-1].e_id);j--)
        { z++;
          e[j]=e[j-1];
          a[j]=a[j-1];
        }
        e[j]=t;
        a[j]=a1;
    }
    cout<<"\nComparisons Required :"<<z;
}
void display()
{
     int i;
     for(i=0;i<(::count);i++)
     {
         cout<<"Name-"<<e[i].e_name<<"\n";
         cout<<"Designation-"<<e[i].e_desig<<"\n";
         cout<<"Employee ID"<<e[i].e_id<<"\n";
         cout<<"Salary-"<<e[i].sal<<"\n";
         cout<<"Years of Experience-"<<e[i].y_exp<<"\n";
         cout<<"Address-\n";
         cout<<"Flat no-"<<a[i].f_no<<"\n";
         cout<<"Street-"<<a[i].street<<"\n";
         cout<<"State-"<<a[i].state<<"\n";
         cout<<"City-"<<a[i].city<<"\n";
         cout<<"Pin code-"<<a[i].pincode<<"\n";
     }
}
int main()
{
    int ch;
    char c='y';
    cout<<"\t\t\t\t*********MENU********\n";
    while(c=='y'||c=='Y')
    {
         cout<<"1.INSERTION\n2.SORT\n3.DISPLAY\n";
         cout<<"Enter your choice-";
         cin>>ch;
         switch(ch)
         {
              case 1:insert();break;
              case 2:sort();break;
              case 3:display();break;
              default:cout<<"\nWrong Input Try Again !!!!";
         }
         cout<<"\nDo you want to continue";
         cin>>c;
     }
     system("pause");
     return 1;
}
 
 
 
 
