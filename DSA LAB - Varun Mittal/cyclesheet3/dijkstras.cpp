#include<iostream>
using namespace std;
class graph
{
      int data[100][100],size,weight[100][100],dist[100],path[100];
      bool known[100];
      public:
             graph(int n)
             {
                    size=n;
                    for(int i=0;i<size;i++)
                    {
                            dist[i]=1000;
                            known[i]=0;
                            path[i]=-1;
                            for(int j=0;j<size;j++)
                            {       
                                    data[i][j]=0;
                                    weight[i][j]=1000;
                            }
                    }
             }
             void make()
             {
                  int no,ver,wt;
                  for(int i=0;i<size;i++)
                  {
                          cout<<"\nEnter the no of adjacent vertices of ( V"<<i+1<<" ) : ";
                          cin>>no;
                          for(int j=0;j<no;j++)
                          {
                                  cout<<"\nEnter the vertex ( "<<j+1<<" ) : V";
                                  cin>>ver;
                                  cout<<"\nEnter the weight : ";
                                  cin>>wt;
                                  if((ver>0)&&(ver<size+1)&&(ver!=i+1))
                                  {       
                                          data[i][ver-1]=1;
                                          weight[i][ver-1]=wt;
                                  }
                          }
                  }
             }
             void show()
             {
                    cout<<"\n\nVertex\tKnown\tDist\tPath";
                    for(int i=0;i<size;i++)
                      cout<<"\nV"<<i+1<<"\t"<<known[i]<<"\t"<<dist[i]<<"\tV"<<path[i]+1;
             }
             void djkstra()
             {
                   int v,w,min=1000,temp=0;
                   dist[0]=0;
                   path[0]=-1;
                   while(1)
                   {
                       temp=0;
                       min=1000;
                       for(int i=0;i<size;i++)  //to get v = smallest unknown vertex
                       {
                            if((known[i]==0)&&(min>dist[i]))
                            {  
                                min=dist[i];
                                v=i;           
                            }
                            else if(known[i]==1)
                                temp++;
                       }
                       if(temp==size)   // to get out of while(1)
                       {
                            break;
                       }
                       known[v]=1;
                       for(int i=0;i<size;i++)
                       if(i!=v)
                       {
                                     //system("pause");
                           if(known[i]==0)
                           {
                                //system("pause");
                               if(dist[v]+weight[v][i]<dist[i])
                               {     
                                     //system("pause");
                                     dist[i]=dist[v]+weight[v][i];
                                     path[i]=v;
                               }
                           }//end of if(known)
                       }  //end of if(i!=v)
                       show();
                   }//  end of while(1)
             }  // end of function
};
int main()
{
    int n;
    cout<<"\nEnter the no of vertices : ";
    cin>>n;
    graph g1(n);
    cout<<endl;
    cout<<"\nEnter :\n\n";
    g1.make();
    g1.djkstra();
    system("pause");
    return 0;
}
