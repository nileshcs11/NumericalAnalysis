//Priority Queue using Array
//==================
#define SIZE 5

struct process 
{
	char name[5]; 
	int priority; 
}; 

struct process A[SIZE]; 
int FRONT = -1, REAR = -1; 

void insert();
void del(); 
void showqueue();

int main()
{
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
			default: printf("\nWrong choice ");
		}
	}
}

void del() 
{
	if (FRONT == -1)
		printf("\nQueue underflow !! No item delete "); 
	else
	{
		printf("\nDeleted process is %s ", A[FRONT].name ); 
		FRONT = FRONT + 1; 

		if (FRONT > REAR)
			FRONT = REAR = -1;
	}
}


void showqueue()
{
	int i ;

	if (FRONT == -1)
		printf("\nQueue underflow !! No item to display ");
	else
	{
		printf("\nProcess Priority\n");
		for(i = FRONT; i <= REAR; i++)
			printf("%6s %6d\n", A[i].name, A[i].priority);
	}
}

void insert()
{
	char n[5];
	int pr, j, i;

	if (REAR == SIZE - 1)
		printf("\nQueue overflow !! item can not be inserted ");
	else
	{
		printf("\nEnter the name and priority of the process " );
		scanf("%s%d", &n, &pr);

		if(REAR == -1)
		{
			FRONT = FRONT + 1;
			REAR = REAR + 1;
			A[REAR].priority = pr;
			strcpy(A[REAR].name ,n);
		}
		else
		{
			if(pr < A[FRONT].priority)
			{
				i = REAR;
				while(i >= FRONT)
				{
					A[i+1].priority = A[i].priority;
					strcpy(A[i+1].name, A[i].name);
					i = i - 1;
				}
				A[FRONT].priority = pr;
				strcpy(A[FRONT].name, n);
				REAR = REAR + 1;
			}

		}
	}
}
