#include<stdio.h>
#include<conio.h>

#define SIZE 100

int main()
{
	int n, X[SIZE], Y[SIZE], XY[SIZE], Xsq[SIZE], i;
	int sx, sy, sxy, sxsq;
	int a1, b1, c1, a2, b2, c2, denom;
	float A, B;

	clrscr();

	printf("\nFitting of a striaght line \n");
	printf("-----------------------------\n\n");
	printf("Enter the number of observations: ");
	scanf("%d", &n);

	sx = 0;
	sy = 0;
	sxy = 0;
	sxsq = 0;

	for(i=0; i<n; i++)
	{
		printf("\nEnter observation pair %d: ", i+1);
		scanf("%d%d", &X[i], &Y[i]);
		XY[i] = X[i] * Y[i];
		Xsq[i] = X[i] * X[i];
		sx = sx + X[i];
		sy = sy + Y[i];
		sxy = sxy + XY[i];
		sxsq = sxsq + Xsq[i];

	}

	printf("\n X \t Y \t XY \t X^2\n");
	printf("______________________________\n");

	for(i=0; i<n; i++)
	{
		printf("%d \t %d \t %d \t %d\n", X[i], Y[i], XY[i], Xsq[i]);
	}
	printf("______________________________\n");
	printf("%d \t %d \t %d \t %d", sx, sy, sxy, sxsq);

	//Displaying the normal equations
	printf("\nThe straight line to fit is of the form y = ax + b");
	printf("\nThe normal equations for the fitting are \n");
	printf("%d = a. %d + %d. b\n", sy, sx, n); // sy = a. sx + n.b
	printf("%d = a. %d + b. %d", sxy, sxsq, sx); // sxy = a. sxsq + b. sx

	//Solving the normal equations
	a1 = sx ;
	b1 = n ;
	c1 = -sy ;
	a2 = sxsq ;
	b2 = sx ;
	c2 = -sxy;

	denom  = a1 * b2 - a2 * b1;
	if (denom == 0)
		printf("\nThe straight line can't be fitted");
	else
	{
		A = (float) (b1 * c2 - b2 * c1) / denom;
		B = (float) (a2 * c1 - a1 * c2) / denom;
		printf("\nThe striaght line is y = %g.x + %g", A, B);
	}



	getch();
	return 0;
}
















