#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int a[5];
    int top;
};

void initstack(struct stack *p)
{
    p->top = -1;
}

void display(struct stack p)
{
    if(p.top==-1)
    printf("{}");
    else
    {
    for(int i = 0; i<=p.top; i++)
    {
        printf(" %d",p.a[i]);
    }
    }
}
void push(struct stack *p, int item)
{
    if(p->top>=4)
    printf("Stack is full\n");
    else
    {
        p->a[++p->top] = item;
    }
}

int main()
{
    struct stack s;
    initstack(&s);
    printf("The contents of the stack are ");
    display(s);
        printf("\nEnter the element to be pushed\n");
            int ele;
            scanf("%d",&ele);
            push(&s,ele);
    while(1)
    {
        printf("The contents of the stack are");
        display(s);
        printf("\nDo you want to push another element into the stack? Type Yes/No\n");
        char c[3];
        scanf("%s",c);
        if(strcmp(c, "Yes") == 0)
        {
            printf("Enter the element to be pushed\n");
            int ele;
            scanf("%d",&ele);
            push(&s,ele);
        }
        else
        break;
    }
    return 0;


}
