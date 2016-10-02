/*
6. Write a C++ program to sort an array of 10 elements using Heap sort algorithm. (
construct a MAX_Heap and also perform In-place sorting ).
*/
#include <iostream>
#include<conio.h>
using namespace std;
const int size=10;
class array
{
	private :
		    int heap[size] ;
		    int end ;
	public :
		   array()
		   {
                 end=size-1;
                 int i;
                 cout<<"\nEnter The 10 Elements :";
                 for(i=0;i<size;i++)
                                    cin>>heap[i];
                 buildmaxheap();
           }
           void buildmaxheap()
           {
                int i;
                for(i=(end-1)/2;i>=0;i--)
                      maxheapify(i);
           }
           void maxheapify(int pos)
           {
                int i=pos;
                int j=2*i+1;
                int k=2*i+2;
                int largest=i;
                if((j<=end)&&(heap[j]>heap[largest]))
                        largest=j;
                if((k<=end)&&(heap[k]>heap[largest]))
                        largest=k;
                if(largest!=i)
                {       int temp=heap[i];
                        heap[i]=heap[largest];
                        heap[largest]=temp;
                        maxheapify(largest);
                }
           }
           void heapsort()
           {
                while(end>0)
                 deletemax();
           }
           void deletemax()
           {
                int temp=heap[0];
                heap[0]=heap[end];
                heap[end]=temp;
                end--;
                maxheapify(0);
           }
           void print()
           {
                cout<<"\nSorted Elements :";
                int i;
                for(i=0;i<size;i++)
                                   cout<<heap[i]<<"\t";
           }
};
int main()
{
    array h;
    h.heapsort();
    h.print();
    getch();
    return 1;
}
                              
                        
