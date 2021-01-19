#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node*prev;
	struct node*next;
};
void append(struct node**head,int val){
	struct node*p=(struct node*)malloc(sizeof(struct node));
	p->data=val;
//	p->prev=(*head);
	p->next=NULL;
	struct node * q=(struct node*)malloc(sizeof(struct node));
	q=*head;
	if(q==NULL)
	{
	    p->prev=NULL;
	    *head=p;
	}
	else{
	    while(q->next!=NULL)
	    {
		q=q->next;	
	    }
	    q->next=p;
	    p->prev=q;
	}
	//(*head) = p;
}
void display(struct node*q){
	while(q != NULL){
		printf(" %d",q->data);
		q = q->next;
	}
}
void addafter(struct node **q ,int a,int n)
{
    int i;
    struct node*p=(struct node*)malloc(sizeof(struct node));
   struct node*t=(struct node*)malloc(sizeof(struct node));
    struct node*r=(struct node*)malloc(sizeof(struct node));
    p=*q;
    r->data=n;
    for(i=0;i<a-1;i++)
    {
        p=p->next;
    }
    if(p->next!=NULL)
    {
    t=p->next;
    r->next=p->next;
    r->prev=p;
    t->prev=r;
    p->next=r;
    }
    else{
        p->next=r;
        r->prev=p;
        r->next=NULL;
    }
}
int main(){
	struct node*head = NULL;
	int n;
	int n1;
	int a;
	int count=0;
	char ch[10];
	do{
		printf("Enter the value\n");
		scanf("%d",&n);
		count++;
		append(&head,n);
		printf("Do you want to append another node? Type Yes/No\n");
		scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));
	printf("The elements in the linked list are \n");
	display(head);
	printf("\n");
	do
	{
	printf("Enter the position after which you want to add another node\n");
	scanf("%d",&a);
	printf("Enter the value\n");
	scanf("%d",&n1);
	addafter(&head,a,n1);
	printf("The elements in the linked list are \n");
	display(head);
	printf("\n");
	printf("Do you want to add another node after a certain position? Type Yes/No\n");
	scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));
	//printf("The elements in the linked list are \n");
	//display(head);
	printf("\n");
	return 0;
}
