//This is a program that finds a root of the equation x^3 - 4x - 9 = 0
//where the initial interval for the root is given by the user and verified
//for convergence in the program		[CU 2013]

#include<stdio.h>
#include<math.h>
#include<conio.h>

float f(float x)
{
	return(x * x * x - 4 * x - 9);
}

int main()
{
	int itr = 0, maxitr;
	float a, b, allerr, x0, x1;

	clrscr();

	printf("\nEnter the initial interval of the root ");
	scanf("%f%f", &a, &b);

	printf("\nEnter the allowabale error limit and maximum no of iterations");
	scanf("%f%d", &allerr, &maxitr);

	if(f(a) * f(b) >= 0)
	{
		printf("\nInvalid initial interval given ");
		getch();
		return 0;
	}

	printf("n         an         bn        f(an)       f(bn)        xn+1     f(xn+1)");
	do
	{
		x0 = (a + b) / 2;

		printf("\n%3d %10.6f %10.6f %10.6f %10.6f %10.6f %10.6f",
		itr++, a, b, f(a), f(b), x0, f(x0));

		if(f(a) * f(x0) < 0)
		{
			b = x0;
		}
		else
		{
			a = x0;
		}
		x1 = (a + b) / 2;
		if (fabs(x1 - x0) < allerr)
		{
			printf("\nRoot = %12.6f", x1);
			getch();
			return 0;
		}
		x0 = x1;
	}while(itr < maxitr);

	printf("\nThe solution does not converge or iterations are insufficient");

	getch();
	return 0;
}




























