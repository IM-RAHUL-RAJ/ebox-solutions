#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct queue
{
    char s[100];
};

int main()
{
    struct queue a[5];
    int front=-1,rear=-1,ch,i;
    char st[100];

    do
    {
        printf("Choice 1 : Enter element into Queue\nChoice 2 : Delete element from Queue\nChoice 3 : Display\nAny other choice : Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: //enqueue
                    if((front==rear+1)||((front==0)&&(rear==4)))

                    {
                        printf("Queue is full\n");
                    }
                    else
                    {printf("Enter the string to be inserted = \n");
                    scanf("%s",st);
                        if(front==-1)
                        front=0;
                        rear=(rear+1)%5;
                        strcpy(a[rear].s,st);
                    }
                    
                    break;
                    
            case 2: //Dequeue

                      if(front==-1)  //check if queue is empty
                      {
                          printf("Queue is empty\n");
                      }
                      else if (front==rear)
                      {
                          printf("The deleted element is %s\n",a[front].s);
                          front=-1;
                          rear=-1;
                          
                      }
                      else
                      {
                          printf("The deleted element is %s\n",a[front].s);
                          front=(front+1)%5;
                      }
                      
                      
                     break;
            case 3: //Display
                     if(front==-1)
                   {
                       printf("The contents of the queue are {}");
                   }
                   else
                   {
                       printf("The contents of the queue are");
                       for(i=front;i<rear;i=(i+1)%5)
                       {
                           printf(" %s",a[i].s);
                       }
                       printf(" %s",a[i].s);
                   }
                   printf("\n");   
                   break;
            case 4:break;
            default:printf("Enter valid option\n");
        }
        
    } while (ch!=4);


 return 0;   
 
}
