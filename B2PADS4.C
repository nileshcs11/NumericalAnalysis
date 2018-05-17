//Implementation of Queue Using Array

#include<stdio.h>
#include<conio.h>

#define SIZE 5

int A[SIZE], FRONT = -1 , REAR = -1;

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
			default:printf("\nWrong Choice ");
		}
	}
}

void insert()
{
	int item;
	if(REAR == SIZE - 1)
		printf("\nQueue Overflow !! Item can't be inserted ");
	else
	{
		printf("\nEnter item to insert ")	;
		scanf("%d", &item );

		REAR = REAR + 1;
		A[REAR]	= item;

		if (FRONT == -1)
			FRONT = FRONT + 1;
	}
}
void del()
{
	if(FRONT == -1 )
		printf("\nQueue underflow !! No item to delete");
	else
	{
		printf("\nDeleted item is %d " , A[FRONT]);
		FRONT = FRONT + 1;
		if (FRONT > REAR)
			REAR = FRONT = -1;
	}
}
void showqueue()
{
	int i ;
	if(FRONT == -1)
		printf("\nQueue underflow !! No items to display ");
	else
	{
		printf("\nThe elements of the queue are ");
		for(i = FRONT; i <= REAR; i++)
			printf("%d ", A[i]);
	}
}





