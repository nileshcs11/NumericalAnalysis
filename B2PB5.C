//This is a program that finds the value of an integral using
// i. Trapezoidal's rule
// ii. Simpson's 1/3rd rule
// I = INT (0..1) dx / (1 + x)

#include<stdio.h>
#include<conio.h>

float f(float x)
{
	return (1 / (1 + x));
}

int main()
{
	float x0, xn, h, sum = 0.0, trap;
	int n;

//	clrscr();

	printf("\nEnter the value lower and upper limit : ");
	scanf("%f%f", &x0, &xn);

	printf("\nEnter the number of sub-intervals: ");
	scanf("%d", &n);

	printf("\n x \t\t f(x)");

	h = (xn - x0) / n;
	sum = f(x0) + f(xn);
	do
	{
		printf("\n%f \t %f", x0, f(x0));
		x0 = x0 + h;
		sum = sum + 2 * f(x0);
	}while (x0 < xn);
	printf("\n%f \t %f", x0, f(x0));

	trap = (h * 0.5) * (sum);

	printf("\nThe integral is %f", trap);

	getch();
	return 0;
}
























