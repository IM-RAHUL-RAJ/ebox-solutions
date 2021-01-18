#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node * link;
};
void append (struct node **q, int num); 
void display (struct node *q) ;
int count (struct node *q) ;
int findmid (struct node *q);
int main()
{
    int a,mid;
    struct node  * p;
    char ch[50];
    p=(struct node*)malloc(sizeof(struct node));
    p=NULL;
    do 
    {
        printf("Enter the value\n");
        scanf("%d",&a);
        append(&p,a);
        printf("Do you want to add another node? Type Yes/No\n");
        scanf("%s",ch);
    }while(!strcmp(ch,"Yes"));
    printf("The elements in the linked list are");
    display(p);
    mid = findmid(p);
    printf("The middle element in the linked list is %d\n",mid);
    return 0;
}
void append(struct node ** q,int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->link = NULL;
    temp->data = num;
    if(*q==NULL){
        *q = temp;
        //temp->link=NULL;
    }
    
    else{
        struct node * p;
        p=*q;
        while((p->link)!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
        //temp->link=NULL;
    }
    
}
int count(struct node * q)
{
    struct node * p;
    p=q;
    int c=0;
    while(p->link!=NULL)
    {
        p=p->link;
        c++;
    }
    return c;
}
int findmid(struct node * q)
{
    struct node * p;
    int c =0;
    int x;
    p=q;
    c = count(q);
    c=c/2;
    int i;
    for(i=0;i<c;i++)
    {
        p=p->link;
    }
    //return 
    x=p->data;
    return x;
}
void display(struct node * q)
{
    struct node  * p;
    p=q;
    while((p->link)!=NULL)
    {
        printf(" %d",p->data);
        p=p->link;
    }
    printf(" %d",p->data);
}
