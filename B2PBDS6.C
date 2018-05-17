//This is a program that simulates DEQUE using array 

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

MENU: 	while(1)
	{
		printf("1. Input restricted\n2. Output restricted\n3. Exit ");
		printf("\nEnter your choice: ");
		scanf("%d", &ch1);

		switch(ch1)
		{
			case 1: while(1)
				{
					printf("1. Insert at REAR\n");
					printf("2. Delete from FRONT\n");
					printf("3. Delete from REAR\n");
					printf("4. Display\n");
					printf("5. Main menu\n");
					printf("Enter your choice ");
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
					printf("1. Insert at REAR\n");
					printf("2. Insert at FRONT\n");
					printf("3. Delete from FRONT\n");
					printf("4. Display\n");
					printf("5. Main menu\n");
					printf("Enter your choice ");
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
			default: printf("\nEnter proper choice ");
		}
	}
}
void insert_FRONT()
{
	int item, i; 

	if (REAR == SIZE -1)
		printf("\nThe queue is full ");
	else
	{
		printf("\nEnter the item to insert:  ");
		scanf("%d", &item );
		
		if (FRONT != -1 ) // The queue has at least one element  
		{
		//Shifting the elements of the queue towards right from REAR to FRONT 
			for(i = REAR; i >= FRONT; i--)
				A[i + 1] = A[i];
			A[FRONT] = item; 
			REAR = REAR + 1; 
		}
		else // QUEUE is empty ... First Item will be inserted 
		{
			FRONT = FRONT + 1; 
			A[FRONT] = item; 
			REAR = REAR + 1;
		}
	}
}

void insert_REAR()
{
	int item; 

	if (REAR == SIZE -1)
		printf("\nThe queue is full ");	
	else
	{
		printf("\nEnter the item to insert at REAR: " );
		scanf("%d", &item);

		REAR = REAR + 1; 
		A[REAR]	 = item; 

		if (FRONT == -1)
			FRONT = FRONT + 1;
	}
}

void del_FRONT()
{
	if (FRONT == -1 )
		printf("\nThe queue is empty ");
	else
	{
		printf("\nThe deleted item is %d ", A[FRONT++ ]);
	
		if (FRONT > REAR)
			FRONT = REAR = -1; 
	}	
}

void del_REAR()
{
	if (REAR == -1)
		printf("\nThe queue is empty ");
	else
	{
		printf("\nThe deleted item is %d" , A[REAR]);
		REAR = REAR - 1; 
		if (REAR < FRONT)
			FRONT = REAR = -1;
	}
}

void showqueue()
{
	int i; 

	if (FRONT == -1)
		printf("\nThe queue is empty ");
	else
	{
		printf("\nThe elements are \n");
		for(i = FRONT; i <= REAR; i++) 
			printf("%5d", A[i]);
	}		
}

