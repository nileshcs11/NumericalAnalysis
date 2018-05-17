//A Program to implement stack using array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

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
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("Enter your choice ");
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
			default: printf("\nWrong choice given ");
		}
	}
}
void push()
{
	int item;

	if(TOP == SIZE - 1)
		printf("\Stack overflow !! Can't push an item");
	else
	{
		printf("\nEnter the item to push ");
		scanf("%d", &item );
		A[++TOP] = item;
	}
}
void pop()
{
	if(TOP == -1)
		printf("\nStack underflow !! Can't pop an item ");
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
		printf("\nThe items in the stack are \n");
		for(i = TOP; i >= 0; i--)
			printf("%d \n", A[i]);
	}
}















