#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data ;
	struct node * link ;
} ;


void addcirq(struct node**,struct node**,int);
int delcirq (struct node**,struct node**);
void cirq_display ( struct node * ) ;
void printMenu();

int main()
{
	struct node *front = NULL, *rear = NULL ;
	int data,ch, data1;
	do {
	printMenu();
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch) {
	  case 1:
		printf("Enter the element to be inserted/entered\n");
		scanf("%d",&data);
		addcirq(&front,&rear,data);
		break;
	  case 2:
		data1 = delcirq(&front,&rear);
		if(data1 != -1000)
		printf("The deleted element is %d\n",data1);
		break;
	  case 3:
		printf("The contents of the queue are");
		cirq_display ( front ) ;
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


void addcirq ( struct node **f,struct node **r,int item )
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->link=NULL;
    if((*f)==NULL && (*r)==NULL)
    {
        (*f)=(*r)=newnode;
        (*r)->link=(*f);
    }
    else
    {
        (*r)->link=newnode;
        (*r)=newnode;
        newnode->link=(*f);
    }
  }
int delcirq (struct node **f,struct node **r)
{
    int item;
    struct node *temp=(*f);
    if((*f)==NULL && (*r)==NULL)
    {
        printf("Queue is empty\n");
        return -1000;
    }
    item=temp->data;
    if((*f)==(*r))
    {
        (*f)=(*r)=NULL;
        free(temp);
    }
    else
    {
        (*f)=(*f)->link;
        (*r)->link=(*f);
        free(temp);
    }
return item;
  }


void cirq_display ( struct node *f )
{
    struct node *temp;
    temp=f;
    if(f==NULL)
    {
        printf("{}");
    }
    else{
        do
        {
        printf("%d ",temp->data);
        temp=temp->link;
        }
        while(temp!=f);
    }
}
