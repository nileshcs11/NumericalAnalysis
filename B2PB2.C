//This is a program to find the value of y wrt dy/dx = xy with y(0) = 2

#include<stdio.h>
#include<conio.h>

float f(float x, float y)
{
	return (x * y);
}

int main()
{
	float x0, y0, y1, xn, h;
	int n;

	clrscr();

	printf("\nEnter the initial value of x: ");
	scanf("%f", &x0);

	printf("\nEnter the initial value of y: ");
	scanf("%f", &y0);

	printf("\nEnter the value of x for which y to be found: ");
	scanf("%f", &xn);

	printf("\nEnter the number of sub-intervals: ");
	scanf("%d", &n);

	h = (xn - x0) / n;
	printf("\n %g \t %g", x0, y0);
	do
	{
		y1 = y0 + h * f(x0,y0);
		x0 = x0 + h;
		printf("\n %g \t %g", x0, y1);
		y0 = y1;
	}while(x0<=xn);

	printf("\nThe value of y(%g) = %g", xn, y0);
	getch();
	return 0;
}


































