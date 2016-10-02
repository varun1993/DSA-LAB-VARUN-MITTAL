/*
Design a C++ program to store the student details: Reg.No, Name, Programme
,Branch and contact number( Don’t allow duplicate registration numbers). Sort
the records based on the reg.no using selection sort. When a new record is added
it should be placed in the proper position.
*/
#include<iostream.h>
#include<conio.h>
struct node
{
 char r_no[20];
 char name[20];
 char prog[10];
 char branch[10];
 long int ph_no;
 node *link;
}*start=NULL,*ptr,*p,*p1;
void create()
{
 char reg[20];
 int flag=0;
 cout<<"\nEnter the reg. no.->";
 fflush(stdin);
 gets(reg);
 p=start;
 while(p!=NULL)
 {
     if(strcmp(p->r_no,reg)==0)
     {
          flag++;
          break;
     } 
     else
         p=p->link;
 }
 if(flag!=0)
            cout<<"\nDuplicate entry !!!";
 else
 {
     ptr=new node;    
     strcpy(ptr->r_no,reg);
     cout<<"\nEnter the name->";
     fflush(stdin);
     gets(ptr->name);
     cout<<"\nEnter the progrmme->";
     fflush(stdin);
     gets(ptr->prog);
     cout<<"\nEnter the branch->";
     fflush(stdin);
     gets(ptr->branch);
     cout<<"\nEnter the phone no.->";
     cin>>ptr->ph_no;
     if(start==NULL)
     {
          start=ptr;
          start->link=NULL;
     }
     else
     {
          ptr->link=start;
          start=ptr;
     }
 }
}
void add_new()
{
 char reg[20];  
 int flag=0;
 cout<<"Enter the reg. no.->";
 fflush(stdin);
 gets(reg);
 p=start;
 while(p!=NULL)
 {
 if(strcmp(p->r_no,reg)==0)
 {
  flag++;
  break;
 } 
 else
 p=p->link;
}
 if(flag!=0)
            cout<<"\nDuplicate entry";
 else
 {
    ptr=new node;
    strcpy(ptr->r_no,reg);
    cout<<"Name-";
    fflush(stdin);
    gets(ptr->name);
    cout<<"Programme-";
    fflush(stdin);
    gets(ptr->prog);
    cout<<"Branch-";
    fflush(stdin);
    gets(ptr->branch);
    cout<<"Phone no->";
    cin>>ptr->ph_no;
    if(strcmp(start->r_no,ptr->r_no)>0)
      {
        ptr->link=start;
        start=ptr;
      }
    else
      {
         p=start;
      while(p!=NULL)
      {
       if((strcmp(ptr->r_no,p->r_no)==1)&&(p->link!=NULL))
            {
                 p1=p;
                 p=p->link;
            } 
       else if((strcmp(ptr->r_no,p->r_no)==1)&&(p->link==NULL))
           {
                 p->link=ptr;
                 ptr->link=NULL;
                 break;
           }
       else 
          {
               p1->link=ptr;
               ptr->link=p;
               break;
          }    
    }
    } 
 }
} 
void sort()
{
 int temp;
 char t[20];
 p=start;
 while(p->link!=NULL)
 {
     p1=p->link;
     while(p1!=NULL)
    {
     if(strcmp(p->r_no,p1->r_no)>0)
     {
      strcpy(t,p->r_no);
      strcpy(p->r_no,p1->r_no);
      strcpy(p1->r_no,t);
      
      strcpy(t,p->name);
      strcpy(p->name,p1->name);
      strcpy(p1->name,t);
      
       strcpy(t,p->prog);
      strcpy(p->prog,p1->prog);
      strcpy(p1->prog,t);
      
       strcpy(t,p->branch);
      strcpy(p->branch,p1->branch);
      strcpy(p1->branch,t);
      
       temp=p->ph_no;
       p->ph_no=p1->ph_no;
       p1->ph_no=temp;
     }
    p1=p1->link;  
    }
    p=p->link;
 }
}
void display()
{
     ptr=start;
     if(start==NULL)
                    cout<<"No entries as of yet";
     else
     {
         while(ptr!=NULL)
         {
             cout<<"Name->"<<ptr->name;
             cout<<"\nReg. No.->"<<ptr->r_no;
             cout<<"\nProgramme->"<<ptr->prog;
             cout<<"\nBranch->"<<ptr->branch;
             cout<<"\nPhone No.->"<<ptr->ph_no<<"\n";
             ptr=ptr->link;
        }
    }
}
int main()
{
    int ch;
    char c='y';
    cout<<"\t\t\t\t********MENU********\n";
    while(c=='y'||c=='Y')
 {
  cout<<"1.Create\n2.Sort\n3.Add New\n4.Display\n";
  cout<<"Enter your choice :";
  cin>>ch;
  switch(ch)
  {
       case 1:create();break;
       case 2:sort();break;
       case 3:add_new();break;
       case 4:display();break;
       default: cout<<"\nWrong Input !!!";
  }
  cout<<"\nDo you want to continue :";
  cin>>c;
 }
getch();
return 1;
}                
