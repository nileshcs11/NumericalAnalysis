//This program finds the value of y w.r.t. a given value of x for the
//following differential equation
// dy / dx = xy with y(0) = 2

#include<stdio.h>
#include<conio.h>

float f(float x, float y)
{
	return (x * y);
}

int main()
{
	float x0, xn, y0, h, k1, k2, k;
	int n;

	clrscr();

	printf("\nEnter the initial value of x: ");
	scanf("%f", &x0);

	printf("\nEnter the initial value of y: ");
	scanf("%f", &y0);

	printf("\nEnter the value of x for which y has to be found: ");
	scanf("%f", &xn);

	printf("\nEnter the number of sub-intervals: ");
	scanf("%d", &n);

	h = (xn - x0) / n;

	printf("\n %f \t %f", x0, y0);
	do
	{
		k1 = h * f(x0, y0);
		k2 = h * f(x0 + h, y0 + k1);
		k =  (k1 + k2) * 0.5;
		y0 = y0 + k;
		x0 = x0 + h;
		printf("\n %f \t %f", x0, y0);
	}while(x0 <= xn);

	printf("\nThe value of y(%f) = %f", xn, y0);

	getch();
	return 0;
}



























