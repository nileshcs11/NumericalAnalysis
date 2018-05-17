// Solve cosx - x.e^x = 0 using Newton Raphson
#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x)
{
	return (cos(x) - x * exp(x));
}
float fd(float x)
{
	return (-sin(x) - exp(x) - x * exp(x));
}

int main()
{
	int itr = 0, maxitr;
	float a, b, x, x1, h, allerr;

	clrscr();

	printf("\nEnter the initial interval of the root ");
	scanf("%f%f", &a, &b);
	printf("\nEnter the allowable error and max no of iterations ");
	scanf("%f%d", &allerr, &maxitr);

	printf("n   xn	f(xn)  fd(xn)    hn   xn+1");
	x = a;
	do                        	Gauus-Seidel
					Gauss_Jacobi
	{
		h = -f(x) / fd(x);
		x1 = x + h;

		printf("\n%3d %8.4f %8.4f %8.4f %8.4f %8.4f",
		itr++, x, f(x), fd(x), h, x1 );

		if(fabs(x1 - x) < allerr)
		{
			printf("\nRoot is %8.4f", x1);
			getch();
			return 0;
		}
		x = x1;
	}while(itr < maxitr);
	printf("\nThe sol does not converge or insufficient no of iterations");

	getch();
	return 0;
}







