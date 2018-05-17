//Creation and traversal of a Singly Linked List 

#include<stdio.h>
#include<conio.h>

struct SLL 
{
	int data; 
	struct SLL * link; 
}; 

typedef struct SLL Node; 
Node * HEAD; 

createlist() 
{
	char ch; 
	Node * temp; 

	HEAD = (Node *)malloc(sizeof(Node)); 
	if (HEAD == NULL)
		printf("\nMemory is not available to create a node "); 
	else
	{
		temp = HEAD; 
		printf("\nEnter the data of the node "); 
		scanf("%d", &temp->data); 
		temp->link = NULL; 
	
		printf("\nDo you want to continue? (Y/N) "); 
		fflush(stdin);
		ch = getchar(); 
		while(ch == 'y' || ch == 'Y')
		{
			temp -> link= (Node *)malloc(sizeof(Node));	
			if(temp -> link == NULL)			
				
			else
			{
				temp = temp -> link; 
			printf("\nEnter the value of new node"); 
				scanf("%d", &temp -> data); 
				temp -> link = NULL; 
				printf("Do you want to continue"); 	
				fflush(stdin);
				ch = getchar();	
			}
		}
	}
}
		
showlist()
{

}

int main()
{
	createlist(); 
	
	getch();
	return 0; 
}