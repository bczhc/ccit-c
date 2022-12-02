#include"stdio.h"
int sz(int x);
void main()
{
	int h,x;
	printf("输入任意个正数：\n");
	scanf("%d",&x);
	h=sz(x);
	printf("正数的和是：%d",h); 
}
int sz(int g)
{
	int s=0;
	while(g>0)
	{
		s=s+g;
		scanf("%d",&g);
	}
	return s;
}
