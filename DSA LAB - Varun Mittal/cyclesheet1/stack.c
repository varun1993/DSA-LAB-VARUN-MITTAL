#include<stdio.h>
#include<stdlib.h>
# define STACK_SZ 3
typedef int ELEMENT;
typedef int INT;
typedef int *INTP;
typedef struct {
        ELEMENT stack[STACK_SZ];
        INT stack_len;
}STACK;
typedef STACK *STACKP;
INT STACK_is_full(STACKP stackp){
    //returns TRUE 1 or FALSE 0
    printf("STACK_is_full called \n");
    return((stackp->stack_len == STACK_SZ)?1:0);
}//STACK_is_full ends
INT STACK_is_empty(STACKP stackp){
    // returns TRUE 1 or FALSE 0
    printf("STACK_is_empty called \n");
    return((stackp->stack_len==0)?1:0);
}//stack_is_empty ends
ELEMENT STACK_peek(STACKP stackp){
        //returns top element
        printf("STACK_peek called \n");
        if(stackp->stack_len==0){
                    printf("ERROR : stack EMPTY ;STACK_peek failed \n");
                    return (0);
        }
        else{
             return(stackp->stack[stackp->stack_len-1]);
        }//else
 }//stack_peek ends
 void STACK_display(STACKP stackp){
      INT i;
      printf("STACK_display called \n");
      if(stackp->stack_len==0){
        printf("stack EMPTY\n");
        return;
      }//if
      else{
           printf("stack_length is =%d;elements from bottom are\n",stackp->stack_len);
           for(i=0;i<stackp->stack_len;i++){
                 printf("%d\t",stackp->stack[i]);
           }
           printf("\n");
      }
}//stack_display_ends
ELEMENT STACK_push(STACKP stackp,ELEMENT element){
        //returns old top element
       printf("STACK_push called \n");
       if(stackp->stack_len==STACK_SZ){
          printf("ERROR :stack FULL;STACK_push failed \n");
          STACK_display(stackp);
          return(stackp->stack[stackp->stack_len -1]);
       }
else
{  ++stackp->stack_len;
   stackp->stack[stackp->stack_len -1]=element;
   STACK_display(stackp);
   return(stackp->stack[stackp->stack_len -2]);
}
}//stack push ends
ELEMENT STACK_pop(STACKP stackp){
        printf("STACK_pop called \n");
        if(stackp->stack_len==0){
            printf("ERROR: stack EMPTY;Stack_pop failed \n");
            STACK_display(stackp);
            return(0);
}
else {
     --stackp->stack_len;
     STACK_display(stackp);
     return(stackp->stack[stackp->stack_len]);
}
}
int main(void){
     STACK stack_one={0};
     STACKP stack_onep= & stack_one;
     ELEMENT item,old_top,top;
     INT state;
     //stack is empty now
     //test stack is empty for true
     state=STACK_is_empty(stack_onep);
     printf("state=%d\n",state);
     //test stack is full for false 
     state=STACK_is_full(stack_onep);
     printf("state=%d\n",state);
     //test stack peek for empty stack
     top=STACK_peek(stack_onep);
     printf("top=%d\n",top);
     //test stack pop for empty stack
     old_top=STACK_pop(stack_onep);
     printf("old_top=%d\n",old_top);
  
 STACK_display(stack_onep);
 //stack is initialized now
 
 item=1;
 old_top=STACK_push(stack_onep,item);
 printf("old_top=%d\n",old_top);
item=3;
 old_top=STACK_push(stack_onep,item);
 printf("old_top=%d\n",old_top);
item=5;
 old_top=STACK_push(stack_onep,item);
 printf("old_top=%d\n",old_top);
 //test STACK_peek for stack
 top=STACK_peek(stack_onep);
 printf("top=%d\n",top);
 //stack is full now 
//test stack is empty for false
state=STACK_is_empty(stack_onep);
 printf("state=%d\n",state);
 //test stack is full true
 state=STACK_is_full(stack_onep);
 printf("state=%d\n",state);
 //test stack push for full
 item=7;
 old_top= STACK_push(stack_onep,item);
 printf("old_top=%d\n",old_top);
 //test stack pop for stack 
 old_top= STACK_pop(stack_onep);
 printf("old_top=%d\n",old_top);
 old_top= STACK_pop(stack_onep);
 printf("old_top=%d\n",old_top);
 old_top= STACK_pop(stack_onep);
 printf("old_top=%d\n",old_top);
 old_top= STACK_pop(stack_onep);
 printf("old_top=%d\n",old_top);
  getch();
 return 1;
}
 
      
