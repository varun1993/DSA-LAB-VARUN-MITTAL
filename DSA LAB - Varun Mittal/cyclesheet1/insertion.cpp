#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main()
{
    int i,j,k,n,a[10];
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=1;i<n;i++)
    {
                     k=i;
                    for(j=k-1;j>=0;j--)
                    {
                                     if(a[j]>a[k])
                                     {a[j]+=a[k];
                                     a[k]=a[j]-a[k];
                                     a[j]-=a[k];k--;}
                    }
    }
    
    cout<<"\nSorted array is: \n";
    for(i=0;i<n;i++)
    cout<<"\n"<<a[i];
    getch();
    return 0;
}        
