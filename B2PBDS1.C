//A program to represent a polynomial using array and evaluate it for some x

#include<stdio.h>
#include<conio.h>
#include<math.h>

#define SIZE 100

int main()
{
	int A[SIZE],n, i;
	float sum, x;

	clrscr();

	printf("\nEnter the degree of the polynomial ");
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
		scanf("%d", &A[i]);
	}
	if(A[n] == 0)
	{
		printf("\nInvalid polynomial given ");
		getch();
		return 0;
	}

	printf("\nThe polynomial given is \n");
	for(i=0; i<n;i++)
	{
		printf(" %d.x^%d +", A[i], i);
	}
	printf(" %d.x^%d", A[i], i);

	printf("\nEnter the value of the independent variable ");
	scanf("%f", &x);

	sum = 0.0;
	for(i=0; i<=n; i++)
	{
		sum = sum + A[i] * pow(x, i);
	}

	printf("\n f(%g) = %g", x, sum);

	getch();
	return 0;
}














