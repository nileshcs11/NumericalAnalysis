//Implementation of Circular Queue

#include<stdio.h>
#include<conio.h>

#define SIZE 5

int A[SIZE], FRONT = -1, REAR = -1;

void insert();
void del();
void showqueue();

int main()
{
	int ch;

	clrscr();

	while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		printf("Enter your choice ");
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
			default: printf("\nWrong Choice given ");
		}
	}
}

void  insert()
{
	int item;

	if(FRONT == (REAR + 1) % SIZE)
		printf("\nQueue Overflow !! Item can't be inserted ");
	else
	{
		printf("\nEnter the item to insert ");
		scanf("%d", &item);

		REAR = (REAR + 1) % SIZE;
		A[REAR] = item;

		if(FRONT == -1)
			FRONT += 1;
	}
}

void del()
{
	if(FRONT == -1)
		printf("\nQueue underflow !! No item to delete ");
	else
	{
		printf("\nDeleted item is %d ", A[FRONT]);
		if(FRONT == REAR)
			FRONT = REAR = -1; 
		else
			FRONT = (FRONT + 1) % SIZE;
	}
}

void showqueue()
{
	int i;
	if(FRONT == -1)
		printf("\nQueue Underflow !! No item to display ");
	else
	{
		printf("\nThe elements of the queue are ");
		if(FRONT <= REAR)
			for(i = FRONT; i <= REAR; i++)
				printf("%d ", A[i]);
		else
		{
			for(i = FRONT; i < SIZE; i++)
				printf("%d ", A[i]);
			for(i = 0; i <= REAR; i++)
				printf("%d ", A[i]);
		}
	}
}
