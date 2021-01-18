#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tnode {
	int data;
	struct tnode * leftc;
	struct tnode * rightc;
};

void insert(struct tnode **, int num);
void inorder(struct tnode *);
void printPaths(struct tnode* node);
void printPathsRecur(struct tnode* node, int path[], int pathLen);
void printArray(int ints[], int len);

int main()
{
	struct tnode * root=NULL;
	char ch[5];
	int num;
	do 	{
	printf("Enter the element to be inserted in the tree\n");
	scanf("%d",&num);
	insert(&root, num);
	printf("Do you want to insert another element?\n");
	scanf("%s",ch);
	}while(strcmp(ch,"yes")==0);

	printf("The elements in the tree are");
	inorder(root);
	printf("\n");
	printf("The root to leaf paths in the tree are\n");
	printPaths(root);
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

void inorder(struct tnode * s) {
	if(s != NULL) 	{
	inorder(s->leftc);
	printf(" %d",s->data);
	inorder(s->rightc);
	}
}

void printPaths(struct tnode* node) {
	  int path[1000];
	  printPathsRecur(node, path, 0);
}
 
void printPathsRecur(struct tnode* node, int path[], int pathLen) {

  if(node==NULL)
  {
      return;
  }
  path[pathLen]=node->data;
  pathLen++;
  if(node->leftc==NULL&&node->rightc==NULL)
  {
      printArray(path,pathLen);
  }
  else
  {
      printPathsRecur(node->leftc,path,pathLen);
      printPathsRecur(node->rightc,path,pathLen);
  }

}

void printArray(int ints[], int len) {
	int i;
	for (i=0; i<len; i++) {
	    printf("%d ", ints[i]);
	}
	printf("\n");
  
}
