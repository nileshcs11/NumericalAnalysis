//A program to represent a polynomial using array & evaluation for some x
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<math.h>

#define SIZE 5

int main()
{
	int A[SIZE],i, n;
	float x, sum;

	clrscr();

	printf("\nEnter the degree of the polynomial ");
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
		scanf("%d", &A[i]);
	}
	if(A[n] == 0)
	{
		printf("\nIvalid polynomial is given ");
		getch();
		return 0;
	}

	printf("\nThe given polynomial is \n");
	for(i=0; i<=n;i++)
		printf("%d.x^%d +", A[i], i);
	printf("\b");
	printf(" ");

	printf("\nEnter the value of the indep variable ");
	scanf("%f", &x);

	sum = 0.0;
	for(i = 0; i <= n; i++)
		sum = sum + A[i] * pow(x, i);

	printf(" f(%g) =  %g" , x, sum);

	getch();
	return 0;
}


