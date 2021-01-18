#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;    
};
int count(struct Node** q){
	int n = 0;
	struct Node*temp = *q;
	while(temp != NULL){
		n++;
		temp = temp->next;
	}
	return n;
}


// void reverse(struct Node **head_ref)
// {
//      struct Node *temp = NULL;  
//      struct Node *current = *head_ref;
      
    
//      while (current !=  NULL)
//      {
//       temp = current->prev;
//       current->prev = current->next;
//       current->next = temp;              
//       current = current->prev;
//      }      
      
    
//      if(temp != NULL )
//         *head_ref = temp->prev;
// }     
 
 
 

void push(struct Node** head_ref, int new_data)
{   
    
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    
    new_node->data  = new_data;
    new_node->prev= NULL;
    new_node->next = NULL;   
    if(*head_ref==NULL){
        *head_ref = new_node;
    }
    else {
        struct Node* q=*head_ref;
        while (q->next!=NULL) {
            q=q->next;
        }
        q->next=new_node;
        new_node->prev=q;
        q=new_node;
    }
}
void deleteNode(struct Node** head_ref, struct Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return ;
 
    if (*head_ref == del){
    	*head_ref = del->next;
    	printf("System %d has been removed from the particular position\n",del->data);
    	if(*head_ref != NULL) {
    	    (*head_ref)->prev = NULL;
    	}
    	free(del);
	}
        
    else {
        del->prev->next=del->next;
        if(del->next!=NULL) {
            del->next->prev=del->prev;
        }
        printf("System %d has been removed from the particular position\n",del->data);
        free(del);
    }

}
void deleteNodeAtGivenPos(struct Node** head_ref, int n)
{
   int p;
    if (*head_ref == NULL || n <= 0){
    	printf("There is no System\n");
    	return ;
	}
	
	p=count(head_ref);
    if(n > p){
		printf("There are less than %d Systems in the lab\n",n);
		return ;
	}    
 
    struct Node* current = *head_ref;
    
 
    for (int i =1;current != NULL && i < n; i++)
        current = current->next;
 
    deleteNode(head_ref, current);
}
 
void display_reverse(struct Node *p) {
    if(p==NULL)
        return;
    display_reverse(p->next);
    printf("%d ",p->data);
    
 }
 
void display(struct Node*p)
{

	    if(p==NULL){
	    	printf("There is no System\n");
	    	return;
		}
        while(p != NULL){
		printf("%d ",p->data);
		p=p->next;
	    }
	    printf("\n");

} 


int main(){
	struct Node*head = NULL;
	int n,i,ch;
	while(1){
		printf("1.Add a system IP\n");
		printf("2.Display IP's\n");
		printf("3.Remove a system\n");
		printf("4.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				printf("Enter the System IP to Insert:\n");
				scanf("%d",&n);
				push(&head,n);
				break;
			}
			case 2:{
				if(head==NULL){
	    	    printf("There is no System\n");
	    	    }
	    	    else{
	    	    printf("System IP's in Inserted order:\n");
				display(head);
				printf("System IP's in Reverse order:\n");
				display_reverse(head);
				printf("\n");
				
				}
			  break;
			}
			case 3:{
		        printf("Enter a System IP position to be removed:\n");
				scanf("%d",&i);
				deleteNodeAtGivenPos(&head,i);
				
				break;
			}
			case 4: printf("Exit");
                exit(0);
                break;

    default: printf("\nPlease enter the valid choice");
		}
	}
	
return 0;
}
