#include<iostream>
#include <conio.h>
using namespace std;
class ShellSort
{
    private:
        int n;
        int elements[16];
    public:
        void getarray();
        void sortit(int[],int,int);
        int returnn();
        void display();
};
void ShellSort::getarray()
{
     n=16;
     elements[0]=15;     elements[1]=11;     elements[2]=8;     elements[3]=5;     elements[4]=2;     elements[5]=14;     elements[6]=10;     elements[7]=7;
     elements[8]=4;     elements[9]=1;     elements[10]=13;     elements[11]=9;     elements[12]=6;     elements[13]=3;     elements[14]=0;     elements[15]=12;
}
int ShellSort::returnn()
{
    return n;
}
void ShellSort::sortit(int arr[],int numinc,int val)
{
    int i,j,k,span,y;int sp=3;
    for(i=0;i<numinc;i++)
    {
        span=arr[i];
        for(j=span;j<n;j++)
        {
            y=elements[j];
            for(k=j-span;k>=0 && y<elements[k];k-=span)
            {
                elements[k+span]=elements[k];
            }
            elements[k+span]=y;
        }
      //  if(i==numinc-1)
        cout<<"\n";
        cout<<"Iteration "<<i+1<<":  Span="<<span<<" \t";
        display();
        if(span==1)
        break;
    }
}
void ShellSort::display()
{
    for(int i=0;i<n;i++)
    {
        cout<<elements[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    ShellSort ob;
    int n,i,j;
    ob.getarray();
    n=ob.returnn();
    int arr[n];
    arr[0]=5;    arr[1]=3;    arr[2]=1;
    cout<<"Given:   15 11 8 5 2 14 10 7 4 1 13 9 6 3 0 12\n";
    ob.sortit(arr,3,j);
    getch();
}
