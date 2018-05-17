//This is a program to find the value of y wrt dy/dx = xy with y(0) = 2

#include<stdio.h>
#include<conio.h>

float f(float x, float y)
{
	return (x * y);
}

int main()
{
	float x0, y0, y1, xn, h, k1, k2, k3, k4, k;
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
	printf("\n %.4f \t %.4f", x0, y0);
	do
	{
		k1 = h * f(x0, y0);
		k2 = h * f(x0+h/2, y0+k1/2);
		k3 = h * f(x0+h/2, y0+k2/2);
		k4 = h * f(x0+h, y0+k3);
		k =  (float)((k1 + 2*k2 + 2*k3 + k4) / 6.0);
		y1 = y0 + k;
		x0 = x0 + h;
		printf("\n %.4f \t %.4f", x0, y1);
		y0 = y1;
	}while(x0<=xn);

	printf("\nThe value of y(%.4f) = %.4f", xn, y0);
	getch();
	return 0;
}


































