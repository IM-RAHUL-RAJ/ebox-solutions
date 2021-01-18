#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tnode
{
	int data;
	struct tnode * leftc;
	struct tnode * rightc;
};

void insert(struct tnode **, int num);
void inorder(struct tnode *);
void printLevelOrder(struct tnode* root);
void printGivenLevel(struct tnode* root, int level);
int height(struct tnode* node);


int main()
{
	struct tnode * root=NULL;
	char ch[5];
	int num;
	do  {
		printf("Enter the element to be inserted in the tree\n");
		scanf("%d",&num);
		insert(&root, num);
		printf("Do you want to insert another element?\n");
		scanf("%s",ch);
	}while(strcmp(ch,"yes")==0);

	printf("Inorder Traversal : The elements in the tree are");
	inorder(root);
	printf("\n");
	printf("The elements in the tree in level order are");
	printLevelOrder(root);
	printf("\n");
	return 0;
}

void insert(struct tnode ** s, int num) {
	if((*s) == NULL) 	{
		(*s) = (struct tnode *) malloc( sizeof (struct tnode));
		(*s)->data = num;
		(*s)->leftc = NULL;
		(*s)->rightc = NULL;
	}
	else 	{
	if(num < (*s)->data)
	  insert(&( (*s)->leftc ), num);
	else
	  insert(&( (*s)->rightc ), num);
	}
}

void inorder(struct tnode * s)  {
	if(s != NULL) 	{
		inorder(s->leftc);
		printf(" %d",s->data);
		inorder(s->rightc);
	}
}

void printLevelOrder(struct tnode* root)  {
  int h = height(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
}    
 
void printGivenLevel(struct tnode* root, int level)  {
  if(root==NULL)
    {
        return;
    }
    if(level==1)
    {
        printf(" %d",root->data);
    }
    else if(level>0)
    {
        printGivenLevel(root->leftc,level-1);
        printGivenLevel(root->rightc,level-1);
    }
}
 
int height(struct tnode* node) {
   if (node==NULL)
       return 0;
   else    {
       
     int lheight = height(node->leftc);
     int rheight = height(node->rightc);

     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
}
