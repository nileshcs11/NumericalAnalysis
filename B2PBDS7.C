//Stack using linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5

struct stack
{
	int data;
	struct stack * link;
};
struct stack * HEAD = NULL, * TOP = NULL;
int count = 0;

void push()
{
	struct stack * temp;
	if(count == SIZE)
		printf("\nStack is full, push is not possible ");
	else
	{
		temp = (struct stack *)malloc(sizeof(struct stack));
		if(temp == NULL)
			printf("\nmemory is full, node can not be created");
		else
		{
			printf("\nEnter the item push ");
			scanf("%d", &temp->data);

			temp->link = NULL;

			if(TOP == NULL)
			{
				HEAD = temp;
				TOP = temp;
			}
			else
			{
				TOP->link = temp;
				TOP = TOP -> link;
			}
			count = count + 1;
		}
	}
}

void pop()
{
	struct stack * temp;
	if(TOP == NULL)
		printf("\nStack is empty, Pop failed ");
	else
	{
		printf("\nPopped item is %d", TOP -> data);
		if(HEAD->link == NULL)
		{
			free(HEAD);
			HEAD = TOP = NULL;
		}
		else
		{
			temp = HEAD;
			while(temp -> link != TOP)
			{
				temp = temp -> link;
			}
			free(TOP);
			temp->link = NULL;
			TOP = temp;
		}
		count = count - 1 ;
	}
}

void showstack()
{
	struct stack * temp;

	if(TOP == NULL)
		printf("\nStack underflow, no item to display ");
	else
	{
		printf("\nThe elements of the stack are \n");
		temp = HEAD;
		while(temp != NULL)
		{
			printf("%d \n", temp -> data);
			temp = temp -> link;
		}
		printf("\b <-- TOP");
	}
}


int main()
{
	int ch;

	clrscr();

	while(1)
	{
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
		printf("\nEnter your choice ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: showstack();
				break;
			case 4: return 0;
			default: printf("\nWrong choice given ");
		}
	}
}

















