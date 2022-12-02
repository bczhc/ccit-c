#include "stdio.h"
void main()
{
	float f;
	printf("请输入华氏摄氏度:");
	scanf("%f",&f);
	printf("转换为摄氏度:%.2f\n",5.0*(f-32)/9.0);
	
} 
