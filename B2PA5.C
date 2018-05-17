//WAP that will solve an equation x^3 - 4x - 9 = 0 using method of Bisection
//for a given initial interval of the root. Also provide proper validation
//checks for the initial approximate of the root [CU 2013]

#include<stdio.h>
#include<math.h>
#include<conio.h>

float f(float x)
{
	return (x * x * x - 4 * x - 9);
}

int main()
{
	int maxitr, itr = 0;
	float a, b, allerr, x, x1;

	printf("\nEnter the intial interval of the root:  ");
	scanf("%f%f", &a, &b);
	if (f(a) * f(b) >= 0 )
	{
		printf("\nThe interval does not contain a root ");
		getch();
		return 0;
	}
	printf("\nEnter the allowabale error (EPSILON) ");
	scanf("%f", &allerr);
	printf("\nEnter the maximum number of iterations ");
	scanf("%d", &maxitr);

	printf("\n n \t an \t bn \t f(an) \t f(bn) \t xn+1 \t f(xn+1)");
	do
	{
		x = (a + b) / 2;
		printf("\n %3d %8.4f %8.4f %8.4f %8.4f %8.4f %8.4f",
			itr++, a, b, f(a), f(b), x, f(x));

		if (f(a) * f(x) < 0)
			b = x;
		else
			a = x;
		x1 = (a + b) / 2;
		if( fabs(x1 - x) < allerr)
		{
			printf("\nRoot = %8.4f", x1);
			getch();
			return 0;// exit(0);
		}
		x = x1;
	}while(itr < maxitr);

	printf("\nInsufficient number of iterations specified ");
	getch();                                       f
	return 0;
}























































