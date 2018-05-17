//Stack using linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5

#define START main
#define BEGIN {
#define END }
struct queue
{
	int data;
	struct queue * link;
};
struct queue * FRONT = NULL, * REAR = NULL;
int count = 0;

void insert()
{
	struct queue * temp;

	if(count == SIZE)
		printf("\nQueue is full, insertion is not possible ");
	else
	{
		temp = (struct queue *)malloc(sizeof(struct queue));
		if(temp == NULL)
			printf("\nmemory is full, node can not be created");
		else
		{
			printf("\nEnter the item insert ");
			scanf("%d", &temp->data);

			temp->link = NULL;

			if(REAR == NULL)
			{
				FRONT = temp;
				REAR = temp;
			}
			else
			{
				REAR->link = temp;
				REAR= REAR -> link;
			}
			count = count + 1;
		}
	}
}

void del()
{
	struct queue * temp;

	if(FRONT == NULL)
		printf("\nQueue is empty, Pop failed ");
	else
	{
		printf("\ndeleted item is %d", FRONT -> data);
		temp = FRONT;
		FRONT = FRONT -> link;
		if(FRONT == NULL)
			REAR = NULL;
		free(temp);
		count = count - 1 ;
	}
}

void showqueue()
{
	struct queue * temp;

	if(FRONT == NULL)
		printf("\nQueue underflow, no item to display ");
	else
	{
		printf("\nThe elements of the queue are \n");
		printf("FRONT --> ");
		temp = FRONT;
		while(temp != NULL)
		{
			printf("%d ", temp -> data);
			temp = temp -> link;
		}
		printf("\b <-- REAR");
	}
}


int START()
BEGIN
	int ch;

	clrscr();

	while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
		printf("\nEnter your choice ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: insert();
				break;
			case 2: del();
				break;
			case 3: showqueue();
				break;
			case 4: return 0;
			default: printf("\nWrong choice given ");
		}
	}
END

















