#include<stdio.h>
#include<math.h>
#include<string.h>
struct queue {
  int contents[5];
  int front;
  int rear;
  int count;
} ;

void initQueue(struct queue * q);
void enQueue(struct queue * q, int element);
int deQueue(struct queue * q);
void display( struct queue q);
void printMenu();

int main()
{
	struct queue p;
	int data,ch, data1;
	initQueue(&p);
	do {
	printMenu();
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch) {
	  case 1:
		printf("Enter the element to be inserted/entered\n");
		scanf("%d",&data);
		enQueue(&p, data);
		break;
	  case 2:
		data1 = deQueue(&p);
		if(data1 != -1000)
		printf("The deleted element is %d\n",data1);
		break;
	  case 3:
		printf("The contents of the queue are ");
		display(p);
		printf("\n");
		break;
	  default:
		return 0;
	}
	} while(1);
	return 0;
}


void printMenu()
{
	printf("Choice 1 : Enter element into Queue\n");
	printf("Choice 2 : Delete element from Queue\n");
	printf("Choice 3 : Display\n");
	printf("Any other choice : Exit\n");
}

void initQueue(struct queue * q) {
//fill the code
    q->front=0;
    q->rear=0;
    q->count=0;
}

void enQueue(struct queue * q, int element)
{
//fill the code
    if(q->count==5){
        printf("\nQueue is Full");
    }
    else{
        q->contents[q->rear]=element;
        q->rear=(q->rear+1)%5;
        //q->contents[q->rear]=element;
        q->count++;
    }
}

int deQueue(struct queue * q)
{
    int x=-1;
//fill the code
if(q->count==0){
    printf("\nQueue is empty");
    return -1000;
    
}
else{
     x=q->contents[q->front];
    q->front=(q->front+1)%5;
     //x=q->contents[q->front];
    q->count--;
}
return x;
}

void display( struct queue q)
{
//fill the code
    if(q.count==0){
        printf(" {}\n");
        
    }
    else{
        for(int i=0;i<q.count;i++){
            printf("%d ",q.contents[(q.front+i)%5]);
            // printf("\n");
        }
    }
}
