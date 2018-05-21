#include<stdio.h>
#include<conio.h>
#define TRUE 1
#define FALSE 0
#define Delta 0.00001

float ffabs(float);

void main()
{
  float A[100][100],B[100],P[100],Pold[100],Sum,Sep,Rowsum;
  int N,R,C,I,J,K,satisfied;
  clrscr();
  printf("Enter Number of Variables: ");
  scanf("%d",&N);
  printf("Enter The Coeficient Matrix:\n");
  for(I=1;I<=N;I++)
  {
     for(J=1;J<=N;J++)
	scanf("%f",&A[I][J]);
  }

  printf("Enter The B Matrix:\n");
  for(I=1;I<=N;I++)
  {
	scanf("%f",&B[I]);
  }

  satisfied=FALSE;
  for(R=1;R<=N;R++)
  {
     Rowsum=0;
     for(C=1;C<=N;C++)
	 Rowsum=Rowsum+ffabs(A[R][C]);

     if(Rowsum >= 2* ffabs(A[R][R]))
     {
	printf("Tha Matrix Is Not Diagonally Dominant");
	getch();
	exit(0);
     }
  }
  for(J=1;J<=N;J++)
  {
      P[J]=0;
      Pold[J]=0;
  }
  printf("\n\nN\t");
  for(J=1;J<=N;J++)
    printf("X[%d]\t\t\t",J);
  K=1;
  do
  {
     for(R=1;R<=N;R++)
     {
	Sum=B[R];
	for(C=1;C<=N;C++)
	{
	   if(C!=R)
	      Sum=Sum-A[R][C]*P[C];
	}
	P[R]=Sum/A[R][R];
     }
     printf("\n%d\t",K);
     for(J=1;J<=N;J++)
       printf("%f\t\t",P[J]);
     K=K+1;
     Sep=0;
     for(J=1;J<=N;J++)
       Sep=Sep+ffabs(P[J]-Pold[J]);
     for(J=1;J<=N;J++)
       Pold[J]=P[J];
     if(Sep<Delta)
	satisfied=TRUE;
   }
   while(satisfied==FALSE);
   printf("\n\nThe Solution Is:\n\n");
   for(J=1;J<=N;J++)
      printf("X[%d]=%f\n",J,P[J]);
   getch();
}
float ffabs(float x)
{
   if(x<0)
     return(-1*x);
   else
     return(x);
}