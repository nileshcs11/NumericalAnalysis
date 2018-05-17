//Implementation of Stack using Linked list
#include<stdio.h>
#include<conio.h>
#define SIZE 5

int count = 0 ;
struct queue
{
	int data;
	struct queue * link;
};

struct queue * REAR = NULL, * FRONT = NULL;

void insert()
{
	struct queue * temp;

	if (count == SIZE)
		printf("\nThe queue is full, insertion not possible ");
	else
	{
		temp = (struct queue *)malloc(sizeof(struct queue));
		if (temp == NULL)
			printf("\nMemory is not available ");
		else
		{
			printf("\nEnter the element to insert ");
			scanf("%d", &temp -> data);
			temp -> link = NULL;

			if (REAR == NULL)
				FRONT = REAR = temp;
			else
			{

				REAR -> link = temp ;
				REAR = REAR -> link;
			}
			count = count + 1;
		}
	}
}

void del()
{
	struct queue * temp;

	if(FRONT == NULL)
		printf("\nQueue Underflow, No item to delete ");
	else
	{
		printf("\nDeleted item is %d ", FRONT -> data);
		temp = FRONT;
		FRONT = FRONT -> link;
		free(temp);
		if(FRONT == NULL)
			REAR = NULL;
		count = count - 1;
	}
}

void showqueue()
{
	struct queue * temp;

	if (FRONT == NULL)
		printf("\nQueue is empty, No item to display ");
	else
	{
		printf("\nThe queue elements are \n");

		temp = FRONT;
		printf("\nFRONT --> ");
		while(temp != NULL)
		{
			printf("%d ", temp -> data);
			temp = temp -> link;
		}
		printf(" <--REAR");
	}
}

int main()
{
	int ch;

	clrscr();

	while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit ");
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
			default: printf("\nWrong choice ");
		}
	}
}











