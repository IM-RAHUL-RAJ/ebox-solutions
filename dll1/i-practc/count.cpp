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


int count(struct node*q){
	int n = 0;
	struct node*temp = q;
	while(temp != NULL){
		n++;
		temp = temp->next;
	}
	return n;
}
void display(struct node*p){
	struct node*last;
	
	
		
		while(p != NULL){
		
		last = p;
		p=p->next;
	    }
	
	    
		while(last != NULL){
		printf(" %d",last->data);
		last=last->prev;
        }		
	
  }
int main(){
	struct node*p=NULL;
	int n;
	char ch[10];
	do{
		printf("Enter the value\n");
		scanf("%d",&n);
		append(&p,n);
		printf("Do you want to add another node? Type Yes/No\n");
		scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));
	printf("The elements in the doubly linked list are");
	display(p);
	printf("\n");
	printf("The number of nodes in the doubly linked list is %d", count(p));
	return 0;
}
