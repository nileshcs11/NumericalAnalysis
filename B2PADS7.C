//Implementation of Stack using Linked list 
#include<stdio.h>
#include<conio.h>
#define SIZE 5

int count = 0 ;
struct stack
{
	int data;
	struct stack * link;
};

struct stack * TOP = NULL, * HEAD = NULL; 

void push()
{
	struct stack * temp; 

	if (count == SIZE)
		printf("\nThe stack is full, push not possible ");
	else
	{
		temp = (struct stack *)malloc(sizeof(struct stack)); 
		if (temp == NULL)
			printf("\nMemory is not available "); 
		else
		{
			printf("\nEnter the element to push "); 
			scanf("%d", &temp -> data); 
			temp -> link = NULL;

			if (TOP == NULL)
				TOP = HEAD = temp; 
			else
			{

				TOP -> link = temp ;
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
		printf("\nStack Underflow, No item to pop ");
	else
	{
		printf("\nPopped item is %d ", TOP -> data);
		if (HEAD -> link == NULL)
		{
			free(TOP);
			HEAD = TOP = NULL;
		}
		else
		{
			temp = HEAD;
			while(temp -> link != TOP)	
				temp = temp -> link; 
			temp -> link = NULL;
			free(TOP); 
			TOP = temp; 
		}
		count = count - 1;
	}
}

void showstack()
{
	struct stack * temp; 
	if (TOP == NULL)	
		printf("\nStack is empty, No item to display "); 
	else
	{
		printf("\nThe stack elements are \n"); 
		temp = HEAD; 
		while(temp != NULL)
		{
			printf("\n%d", temp -> data); 
			temp = temp -> link; 
		}
		printf(" <-- TOP"); 
	}
}

int main()
{
	int ch; 

	while(1)	
	{
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit ");
		printf("\nEnter your choice "); 
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: 	push(); 
				break;
			case 2: 	pop(); 
				break;
			case 3: 	showstack(); 
				break;
			case 4: 	return 0;
			default: 	printf("\nWrong choice "); 
		}
	}
}











