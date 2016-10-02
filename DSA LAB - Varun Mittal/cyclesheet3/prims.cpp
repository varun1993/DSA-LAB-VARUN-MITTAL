/*
Write a C++ program to find the minimum spanning tree of the following graph
using Prim’s algorithm.
*/
#include<iostream>
using  namespace std;
class prims
{
  private:
    int n; //no of nodes
    int graph_edge[250][4]; //edges in the graph
    int g; //no of edges in the graph
    int tree_edge[250][4]; //edges in the tree
    int t; //no of edges in the tree
    int s; //source node
    //Partition the graph in to two sets
    int T1[50],t1; // Set 1
    int T2[50],t2; // Set 2
 public:
    void input();
    int findset(int);
    void algorithm();
    void output();
};
void prims::input()
{
     int i,j;
cout<<"Enter the no. of nodes in the undirected weighted graph ::";
cin>>n;
g=0;
cout<<"Enter the weights for the following edges ::\n";
for(i=1;i<=n;i++)
{
 for(j=i+1;j<=n;j++)
  {
     cout<<" < "<<i<<" , "<<j<<" > ::";
     int w;
     cin>>w;
     if(w!=0)
     {
        g++;
        graph_edge[g][1]=i;
        graph_edge[g][2]=j;
        graph_edge[g][3]=w;
     }
  }
}
// print the graph edges
cout<<"\n\nThe edges in the given graph are::\n";
for(i=1;i<=g;i++)
   cout<<" < "<<graph_edge[i][1]<<" , "<<graph_edge[i][2]<<" > ::"<<graph_edge[i][3]<<endl;
}
int prims::findset(int x)
{
    int i;
for(i=1;i<=t1;i++)
  if(x==T1[i])
    return 1;
for(i=1;i<=t2;i++)
 if(x==T2[i])
   return 2;
 return -1;
}
void prims::algorithm()
{
t=0;
t1=1;
T1[1]=1; //The source node
t2=n-1;
int i;
for(i=1;i<=n-1;i++)
   T2[i]=i+1; //The reamining nodes
while(g!=0 && t!=n-1)
{
// Find the least cost edge
    int min=9999;
    int p;
    int u,v,w;
    for(i=1;i<=g;i++)
    {
        //if u and v are in different sets
        if(findset(graph_edge[i][1])!=findset(graph_edge[i][2]))
        {
          if(min>graph_edge[i][3])
          {
           min=graph_edge[i][3];
           u=graph_edge[i][1];
           v=graph_edge[i][2];
           w=graph_edge[i][3];       
           p=i;
          }
        }
     }
     //break if there is no such edge
    cout<<"The edge included in the tree is ::";
    cout<<" < "<<u<<" , "<<v<<" > "<<endl;
    //delete the edge from graph edges
    for(int l=p;l<g;l++)
    {
        graph_edge[l][1]=graph_edge[l+1][1];
        graph_edge[l][2]=graph_edge[l+1][2];
        graph_edge[l][3]=graph_edge[l+1][3];
    }
    g--;
    //add the edge to the tree
    t++;
    tree_edge[t][1]=u;
    tree_edge[t][2]=v;
    tree_edge[t][3]=w;
    //Alter the set partitions
    t1++;
    int m;
    if(findset(v)==2)
    {
        T1[t1]=v;
        m=v;
    }
    else if(findset(u)==2)
    {
        T1[t1]=u;
        m=u;
    }
    int x;
    for(x=1;T2[x]!=m;x++);
    for(;x<t2;x++)
         T2[x]=T2[x+1];
          t2--;
    // Print the sets
int k;
cout<<"NOW\nT1 :: ";
for(k=1;k<=t1;k++)
cout<<T1[k]<<" ";
cout<<endl;
cout<<"T2 :: ";
for(k=1;k<=t2;k++)
cout<<T2[k]<<" ";
cout<<endl;
cout<<"The graph edges are ::\n";
for(i=1;i<=g;i++)
cout<<" < "<<graph_edge[i][1]<<" , "<<graph_edge[i][2]<<" > ::"<<graph_edge[i][3]<<endl;
cout<<endl<<endl;
}
}
void prims::output()
{
cout<<"\nThe selected edges are ::\n";
for(int i=1;i<=t;i++)
cout<<" < "<<tree_edge[i][1]<<" , "<<tree_edge[i][2]<<" > ::"<<tree_edge[i][3]<<endl;
}
int main()
{
prims obj;
obj.input();
obj.algorithm();
obj.output();
system("PAUSE");
return 0;
}
















