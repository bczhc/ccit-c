#include"stdio.h"
char D(char c);
void main()
{
	int c,d;
	printf("从键盘输入一个字符：");
	scanf("%c",&c);
	d=D(c);
	printf("%c",d);
}
char D(char c)
{
	int t;
	t=c+5;
	return t;
}
