#include"stdio.h"
/*int gcd(int m, int n)
{
if(n==0) return m;
else return gcd(n,m%n);
}*/
void main()
{
    int a,b,t,g;
    scanf("%d%d",&a,&b);
    printf("%d,%d最大公约数为",a,b);
    if(a{
        t=a;
        a=b;
        b=t;

    }
    g=gcd(a,b);
    printf("%d",g);
}
int gcd(int m,int n)
{
    if(n==0) return m;
    else return gcd(n,m%n);
}
