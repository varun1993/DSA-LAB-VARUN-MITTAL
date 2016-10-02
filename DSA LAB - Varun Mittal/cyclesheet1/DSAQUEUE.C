#include<stdio.h>
#include<stdlib.h>
# define QUEUE_SZ 5
typedef int ELEMENT ;
typedef ELEMENT *ELEMENTP ;
typedef int INT ;
typedef int * INTP ;
typedef struct {
        ELEMENT queue[QUEUE_SZ];
        INT queue_len; 
        INT queue_head;
        INT queue_tail;
}QUEUE;
typedef QUEUE *QUEUEP ;

INT QUEUE_is_full(QUEUEP queuep){
    printf("QUEUE_is_full called \n");
    return ((queuep->queue_len == QUEUE_SZ)?1:0);
}
INT QUEUE_is_empty(QUEUEP queuep){
    printf("QUEUE_is_empty called \n");
    return ((queue->queue_len==0)?1:0);
}
void QUEUE_display(QUEUEP queuep){
     INT i,len,head,tail;
     len=queuep->queue_len;
     head= queuep->queue_head;
     tail=queuep->queue_tail;
     printf("QUEUE_display called \n");
     if(len==0)
     {
               printf("queue EMPTY\n");
               return ;
     }
     else {
           printf("queue_length is = %d,head=%d,tail=%d elements from head to tail are \n",len,head,tail);
               if(tail>head)
                   {
                      if(tail-head==len)
                                {
                                  for(i=head;i<tail;i++)
                                      {
                                               printf("%d \t",queuep->queue[i]);
                                      }
                                 }
                                 else 
                                 {
                                         for(i=head;i<=0;i--)
                                        {
                                                 printf("%d \t",queuep->queue[i]);
                                         }
                                        for(i=QUEUE_SZ-1;i<tail;i--)
                                      {
                                              printf("%d \t",queuep->queue[i]);
                                      }
                                 }
                        }
                    }
                       else if((tail==head)&&(len==QUEUE_SZ))||(((head-tail)>0)&&((head-tail)!=len))){
                              if(head-tail==len)
                              {
                                             for(i=head;i<tail;i--)
                              {
                                                        printf("%d\t",queuep->queue[i-1]);
                               }
                         }else{
                                    for(i=head;i<QUEUE_SZ;i++)
                                    {
                                         printf("%d\t",queuep->queue[i-1]);
                                    }
                                   for(i=1;i<=tail;i++)
                                   {
                                            printf("%d\t",queuep->queue[i-1]);
                                   }          
                              }
                        }
                       printf("\n");
          }
     }

    void QUEUE_enqueue(QUEUE queue,ELEMENT element){
         INT tail;
         tail=queuep->queue_tail;
         printf("QUEUE_enqueue called \n");
         if(queuep->queue_len==QUEUE_SZ){
               printf("ERROR :queue FULL;QUEUE_enqueue failed \n");
         }else{
               queuep->queue[tail]=element ;
               ++queuep->queue_len;++tail;
               tail=tail%QUEUE_SZ;
               queuep->queue_tail=tail;
         }
         QUEUE_display(queuep);
}
    void QUEUE_dequeue(QUEUEP queuep,ELEMENTP elementp){
         INT head;
         head=queuep->queue_head;
         elementp=&queuep->queue[head];
         printf("QUEUE_dequeue called \n");
         if(queuep->queue_len==0)
        {
                                 printf("ERROR: queueEMPTY;QUEUE_dequeue failed\n");
        }
        else {
             --queuep->queue_len;
             ++head;
             head=head%QUEUE_SZ;
             queuep->queue_head=head;
             QUEUE_display(queuep) ;
             }
        }
        
int main(void){
       QUEUE queue_one={0};
       QUEUEP queue_onep=&queue_one;
       ELEMENT item;
       ELEMENTP itemp;
       INT state;
       state=QUEUE_is_empty(queue_onep);
       printf("state=%d\n",state);
       state=QUEUE_is_full(queue_onep);
       printf("state=%d\n",state);
       QUEUE_dequeue(queue_onep,itemp);
       QUEUE_display(queue_onep);
       item =1;
       QUEUE_enqueue(queue_onep,item);
       item =3;
       QUEUE_enqueue(queue_onep,item);
       item =5;
       QUEUE_enqueue(queue_onep,item);
       item =7;
       QUEUE_enqueue(queue_onep,item);
       item =9;
       QUEUE_enqueue(queue_onep,item);
       // TEST QUEUE IS FULL TRUE
       state=QUEUE_is_full(queue_onep);
       printf("state=%d\n",state);
       item =11;
       QUEUE_enqueue(queue_onep,item);
       //test queue dequeue 
       QUEUE_dequeue(queue_onep,itemp);
       QUEUE_dequeue(queue_onep,itemp);
       QUEUE_dequeue(queue_onep,itemp);
       
       //test queue display 
       item =13;
       QUEUE_enqueue(queue_onep,item);
       item =15;
       QUEUE_enqueue(queue_onep,item);
       item =17;
       QUEUE_enqueue(queue_onep,item);
       item =19;
       QUEUE_enqueue(queue_onep,item);
       item =21;
       QUEUE_enqueue(queue_onep,item);
       QUEUE_dequeue(queue_onep,itemp);
       QUEUE_dequeue(queue_onep,itemp);
       getch();
       return 1;
}
