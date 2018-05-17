//Implementation of Circular Queue Using Array

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
