//Write a C++ program to traverse the following digraph using topological sorting
#include<iostream>
using namespace std;
int i,j,n,m,times;
int a[10][10],visited[10],arrival[10];
struct node
{
   int x,departure;
}ns[10];
void dfs(int i) 
{ 
   visited[i]=1;
   arrival[i]=++times;
   for(int j=1;j<=n;j++)
   {
     if((a[i][j]==1)&&(visited[j]==0))
     dfs(j);
   }
   ns[i].departure=++times;
}
void topo_sort()
{
    node tmp;
    for(i=1;i<=n;i++)
    for(j=1;j<=n-1-i;j++)
    if(ns[j].departure<ns[j+1].departure)
    {
       tmp=ns[j];
       ns[j]=ns[j+1];
       ns[j+1]=tmp;
    } 
    cout<<"\ntopologically sorted nodes:\n";
    for(i=1;i<=n;i++)
    cout<<ns[i].x<<" ";
}
int main()
{
   cout<<"enter no. of vertices:"; cin>>n;
   cout<<"enter no. of edges:"; cin>>m;  
   for(i=1;i<=n;i++)
   { ns[i].x=i;
     ns[i].departure=0;
     for(j=1;j<=n;j++)
     a[i][j]=0;
   }
   cout<<"enter edges:";
   while(m)
   {
           cout<<"\n<i,j>:";cin>>i>>j;
           a[i][j]=1;
           m--;
   }
   cout<<"\nStarting node?:";
   cin>>i;
   cout<<"\nDFS started from node:"<<i;
   dfs(i);
   for(i=1;i<=n;i++)
   if(visited[i]==0)
   dfs(i);
   topo_sort();
   cout<<endl; 
   system("pause");
   return 0;
}
