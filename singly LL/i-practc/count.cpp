#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *link;
};

void append(struct node **q, int num) ;

void display(struct node *q) ;
int count(struct node *q) ;



int main(void){
    struct node *p;
    p = NULL;
    int n;
    char ch[10];
    do{
        printf("Enter the value\n");
        scanf("%d", &n);
        append(&p, n);
        printf("Do you want to add another node? Type Yes/No\n");
        scanf("%s", ch);
    }while(!strcmp("Yes", ch));
    printf("The elements in the list are ");
    display(p);
    printf("\nThe number of elements in the linked list is %d", count(p));
    return 0;
}

void append(struct node **q, int num){
    if(*q == NULL){
        *q = (struct node *)malloc(sizeof(struct node));
        (**q).data = num;
    }else{
        struct node *temp;
        temp = *q;
        while((*temp).link != NULL){
            temp = (*temp).link;
        }
        (*temp).link = (struct node *)malloc(sizeof(struct node));
        temp = (*temp).link;
        (*temp).data = num;
    }
}

void display(struct node *q){
    struct node *temp;
    temp = q;
    while(temp != NULL){
        printf("%d ", (*temp).data);
        temp = (*temp).link;
    }
}

int count(struct node *q){
    int n = 0;
    struct node *temp;
    temp = q;
    while(temp != NULL){
        n++;
        temp = (*temp).link;
    }
    return n;
}
