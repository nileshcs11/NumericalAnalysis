//A program that adds two polynomial represented using array
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define SIZE 100

int main()
{
	int A[SIZE], B[SIZE], C[SIZE], m, n, i;

	clrscr();

	printf("\nEnter the degree of the 1st polynomial ");
	scanf("%d", &m);

	if(m > SIZE - 1)
	{
		printf("\nDegree of polyniomial exceeds the size of array");
		getch();
		return 0;
	}

	for(i=0; i<=m;i++)
	{
		printf("\nEnter the coefficient of x^%d :", i);
		scanf("%d", &A[i]);
	}
	if(A[m] == 0)
	{
		printf("\nInvalid polynomial given ");
		getch();
		return 0;
	}

	printf("\nThe 1st polynomial given is \n");
	for(i=0; i<m;i++)
	{
		printf(" %d.x^%d +", A[i], i);
	}
	printf(" %d.x^%d", A[i], i);


	printf("\nEnter the degree of the 2nd polynomial ");
	scanf("%d", &n);

	if(n > SIZE - 1)
	{
		printf("\nDegree of polyniomial exceeds the size of array");
		getch();
		return 0;
	}

	for(i=0; i<=n;i++)
	{
		printf("\nEnter the coefficient of x^%d :", i);
		scanf("%d", &B[i]);
	}
	if(B[n] == 0)
	{
		printf("\nInvalid polynomial given ");
		getch();
		return 0;
	}

	printf("\nThe 1st polynomial given is \n");
	for(i=0; i<n;i++)
	{
		printf(" %d.x^%d +", B[i], i);
	}
	printf(" %d.x^%d", B[i], i);

	//Addition of the polynomials
	if(m == n)
	{
		for(i = 0; i <=m; i++)
			C[i] = A[i] + B[i];
	}
	else if(m > n)
	{
		for(i=0; i<=n;i++)
			C[i] = A[i] + B[i];
		for(i=n+1; i<=m; i++)
			C[i] = A[i];
	}
	else
	{
		for(i=0; i<=m;i++)
			C[i] = A[i] + B[i];
		for(i=m+1; i<=n; i++)
			C[i] = B[i];
	}
	printf("\nThe result of addition is \n");
	if(m>=n)
	{
		for(i=0; i<m; i++)
		{
			printf("%d.x^%d+ ", C[i], i);
		}
		printf("%d.x^%d", C[i], i);
	}
	else
	{
		for(i=0; i<n;i++)
		{
			printf("%d.x^%d + ", C[i], i);
		}
		printf("%d.x^%d ", C[i], i);
	}

	getch();
	return 0;
}








