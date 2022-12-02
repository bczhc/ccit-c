#include"stdio.h"
void convert(int n)
{
    if((n/10)!=0)
        convert(n/10);
    printf("%d",n);
}
int main()
{
    int num;
    printf("请输入一个正数：");
    scanf("%d",&num);
    printf("各位上的数字分别是：");
    convert(num);
    return 0;

}
