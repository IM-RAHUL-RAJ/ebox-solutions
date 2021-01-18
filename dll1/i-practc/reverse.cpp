#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;    
};
 
void reverse(struct Node **head_ref)
{
     struct Node *temp = NULL;  
     struct Node *current = *head_ref;

     while (current !=  NULL)
     {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;              
       current = current->prev;
     }      

     if(temp != NULL )
        *head_ref = temp->prev;
}     
 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
  
    new_node->data  = new_data;
    
    new_node->prev = NULL;
  
    new_node->next = (*head_ref);    
 
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;    
  
    (*head_ref)    = new_node;
}

void printList(struct Node*p)
{
  struct Node*last;
	
	
		
		while(p != NULL){
		
		last = p;
		p=p->next;
	    }
	
	    
		while(last != NULL){
		printf("%d ",last->data);
		last=last->prev;
        }		
	
} 
int main(){
	struct Node*head = NULL;
	int n;
	char ch[10];
	do{
		printf("Enter the element to insert:\n");
		scanf("%d",&n);
		push(&head,n);
		printf("Do you want insert again yes/no:\n");
		scanf("%s",ch);
	}
	while(!strcmp(ch,"yes"));
	printf("Before Reversing:");
	printList(head);
	printf("\n");
	printf("After Reversing:");
	reverse(&head);
	printList(head);
	printf("\n");
	return 0;
}
