/*
Create an English dictionary which contains words and their meanings. Write a
C++ program to search for a word in the Dictionary Using 1) Linear search 2)
Binary Search. Also calculate the number of comparisons required to search for a
word.
*/
#include<iostream.h>
#include<conio.h>
struct node
{
     char word[20];
     char mean[40];
     node *next;
}*start=NULL,*ptr,*p,*p1;
void insert()
{
  ptr=new node;
  cout<<"\nEnter the word -";
  fflush(stdin);
  gets(ptr->word);
  cout<<"Specify meaning of the word-";
  fflush(stdin);
  gets(ptr->mean);
  if(start==NULL)
  {
    start=ptr;
    start->next=NULL;
  }
  else
  {
      ptr->next=start;
      start=ptr;
  }
}
void display()
{
     p=start;
     while(p!=NULL)
     {
       cout<<"Word-"<<p->word;
       cout<<"\nMeaning-"<<p->mean<<"\n";
       p=p->next;
     }
}
void lin_sch()
{    int z=0;
     char word[20];
     int flag=0;
     cout<<"\nEnter word to be searched-";
     fflush(stdin);
     gets(word);
     p=start;
     while(p!=NULL)
     { z++;
      if(stricmp(p->word,word)==0)
      {
      flag++;
      cout<<"\nWord found At"<<z<<" Comparison !!";
      cout<<"\nWord:"<<p->word<<"\t Meaning:"<<p->mean;
      break;
      }
      else
      p=p->next;
     }
     if(flag==0)
     cout<<"\nWord does not exist in the dictionary";
}
void bin_sch()
{ 
 char word[40];
 int z=0,count=0,mid,low,high,i,j,flag=0;
 cout<<"\nEnter the word to be searched-";
 fflush(stdin);
 gets(word);
 p=start;
 while(p!=NULL)
 {
 count++;
 p=p->next;
 }
 low=0;
 high=count;
 while(low<=high)
 {
     j=0;
     mid=(low+high)/2;
     p=start;
     while(j!=mid)
         {
           j++;
           p=p->next;
         }
      z++;
      if(stricmp(word,p->word)==0)
      {
          cout<<"\nWord found At "<<z<<" Comparison !!";
          cout<<"\nWord :Meaning="<<p->word<<": "<<p->mean;
          flag++;
          break;
      }
      else if(strcmp(word,p->word)>0)
             low=mid+1;
      else
            high=mid-1;
 }
    if(flag==0)
    cout<<"Word not found!!";
}
void sort()
{
     char t[40];
     p=start;
     while(p->next!=NULL)
     {
      p1=p->next;
      while(p1!=NULL)
     {
       if(stricmp(p->word,p1->word)>0)
     {
       strcpy(t,p->word);
       strcpy(p->word,p1->word);
       strcpy(p1->word,t);
       strcpy(t,p->mean);
       strcpy(p->mean,p1->mean);
       strcpy(p1->mean,t);
       p1=p1->next;
     }
     else
     p1=p1->next;
     }
     p=p->next;
     }
}
int main()
{
    int ch;
    char c='y';
    cout<<"\t\t\t\t\tMENU\n";
    cout<<"1.Insert\n2.Linear search\n3.Binary search\n4.Display\n";
    while(c=='y'||c=='Y')
    {
     cout<<"Enter ur choice->";
     cin>>ch;
     switch(ch)
     {
      case 1:insert();break;
      case 2:lin_sch();break;
      case 3:
           sort();
           bin_sch();
           break;
      case 4:display();
           break;
      default :cout<<"\nWrong Choice !!!";
     }
     cout<<"\nDo you want to continue :";
     cin>>c;
    }
    getch();
    return 1;
}       
     
       
       
      
     
