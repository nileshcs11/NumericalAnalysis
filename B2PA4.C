//This is a program that calculates the value of the integral
//	I = INT (0..1) dx / 1 + x
#include<stdio.h>
#include<conio.h>

float f(float x)
{
	return (1 / (1 + x));
}

int main()
{
	float x0, xn, h, i, sum = 0.0, trap;
	int n;

	clrscr();

	printf("\nEnter the lower and upper limit: ");
	scanf("%f%f", &x0, &xn);

	printf("\nEnter the number of sub-intervals: ");
	scanf("%d", &n);

	h = (xn - x0) / n;
	sum = f(x0) + f(xn);
	printf("\n %f \t %f", x0, f(x0));
	for(i=x0 + h; i<=xn; i+= h)
	{
		printf("\n %f \t %f", i, f(i));
		sum = sum + 2 * f(i);
	}
	printf("\n %f \t %f", xn, f(xn));
	trap = sum * h * 0.5;

	printf("\nThe result of the integral is %f", trap);

	getch();
	return 0;
}








