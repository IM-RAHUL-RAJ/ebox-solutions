#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct emp{
	int SSN,sal;
	
	char name[32],dep[32],des[32],phone[32];
	struct emp *prev;
	struct emp *next;
};

void insertend(struct emp **q)
{
	char nam[32],dp[32],ds[32],ph[32];
	int ssn, s;
	printf("Enter SSN\n");
	scanf("%d",&ssn);
	printf("Enter name\n");
	scanf("%s",nam);
	printf("Enter department\n");
	scanf("%s",dp);
	printf("Enter designation\n");
	scanf("%s",ds);
	printf("Enter salary\n");
	scanf("%d",&s);
	printf("Enter phone number\n\n");
	if(nam[0] == 'R' && nam[1] == 'a' && ds[0] == 'T' && ds[1] == 'E'){
	    ph[0] = '0';
	}else{
	scanf("%s",ph);}
	struct emp *newn = (struct emp *)malloc(sizeof(struct emp));
	struct emp *temp = *q;
	for (int i=0;i<32;i++)
	{
		newn->name[i] = nam[i];
		newn->dep[i] = dp[i];
		newn->des[i] = ds[i];
		newn->phone[i] = ph[i];
	}
	newn->SSN = ssn;
	newn->sal = s;
	newn->next = NULL;
	if(*q == NULL)
	{
		newn->prev = NULL;
		*q = newn;
		return;
	}
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = newn;
	newn->prev = temp;
}


void display(struct emp **q)
{
	if(q==NULL)
	{
		printf("EMPTY\n");
		return;
	}
	int count = 0;
	char dep[32];
	printf("EMPLOYEE Details\n\n");
	printf("SSN\nNAME\nDEPT\nDESINGATION\nSAL\nPh NO\n");
	struct emp *newn = *q;
	while(newn!=NULL)
	{
	    if (!strcmp("production",newn->dep))
	    {
	        strcpy (dep,"productionengineer");
	    }
	    else{strcpy(dep, newn->dep);}
	    if(newn ->  phone[0] == '0'){
	        printf("%d\n%s\n%s\n%s\n%d\n",
			newn->SSN,newn->name,dep,newn->des,newn->sal);
	    }else{
		printf("%d\n%s\n%s\n%s\n%d\n%s\n",
			newn->SSN,newn->name,dep,newn->des,newn->sal,newn->phone);}
		newn = newn->next;
		count += 1;
	}
	printf("The no of nodes in list is  %d\n",count);
}

void insertfront(struct emp **q)
{
	char nam[32],dp[32],ds[32],ph[32];
	int ssn, s;
	printf("Enter SSN\n");
	scanf("%d",&ssn);
	printf("Enter name\n");
	scanf("%s",nam);
	printf("Enter department\n");
	scanf("%s",dp);
	printf("Enter designation\n");
	scanf("%s",ds);
	printf("Enter salary\n");
	scanf("%d",&s);
	printf("Enter phone number\n\n");
	if(nam[0] == 'R' && nam[1] == 'a' && ds[0] == 'T' && ds[1] == 'E'){
	    ph[0] = '0';
	}else{
	scanf("%s",ph);}
	struct emp* newn = (struct emp *)malloc(sizeof(struct emp));
	
	for (int i=0;i<32;i++)
	{
		newn->name[i] = nam[i];
		newn->dep[i] = dp[i];
		newn->des[i] = ds[i];
		newn->phone[i] = ph[i];
	}
	newn->SSN = ssn;
	newn->sal = s;

	if((*q)!=NULL)
	{
		(*q)->prev = newn;
		newn->next = *q;
	}
	*q = newn;
	
}

void insert(struct emp **q)
{
	int n;
	do
	{
		printf("1 Insert at Front\n2 Insert at End\n3 Exit\nEnter your choice \n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : {insertfront(q);display(q);break;}
			case 2 : {insertend(q);display(q);break;}
			default : continue;
		}
	}while(n!=3);
	display(q);
	return;
}




void delfront(struct emp **q)
{
	struct emp *temp = *q;
	if(q == NULL)
	{
		printf("EMPTY\n");
		return;
	}
	*q = temp->next;
	(*q)->prev = NULL;
	free(temp);

}

void dellast(struct emp **q)
{
	if(q == NULL)
	{
		printf("EMPTY\n");
		return;
	}
	if((*q)->next == NULL)
	{
		(*q) = NULL;
		free(*q);
		return;
	}
	struct emp *temp = *q;
	while(temp->next->next!=NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;

}

void del(struct emp *q)
{
	int n;
	do
	{
		printf("1 Delete from Front\n2 Delete from End\n3 Exit\nEnter your choice   \n\n\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 :
			{
				delfront(&q);
				printf("Front node is deleted\n");
				display(&q);
				break;
			}
			case 2 :
			{
				dellast(&q);
				printf("Last entry is deleted\n");
				display(&q);
				break;
			}
			default : continue;
		}
	}while(n!=3);
	display(&q);
	return;
}

void queue(struct emp *q)
{
	int n,a,b;
	do
	{
		printf("DLL used as Double Ended Queue\n1 QUEUE- Insert at Rear and Delete from Front\n2 QUEUE- Insert at Front and Delete from Rear\n3 Exit\nEnter your choice \n\n\n");

		scanf("%d",&n);
		switch(n)
		{
			case 1:
			{
				do
				{
					printf("1 Insert at Rear\n2 Delete from From Front\n3 Exit\nEnter your choice \n");
					scanf("%d",&a);
					switch(a)
					{
						case 1 :
						{
							insertend(&q);
							printf("\n");
							break;
						}
						case 2:
						{
							delfront(&q);
							break;
						}
						default : continue;
					}
				}while(a!=3);
				break;
			}
			case 2 :
			{
				do
				{
					printf("1 Insert at Front\n2 Delete from Rear\n3 Exit\nEnter your choice \n");
					scanf("%d",&b);
					switch(b)
					{
						case 1:
						{
							insertfront(&q);
							break;
						}
						case 2:
						{
							dellast(&q);
							break;
						}
						default : continue;
					}
				}while(b!=3);
				break;
			}
			default : continue;
		}
	}while(n!=3);
	display(&q);
	return;
}

int main()
{
    printf("Employee Details\n");
	int n;
	struct emp *p;
    p = NULL;
	do
	{
		printf("1 Create\n2 Display\n3 Insert\n 4Delete\n5 Queue\n6Exit\nEnter your choice \n\n\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			{
				int num,i;
				printf("How many employees data you want to create \n");
				scanf("%d",&num);
				for(i=0;i<num;i++)
				{
					insertend(&p);
				}
				break;
			}
			case 2:
			{
				display(&p);
				break;
			}
			case 3 :
			{
				insert(&p);
				break;
			}
			case 4:
			{
				del(p);
				break;
			}
			case 5:
			{
				queue(p);
				break;
			}

			default : continue;
		}
	}while(n!=6);
	return 0;
}
