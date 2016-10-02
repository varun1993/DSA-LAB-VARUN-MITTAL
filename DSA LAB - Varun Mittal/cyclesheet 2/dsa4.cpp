#include <iostream>
#include <conio.h>
using namespace std;
int a[50];

void merge(int low,int mid,int high)
{
  int h,i,j,b[50],k;
  h=low;
  i=low;
  j=mid+1;
  while((h<=mid)&&(j<=high))
  {
                       if(a[h]<=a[j])
                       {
                                     b[i]=a[h];
                                     h++;
                       }
                       else
                       {
                                     b[i]=a[j];
                                     j++;
                       }
                       i++;
  }
  if(h>mid)
  {
      for(k=j;k<=high;k++)
      {
                          b[i]=a[k];
                          i++;
      }
  }
  else
  {
      for(k=h;k<=mid;k++)
      {
                         b[i]=a[k];
                         i++;
      }
  }
  for(k=low;k<=high;k++) 
  {
                    a[k]=b[k];
  }         
}
void merge_sort(int low,int high)
 {
      int mid;
      if(low<high)
      {
             mid=(low+high)/2;
             merge_sort(low,mid);
             merge_sort(mid+1,high);
             merge(low,mid,high);
      }
 }
main()
{
      
      int num,num1,i;
      cout<<"No of Elements of list 1: ";
      cin>>num;
      cout<<"No of Elements of list 2: ";
      cin>>num1;
      cout<<"\nEnter list 1 elements:\n";
      for(i=1;i<=num+num1;i++)
      {
                         if(i==(num+1))
                         {
                                       cout<<"Enter list 2 elements:\n";
                         }
                         cin>>a[i] ;
      }
      num=num+num1;
      merge_sort(1,num);
      cout<<"\nAfter sorting: \n";
      for(i=1;i<=num;i++)
      {
                         cout<<a[i]<<" ";
      }
      getch();
}

