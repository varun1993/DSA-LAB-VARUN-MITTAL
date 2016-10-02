#include<stdio.h>
#include<conio.h>
main()
{
      int i,j,n,a[10],temp,min;
      printf("enter the no of element u want to sort");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
                      scanf("%d",&a[i]);
                      }
                     
                      for(i=0;i<=n-2;i++)
                      { min=i;
                      
                         
                         for(j=i+1;j<=n-1;j++)
                         {if(a[j]<a[min])
                         
                              min=j;}
                               temp=a[i];
                               a[i]=a[min];
                               a[min]=temp;
                               
                               }
                               for(i=0;i<n;i++)
                                        {
                                                        printf("\n%d",a[i]);
                                                        }
                                                        getch();
                                                        }
