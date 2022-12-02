#include"stdio.h"
void t();
void main()
{
	t();
}
void t()
{
	int i,j,s;
	for(i=0;i<=7/2+1;i++)
	{
		for(s=1;s<=4-i;s++)
			printf(" ");
		for(j=1;j<=2*i-1;j++)
			printf("*");
			printf("\n");
	}
	for(i=7/2+2;i<=7;i++)
	{	
		for(s=1;s<=i-4;s++)
			printf(" ");
		for(j=1;j<=2*(7+1-i)-1;j++)
			printf("*");
			printf("\n");
	}
}
