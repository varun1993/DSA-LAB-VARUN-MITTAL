#include<conio.h>  
#include<iostream> 
using namespace std;
int n=0;
class apart
{
      public:
           int rno,nofloor,noflats,ano;
           char apname[20],bname[20],sname[20],lname[20];
           void accept();
           void display();
}a[20],temp;
void apart::accept()
{    cout<<"\n\n\n\v\vEnter Details :";
    cout<<"\nEnter Road No : ";
     cin>>rno;
     cout<<"\nEnter Street Name : ";
     fflush(stdin);
     gets(sname);
     cout<<"Enter Building Name : ";
     fflush(stdin);
     gets(bname);
     cout<<"Enter Apartment Name : ";
     fflush(stdin);
     gets(apname);
     cout<<"Enter NO Of floors : ";
     cin>>nofloor;
     cout<<"\nEnter No of Flats : ";
     cin>>noflats;
    cout<<"\nEnter Apartment NO : ";
     cin>>ano;
    cout<<"\nEnter Landmark Name : ";
     fflush(stdin);
     gets(lname);
    
}
void apart::display()
{    cout<<"\n\n\n\v\vDetails :";
    cout<<"\nRoad No : "<<rno;
     cout<<"\nStreet Name : ";
     fflush(stdin);
     puts(sname);
     cout<<"Building Name : ";
     fflush(stdin);
     puts(bname);
     cout<<"Apartment Name : ";
     fflush(stdin);
     puts(apname);
     cout<<"NO Of floors : "<<nofloor;
     cout<<"\nNo of Flats : "<<noflats;
    cout<<"\nApartment NO : "<<ano;
    cout<<"\nLandmark Name : ";
     fflush(stdin);
     puts(lname);
   
}
int binary(int x)
{
    int mid,low=0,high=n;
    while(low<=high)
    {
     mid=(low+high)/2;
     if(x<a[mid].ano)
                     high=mid-1;
     else if(x>a[mid].ano)
                          low=mid+1;
     else  if(x==a[mid].ano)             
                         return mid;
     }
     return -1;
}
int partition(int lb,int ub)
{    int i,j,key;
     key=a[lb].ano;
     i=lb+1;
     j=ub;
        while(i<=j)
              {
                 while((key>=a[i].ano)&&(i<=ub))
                                    i++;
                 while((key<a[j].ano)&&(j>=lb))
                                    j--;
                 if(i<j)
                  {
                         temp=a[i];
                         a[i]=a[j];
                         a[j]=temp;
                  }
                 else 
                 {    
                      temp=a[j];
                      a[j]=a[lb];
                      a[lb]=temp;
                      break;
                 }
              }
  return j;
}
void quick(int lb,int ub)
{    if(lb<ub)
     {
      int p=partition(lb,ub);
      quick(lb,p-1);
      quick(p+1,ub);
     }
}
main()
{     int i,a1;
      cout<<"\nEnter Number Of Apartments :";
      cin>>n;
      for(i=0;i<n;i++)
                      a[i].accept();
      
      quick(0,n-1);
      cout<<"\n\n\t\tDISPLAYING DETAILS ";    
      for(i=0;i<n;i++)
                      a[i].display();
      cout<<"\nEnter Apartment No To search For :";
      cin>>a1;
      i=binary(a1);
      if(i==-1)
               cout<<"\nNot Found !!!";
      else 
          {
                cout<<"\nFound !!";                
                a[i].display();
          }
      getch();
}                
