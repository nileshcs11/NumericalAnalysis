#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	int n,i,j,k;
	float a[10][11],b[10],c,d;

	//clrscr();
	printf("\n Solution by Gauss-Elimination\n");

	printf("Give the no of linear equations (less than 10) : ");
	scanf("%d",&n);

	if(n<=0  || n>10)
	{
		printf("\n The no of system of linear eqautions is invalid \n");
		getch();
		exit(0);
	}

	
    for(i=0;i<n;i++)
	{        
         	printf("a%d\t",i+1);
    }
	printf("b\n");
	
	//READING VALUES 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
			scanf("%f",&a[i][j]);
	}

   // apply elimination 
 	for(k=0;k<n-1;k++)
	{
		for(i=k+1;i<n;i++)
		{
			d=a[i][k];
			for(j=0;j<n+1;j++)
				{
					c=(a[k][j]/a[k][k]);
					a[i][j]-=c*d;             
				}
		}
	}
	printf("\n The matrix after applying Gauss-Elimination\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n+1;j++)
			printf("%g\t",a[i][j]);
	}
    //Solution by back track 
	for(i=n-1;i>=0;i--)
	{
		b[i]=a[i][n];
		d=0;
		for(k=1;k<n-i;k++)
			d+=(a[i][n-k]*b[n-k]);
		b[i]=(b[i]-d)/a[i][i];
	}
	printf("\nThe solution is ");
	for(i=0;i<n;i++)
		printf("\n\tx[%d]\t=\t%g",i+1,b[i]);
	getch();
}
