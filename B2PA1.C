//A program that fits a striaght line based on the values of n observations
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

	printf("\nFitting of a straight line\n\n");

	printf("\nEnter the number of observations: ");
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
	printf("_____________________________ \n");
	for(i=0; i<n; i++)
	{
		printf("%d \t %d \t %d \t %d\n", X[i], Y[i], XY[i], Xsq[i]);
	}
	printf("_____________________________ \n");
	printf("%d \t %d \t %d \t %d", sx, sy, sxy, sxsq);

	//Displaying the normal equations
	printf("\nThe general form of the st line to fit is y = ax + b \n");
	printf("\nThe normal equations to fit the st line are \n");
	printf("%d = a.%d + %d.b \n", sy, sx, n); // sy = a sx + n b
	printf("%d = a.%d + b.%d ", sxy, sxsq, sx);// sxy = a. sxsq + b. sx

	//Solving the normal equations
	a1 = sx;
	b1 = n;
	c1 = -sy;
	a2 = sxsq;
	b2 = sx;
	c2 = -sxy;

	denom = a1*b2 - a2*b1;
	if (denom == 0)
		printf("\nStraight line can't be fit by the given points");
	else
	{
		A = (float)(b1 * c2 - b2 * c1) / denom;
		B = (float)(a2 * c1 - a1 * c2) / denom;

		printf("\nThe straight line is y = %g x + %g", A, B);
	}

	getch();
	return 0 ;
}














