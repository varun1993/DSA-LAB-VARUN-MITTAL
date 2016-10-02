#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;
    cout<<"\n Enter the no. of vertices:";
    cin>>n;
    int a[n][n];
    cout<<"\n Enter the weighetd adjacency matrix:";
    for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
         {
                 if(i!=j)
                 {
                         cout<<"\nElement a["<<i<<"]["<<j<<"] :";
                         cin>>a[i][j];
                 }
                 else 
                   a[i][j]=0;
         }
    int path[n][n];
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    if(a[i][j]==0)
                      path[i][j]=1000;
                    else 
                      path[i][j]=a[i][j];
            }
    }
    for(int k=0;k<n;k++)
       for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
          {
             if(i==j)
               j++;
              else
              {     
              if(path[i][j]>(path[i][k]+path[k][j]))
                  path[i][j]=path[i][k]+path[k][j];
              }
          }
    for(int i=0;i<n;i++)
    {
            cout<<endl;
            for(int j=0;j<n;j++)
            {
                    if(path[i][j]==1000)
                    {  path[i][j]=0;}
                    cout<<" "<<path[i][j];
            }
    }
    getch();
    return 0;
}
