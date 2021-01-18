#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node

{

int data;

struct node * link;

};

void append (struct node **,int); 
void addafter (struct node *,int,int);
void display (struct node *);  
int main()
{
    char inp[4]="Yes";
    int n,pos;
    struct node* head = NULL;
    while(!strcmp(inp,"Yes"))
    {
        printf("Enter the value\n");
        scanf("%d",&n);
        append(&head,n);
        printf("Do you want to append another node? Type Yes/No\n");
        scanf("%s",inp);
    }
    printf("The elements in the linked list are ");
    display(head);
    strcpy(inp,"Yes");
    while(!strcmp(inp,"Yes"))
    {
        printf("Enter the position after which you want to add another node\n");
        scanf("%d",&pos);
        printf("Enter the value\n");
        scanf("%d",&n);
        addafter(head,pos,n);
        printf("The elements in the linked list are ");
        display(head);
        printf("Do you want to add another node after a certain position? Type Yes/No\n");
        scanf("%s",inp);
        
    }
    
    return 0;
}
void append(struct node **head,int n)
{
    struct node* temp;
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->link = NULL;
    temp = *head;
    if(temp==NULL)
    {
        *head = newnode;
    }
    else
    {
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
    
}
void display(struct node* head)
{
    
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->link;
    }
    printf("\n");
}
void addafter (struct node *head,int pos,int n) 
{
    int ind = 0;
    while(ind!=pos && head->link!=NULL)
    {
        head = head->link;
        ind++;
    }
    if(ind<pos)
    {
        printf("There are less than %d elements in the linked list\n",pos);
        return;
    }
    struct node *temp;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    temp = head->link;
    newnode->data = n;
    newnode->link = temp;
    head->link = newnode;
}
