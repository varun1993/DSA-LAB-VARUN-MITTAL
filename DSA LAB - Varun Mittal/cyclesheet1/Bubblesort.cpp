#include<stdio.h>
#include<iostream.h>
#include<conio.h>
main()
{
     int a[50],j,i,n,tmp;
     cout<<"ENTER SIZE OF ARRAY :";
     cin>>n;
     cout<<"Enter Elements :";
     for(i=0;i<n;i++)
     {    
          cin>>a[i];
     }
     cout<<"\t\t\tSORTING ";
     for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
           if(a[j]>a[j+1])
             {  tmp=a[j];
               a[j]=a[j+1];
               a[j+1]=tmp;
             }
     }       
     cout<<"SORTING COMPLETE.THE ARRAY IS :\n";
     for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
     getch();
}
                
