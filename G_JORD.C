#include<stdio.h>
#include<conio.h>
void main()
{
	float a[20][20],d,s,x[20];
	int i,j,k,n;
	clrscr();
	printf("Enter the value of n : ");
	scanf("%d",&n);
	printf("Enetr the element of the matrix :");
	printf("\n");

	for(i=1;i<=n;i++)
		printf(" a%d\t",i);
	printf("b\n");

	for(i=1;i<n+1;i++)
	{
		for(j=1;j<=n+1;j++)
			scanf("%f",&a[i][j]);
	}

	for(k=1;k<=n+1;k++)
	{
		d=a[k][k];
		for(j=1;j<=n+1;j++)
			a[k][j]=a[k][j]/d;
		for(i=1;i<=n;i++)
		{
			if(i!=k)
			{
				d=a[i][k];
				for(j=1;j<=n+1;j++)
					a[i][j]=a[i][j]-(d*a[k][j]);
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n+1;j++){
			printf("%f\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<=n;i++)
		printf("x[%d] = %f \n",i,a[i][n+1]);
	getch();
}



