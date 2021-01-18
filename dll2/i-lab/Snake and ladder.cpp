#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void append(struct node **p, int n);
void display(struct node *p);
void playGame(struct node *p, int *a, int n);

int main()
{
    struct node *p;
    p = NULL;
    int choice, num, dice_num, size = 0, a[100], n;
    do
    {
        printf("1.Insert a square\n");
        printf("2.View board\n");
        printf("3.Play the game\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the square number\n");
            scanf("%d", &num);
            append(&p, num);
            size += 1;
            break;

        case 2:
            display(p);
            break;

        case 3:
            if (size == 0)
            {
                printf("Board is empty\n");
                continue;
            }
            printf("Enter the number of times you want to throw dice\n");
            scanf("%d", &n);
            printf("Enter the number on the dice\n");
            int i = 0;
            while (i < n)
            {
                scanf("%d", &dice_num);
                if (dice_num < 1 || dice_num > 6)
                {
                    printf("Invalid Input\n");
                    continue;
                }
                a[i++] = dice_num;
            }
            playGame(p, a, n);
            break;

        default:
            printf("Exit\n");
            break;
        }
    } while (choice != 4);
    return 0;
}

void append(struct node **q, int num)
{
    struct node *temp;
    if (*q == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        temp->prev = NULL;
        temp->next = NULL;
        *q = temp;
    }
    else
    {
        temp = *q;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        struct node *newn;
        newn = (struct node *)malloc(sizeof(struct node));
        newn->data = num;
        newn->next = NULL;
        newn->prev = temp;
        temp->next = newn;
    }
}

void display(struct node *q)
{
    struct node *temp;
    temp = q;
    if (temp == NULL)
    {
        printf("Board is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != NULL)
            {
                printf(" ");
            }
        }
        printf("\n");
        temp = q;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->prev;
            if (temp != NULL)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void playGame(struct node *q, int *a, int n)
{
    struct node *temp;
    temp = q;
    int square_no;
    if (temp == NULL)
    {
        printf("Board is empty\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < *(a + i); j++)
            {
                if (*(a + i) % 2 == 0)
                {
                    if (temp->next == NULL)
                    {
                        while (temp->prev != NULL)
                        {
                            temp = temp->prev;
                        }
                        continue;
                    }
                    temp = temp->next;
                }
                else
                {
                    if (temp->prev == NULL)
                    {
                        while (temp->next != NULL)
                        {
                            temp = temp->next;
                        }
                        continue;
                    }
                    temp = temp->prev;
                }
            }
        }
        square_no = temp->data;
        printf("Player has landed in square %d\n", square_no);
    }
}
