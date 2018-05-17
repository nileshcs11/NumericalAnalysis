//Priority queue
//===========

#define NULL 0

struct process
{
	char name[5];
	int priority;
	struct process * link;
} * FRONT = NULL;

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
		printf("\nEnter your choice:  ");
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

void insert()
{
	struct process * temp, *p;
	char n[5];
	int pr;

	temp = (struct process *)malloc(sizeof(struct process));
	if(temp == NULL)
	{
		printf("\nMemory is not available to insert");
	}
	else
	{
		printf("\nEnter the process name and priority ");
		scanf("%s%d", &n, &pr);

		strcpy(temp->name, n);
		temp -> priority = pr;

		if (FRONT == NULL || pr < FRONT -> priority)
		{
			temp -> link = FRONT;
			FRONT = temp;
		}
		else
		{
			p = FRONT;
		while( p -> link != NULL && (p -> link) -> priority <= pr )
			{
				p = p -> link;
			}
			temp -> link = p -> link;
			p -> link = temp;
		}
	}
}

void del()
{
	struct process * temp;

	temp = FRONT;

	if (FRONT == NULL)
		printf("\nQueue underflow !! No item to delete ");
	else
	{
		printf("\nDeleted process is %s ", FRONT -> name);
		FRONT = FRONT -> link;
		free(temp);
	}
}

void showqueue()
{
	struct process * temp;

	temp = FRONT;

	if(FRONT == NULL)
		printf("\nQueue underflow !! No item to display ");
	else
	{
		printf("\nProcess Priority\n");
		while(temp != NULL)
		{
			printf("%6s %6d\n", temp -> name, temp -> priority);
			temp = temp -> link; 
		}
	}
}






		








	




	





		
		












	
		