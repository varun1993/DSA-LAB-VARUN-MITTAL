#include<iostream>
#include<conio.h>
using namespace std;
int n=0;
class employee
{     public:
      int i,age;
      char name[30],prod[5][50];
      int yop,p;
      void accept();
      void display();     
}e[10],tmp;
void employee::accept()
{
     cout<<"\nEnter NAme :";
     fflush(stdin);
     gets(name);
     cout<<"\nEnter Age :";
     cin>>age;
     cout<<"\nEnter No of Products :";
     cin>>p;
     for(i=0;i<p;i++)
     {
          cout<<"\nEnter Products "<<i+1<<" :";
          fflush(stdin);
          gets(prod[i]);
      }
     cout<<"\nEnter Years Of experience :";
     cin>>yop;
}
void employee::display()
{
     cout<<"\nNAme :"<<name;
     cout<<"\nAge :"<<age;
     for(i=0;i<p;i++)
     {
          cout<<"\nProduct "<<i+1<<" :";
          puts(prod[i]);
      }
     cout<<"\nYears Of experience :"<<yop;
     getch();
}
main()
{
      int i,j,l,m,count=0,kk=0;
      cout<<"\nEnter  Number Of Employee's :";
      cin>>n;
      for(i=0;i<n;i++)
          e[i].accept();
      for(i=0;i<n;i++)
         for(j=0;j<n-1-i;j++)
            if(e[j].yop>e[j+1].yop)
            {
              tmp=e[j];
              e[j]=e[j+1];
              e[j+1]=tmp;
            }
      for(i=0;i<n;i++)
                      e[i].display();
      for(i=0;i<n-1;i++)            
      {
        for(j=i+1;j<n;j++)
         {
            for(l=0;l<e[i].p;l++)
            for(m=0;m<e[j].p;m++)
                if(stricmp(e[i].prod[l],e[j].prod[m])==0)
                                                        count++;
            if(count>=0)
            {           cout<<"\nCommon Pair Products "<<kk+1<<" :\n";
                        e[i].display();
                        e[j].display();
                        kk++;
            }
            count=0;
         }
        }
        if(kk==0)
          cout<<"\nNO 2 salesman have common pair of products !! ";
          
          getch();
}
