//A program that will add two polynomials of given degrees
#include<stdio.h>
#include<conio.h>


#define SIZE 100

int main()
{
	int A[SIZE], B[SIZE], C[SIZE], m, n, i;
	float x, sum;

	clrscr();

	printf("\nEnter the degree of the 1st polynomial ");
	scanf("%d", &m);

	if(m > SIZE -1)
	{
		printf("\nDegree of polynomial exceeds array size ");
		getch();
		return 0;
	}

	for(i = 0; i <= m; i++)
	{
		printf("\nEnter the coefficient of x^%d: ", i);
		scanf("%d", &A[i]);
	}
	if(A[m] == 0)
	{
		printf("\nIvalid polynomial is given ");
		getch();
		return 0;
	}

	printf("\nThe given polynomial is \n");
	for(i=0; i<=m;i++)
		printf("%d.x^%d +", A[i], i);
	printf("\b");
	printf(" ");


	printf("\nEnter the degree of the 2nd polynomial ");
	scanf("%d", &n);

	if(n > SIZE -1)
	{
		printf("\nDegree of polynomial exceeds array size ");
		getch();
		return 0;
	}

	for(i = 0; i <= n; i++)
	{
		printf("\nEnter the coefficient of x^%d: ", i);
		scanf("%d", &B[i]);
	}
	if(B[n] == 0)
	{
		printf("\nIvalid polynomial is given ");
		getch();
		return 0;
	}

	printf("\nThe given polynomial is \n");
	for(i=0; i<=n;i++)
		printf("%d.x^%d +", B[i], i);
	printf("\b");
	printf(" ");
	//Addition
	if(m == n)
	{
		for(i=0; i<=m; i++)
			C[i] = A[i] + B[i];
	}
	else if(m > n)
	{
		for(i=0; i<=n; i++)
			C[i] = A[i] + B[i];
		for(i=n+1; i<=m; i++)
			C[i] = A[i];
	}
	else
	{
		for(i=0; i<=m; i++)
			C[i] = A[i] + B[i];
		for(i=m+1; i<=n; i++)
			C[i] = B[i];
	}


	if(m >= n)
	{
		printf("\nThe polynomial after addition is \n");
		for(i=0; i<=m; i++)
			printf("%d.x^%d +", C[i], i);
		printf("\b");
		printf(" ");
	}
	else
	{
		printf("\nThe polynomial afdter addition is \n");
		for(i=0; i<=n; i++)
			printf("%d.x^%d + ", C[i], i);
		printf("\b");
		printf(" ");
	}

	getch();
	return 0;
}

