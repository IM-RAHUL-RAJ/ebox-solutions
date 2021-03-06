#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};
struct node *root=NULL;
void insert(int data)
{
    struct node * new_node=(struct node*)malloc(sizeof(struct node));
    struct node *parent,*current;
    new_node->data=data;
    new_node->leftChild=NULL;
    new_node->rightChild=NULL;
    if(root==NULL)
    {
        root=new_node;
        return;
    }
    else
    {
        current=root;
        parent=NULL;
    }
    while(1)
    {
        parent=current;
        if(data<parent->data)
        {
            current=current->leftChild;
            if(current==NULL)
            {
                parent->leftChild=new_node;
                return;
            }
        }
        else
        {
            current=current->rightChild;
            if(current==NULL)
            {
                parent->rightChild=new_node;
                return;
            }
        }
    }
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf(" %d",root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
    inorder(root->leftChild);
    printf(" %d",root->data);
    inorder(root->rightChild);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf(" %d",root->data);
    }
}
int main()
{
    int n;
    //struct node *root=NULL;
    char ch[3];
    do
    {
        printf("Enter the element to be inserted in the tree\n");
        scanf("%d",&n);
        insert(n);
        printf("Do you want to insert another element?\n");
        scanf("%s",ch);
    }while(!strcmp(ch,"yes"));
    printf("Inorder Traversal : The elements in the tree are");
    inorder(root);
    printf("\nPreorder Traversal : The elements in the tree are");
    preorder(root);
    printf("\nPostorder Traversal : The elements in the tree are");
    postorder(root);
    return 0;
}
