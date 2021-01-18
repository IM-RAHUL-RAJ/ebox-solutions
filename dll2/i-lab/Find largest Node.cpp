#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void append(struct node **head, int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = n;
    temp->next = (*head);
    temp->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = temp;
    (*head) = temp;
}
void Print(struct node *head)
{
    struct node *last;
    printf("Linked List is ");
    while (head != NULL)
    {
        last = head;
        head = head->next;
    }

    while (last != NULL)
    {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}
int Largest(struct node *head)
{
    int max = head->data;
    while (head != NULL)
    {
        if (max < head->data)
        {
            max = head->data;
        }
        head = head->next;
    }
    return max;
}
int main()
{
    char ch[2] = "Y";
    int n, lg;
    struct node *head = NULL;
    while (!strcmp(ch, "Y") || !strcmp(ch, "y"))
    {
        printf("Enter node value:");
        scanf("%d", &n);
        append(&head, n);
        printf("Do you want to enter more?(Y or N)\n");
        scanf("%s", ch);
    }
    Print(head);
    lg = Largest(head);
    printf("Largerst node is %d", lg);

    return 0;
}
