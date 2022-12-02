#include "stdio.h"
int main()
{
    int x;
	scanf("%d",&x);
	if(x<1600)
	x=x;
	else if(x<2400)
	x=x*0.95;
		else if(x<3200)
		x=x*0.9;
		else if(x<6400)
		x=x*0.85;
			else if(x>=6400)
			x=x*0.8;
 printf("%d",x);
	return 0;
}
