#include"stdio.h"
int f1(int x,int y);
int f2(int x,int y);
int main()
{ 
int length,wide,pmt1,pmt2;
printf("请输入矩形的长和宽：");
scanf("%d%d",&length,&wide);
pmt1=f1(length,wide);
pmt2=f2(length,wide);
printf("矩形的周长是: %d\n",pmt1);
printf("矩形的面积是: %d\n",pmt2);
return 0;  
}
int f1(int x,int y)
{
	int z;
	z=2*x+2*y;
	return z;
}
int f2(int x,int y)
{
	int z;
	z=x*y ;
	return z;
	
}
