//WAP to find a root of the equation cosx - xe^x = 0 using Newton-Raphson
//method.

#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
	return (cos(x) - x * exp(x));
}
float fd(float x)
{
	return (-sin(x) - x * exp(x) - exp(x));
}

int main()
{
	int itr = 0, maxitr;
	float a, b, x0, h, x1, allerr;


	printf("\nEnter the initial interval of the root ");
	scanf("%f%f", &a, &b);
	if(f(a) * f(b) >= 0 )
	{
		printf("\nInvalid interval specified ");
		getch();
		return 0;
	}

	printf("\nEnter allowable error and max no of iterations ");
	scanf("%f%d", &allerr, &maxitr);

	printf("\n n    xn    f(xn)     fd(xn)    hn     xn+1");
	x0 = a;
	do
	{
		h = -f(x0) / fd(x0);
		x1 = x0 + h;
		printf("\n %3d %8.4f %8.4f %8.4f %8.4f %8.4f ",
		itr++, x0, f(x0), fd(x0), h, x1 );

		if (fabs(x1 - x0) < allerr)
		{
			printf("\nThe root = %8.4f", x1);
			getch();
			return 0;
		}
		x0 = x1;
	}while(itr < maxitr);

	printf("\nInsufficient number of iterations specified ");
	getch();
	return 0;
}




























