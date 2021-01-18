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
	p->next=(*head);
	p->prev=NULL;
	if((*head) != NULL){
		(*head)->prev=p;	
	}
	(*head) = p;
}
void display(struct node*q){
	while(q != NULL){
		printf(" %d",q->data);
		q = q->next;
	}
}
int main(){
	struct node*head = NULL;
	int n;
	char ch[10];
	do{
		printf("Enter the value\n");
		scanf("%d",&n);
		append(&head,n);
		printf("Do you want to add another node? Type Yes/No\n");
		scanf("%s",ch);
	}
	while(!strcmp(ch,"Yes"));
	printf("The elements in the doubly linked list are");
	display(head);
	printf("\n");
	return 0;
}
