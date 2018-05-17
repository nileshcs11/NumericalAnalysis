//A program to implement stack using array
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define SIZE 5

int A[SIZE], TOP = -1;

void push();
void pop();
void showstack();

int main()
{
	int ch;
	clrscr();

	while(1)
	{
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: showstack();
				break;
			case 4: exit(0);
			default: printf("\nWrong choice given\n");
		}
	}
}

void push()
{
	int item;

	if(TOP == SIZE -1)
		printf("\nStack overflow !! Can't push an item ");
	else
	{
		printf("\nEnter an item to push ");
		scanf("%d", &item);

		TOP = TOP + 1;
		A[TOP] = item;
	}
}

void pop()
{
	if(TOP == -1)
		printf("\nStack underflow !! Can't delete an item");
	else
		printf("\nPopped item is %d ", A[TOP--]);
}

void showstack()
{
	int i;

	if(TOP == -1)
		printf("\nStack underflow !! No item to display ");
	else
	{
		printf("\nStack elements are \n");
		for(i = TOP; i>=0; i--)
			printf("%d\n", A[i]);
	}
}










































