#include<stdio.h>
#include<conio.h>
#define SIZE 5

int A[SIZE], FRONT = -1, REAR = -1;

void insert_REAR();
void insert_FRONT();
void del_FRONT();
void del_REAR();
void showqueue();

int main()
{
	int ch1, ch2;

	clrscr();

MENU:	while(1)
	{
		printf("1. Input restricted\n2. Output restricted\n3. Exit ");
		printf("\nEnter your choice: ");
		scanf("%d", &ch1);
		switch(ch1)
		{
			case 1:	while(1)
				{
					printf("\n1. Insert_REAR\n");
					printf("2. Delete_FRONT\n");
					printf("3. Delete_REAR\n");
					printf("4. Display\n");
					printf("5. Main Menu\n");
					printf("\nEnter your choice ");
					scanf("%d", &ch2);
					switch(ch2)
					{
						case 1: insert_REAR();
							break;
						case 2: del_FRONT();
							break;
						case 3: del_REAR();
							break;
						case 4: showqueue();
							break;
						case 5: goto MENU;
					}
				}

			case 2: while(1)
				{
					printf("\n1. Insert_REAR\n");
					printf("2. Insert_FRONT\n");
					printf("3. Delete_FRONT\n");
					printf("4. Display\n");
					printf("5. Main Menu\n");
					printf("\nEnter your choice ");
					scanf("%d", &ch2);

					switch(ch2)
					{
						case 1: insert_REAR();
							break;
						case 2: insert_FRONT();
							break;
						case 3: del_FRONT();
							break;
						case 4: showqueue();
							break;
						case 5: goto MENU;
					}
				}

			case 3: return 0;

			default: printf("\nPlease specify correct choice ");
		}
	}
}

void insert_REAR()
{
	int item;

	if (REAR == SIZE - 1)
		printf("\nQueue overflow ");
	else
	{
		printf("\nEnter the element to insert: ");
		scanf("%d", &item);
				
		A[++REAR] = item; 
		if (FRONT == -1)
			FRONT += 1; 
	}
}

void insert_FRONT()
{
	int item, i;

	if (REAR == SIZE -1)
		printf("\nQueue Overflow ");
	else
	{
		printf("\nEnter the item to insert ");
		scanf("%d", &item );

		//Shifting the elements from REAR to FRONT by one position towards right
		//so that one empty slot is created at the FRONT position of the queue
		for(i = REAR; i >= FRONT; i--)
			A[i+1] = A[i];

		//Inserting the item at FRONT position
		A[FRONT] = item;
		REAR = REAR + 1;
	}
}

void del_FRONT()
{
	if (FRONT == -1)
		printf("\nQueue underflow ");
	else
	{
		printf("\nDeleted item is %d ", A[FRONT++]);

		if (FRONT > REAR)	// Reseting the DeQue when it becomes empty
						// after several deletion
			REAR = FRONT = -1;

	}
}

void del_REAR()
{
	if (REAR == -1)
		printf("\nQueue underflow ")	;
	else
	{
		printf ("\nDeleted item is %d", A[REAR--]);
		if (REAR < FRONT )
			FRONT = REAR = -1;
	}
}

void showqueue()
{
	int i;

	if (FRONT == -1)
		printf("\nQueue underflow");
	else
	{
		printf("\nThe DeQue elements are \n");
		for (i = FRONT; i <= REAR; i++)
			printf("%-5d", A[i]);
	}
}
