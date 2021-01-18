#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *left,*right;
};
void insert(struct node **s,int num)
{
    if((*s)==NULL)
    {
        (*s)=(struct node*)malloc(sizeof(struct node));
        (*s)->data=num;
        (*s)->left=NULL;
        (*s)->right=NULL;
    }else
    {
        if(num<(*s)->data)
        insert(&((*s)->left),num);
        else
        insert(&((*s)->right),num);
    }
}
void inorder(struct node *s)
{
    if(s!=NULL)
    {
        inorder(s->left);
        printf(" %d",s->data);
        inorder(s->right);
    }
}
int depth(struct node *s)
{
    if(s==NULL)
    {
        return 0;
    }else
    {
        int l=depth(s->left);
        int r=depth(s->right);
        if(l>r)
        return l+1;
        else
        return r+1;
    }
}
int main()
{
    struct node *head=NULL;
    char ch[5];
    int num;
    do{
        printf("Enter the element to be inserted in the tree\n");
        scanf("%d",&num);
        insert(&head,num);
        printf("Do you want to insert another element?\n");
        scanf("%s",ch);
    }while(!strcmp(ch,"yes"));
    printf("The elements in the tree are");
    inorder(head);
    printf("\n");
    printf("The maximum depth of the tree is %d\n",depth(head));
}
