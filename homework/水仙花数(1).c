#include "stdio.h"
int main()
{
	int i,j,k,n,g;
	printf("水仙花数是:");
	for(n=100,g=0;n<1000;n++)
	{
	i=n/100;
	j=n/10%10;
	k=n%10;
	if(n==i*i*i+j*j*j+k*k*k)
	printf("第%d个%5d\n",++g,n);
    }
    printf("\n");
    return 0;
}

