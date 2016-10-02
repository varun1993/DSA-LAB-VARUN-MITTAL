/*
Write C++ program which takes the following details of picture: Picture Title,
date_taken, type of image, Description, Camera_used. Using max_selection sort,
Sort the details of the pictures first based on date_taken and then by type of
image. Search for a specific picture based on date_taken or Picture_ Title.
*/
#include<iostream.h>
#include<conio.h>
int n;
class pic
{     public:
      char title[20],date[8],type[5],desc[50],cam[10];
      void accept()
      {
           cout<<"\n\n\nEnter Details for Picture :";
           cout<<"\nEnter Title :";
           fflush(stdin);
           gets(title);
           cout<<"\nEnter Date Taken :";
           fflush(stdin);
           gets(date);
           cout<<"\nEnter Type :";
           fflush(stdin);
           gets(type);
           cout<<"\nEnter Description :";
           fflush(stdin);
           gets(desc);
           cout<<"\nEnter Camera :";
           fflush(stdin);
           gets(cam);
           
      }
      void display()
      {
           cout<<"\n\n\nDetails for Picture :";
           cout<<"\nTitle :"<<title;
           cout<<"\nDate Taken :"<<date;
           cout<<"\nType :"<<type;
           cout<<"\nDescription :"<<desc;
           cout<<"\nCamera :"<<cam;
           getch();
      }     
}a[20],temp;
void selsortdate()
{      int i,j,pos;
       for(i=0;i<n-1;i++)
       {
            pos=i;
            for(j=i+1;j<n;j++)
             if(stricmp(a[pos].date,a[j].date)>0)
                   pos=j;
             if(pos!=i)
             {
                       temp=a[i];
                       a[i]=a[pos];
                       a[pos]=temp;
             }
       }
}
void selsorttype()
{      int i,j,pos;
       for(i=0;i<n-1;i++)
       {
            pos=i;
            for(j=i+1;j<n;j++)
             if(stricmp(a[pos].type,a[j].type)>0)
                   pos=j;
             if(pos!=i)
             {
                       temp=a[i];
                       a[i]=a[pos];
                       a[pos]=temp;
             }
       }
}
void searchtitle()
{    int i;
     char title[20];
     cout<<"\n\n\nEnter Title for Picture To Be Searched :";
           fflush(stdin);
           gets(title);
     for(i=0;i<n;i++)
        if(strcmp(title,a[i].title)==0)
           {
               cout<<"\nPicture Found !!";
               a[i].display();break;
           }
     if(i==n)
             cout<<"\nNot Found !!!";
}
void searchdate()
{    int i;
     char date[8];
     cout<<"\n\n\nEnter date for Picture To Be Searched :";
          fflush(stdin);
           gets(date);
     for(i=0;i<n;i++)
        if(strcmp(date,a[i].date)==0)
           {
               cout<<"\nPicture Found !!";
               a[i].display();break;
           }
     if(i==n)
             cout<<"\nNot Found !!!";
}
main()
{
      int i,ch;
      cout<<"\nEnter No Of Pictures :";
      cin>>n;
      for(i=0;i<n;i++)
                      a[i].accept();
      while(1)
      {
              cout<<"\n\n\t\t\tMENU\n1.Sort By Date\n2.Sort By Type\n3.Search By Date\n4.Search By Title\n5.Display\n6.Exit\nEnter Choice :";
              cin>>ch;
              switch(ch)
              {
                        case 1:cout<<"\nSorting List by date!!";
                                                selsortdate();
                                                break;
                        case 2:cout<<"\nSorting List by type!!";
                                                selsorttype();
                                                break;
                        case 3:cout<<"\nSearching by date: ";
                                                  searchdate();
                                                  break;
                        case 4:cout<<"\nSearching by title : ";
                                                  searchtitle();
                                                  break;
                        case 5:cout<<"\nDisplaying Details :";
                                                   for(i=0;i<n;i++)
                                                                   a[i].display();
                                                                   break;
                        case 6:exit(0);
                         default:cout<<"\nWrong Input !! ";
              }
      }
      getch();
      return 1;
}
