#include"stdio.h"
#define PI 3.1415926
void main()

{
    float r,h;
	printf("请输入圆的半径和圆柱的高:")	;
	scanf("%f%f",&r,&h);
	printf("圆球的表面积是：%.2f\n",4*PI*r*r);
	printf("圆球的体积是：%.2f\n",(4/3)*PI*r*r*r);
	printf("圆柱的体积是:%.2f\n",PI*r*r*h);
	
} 
