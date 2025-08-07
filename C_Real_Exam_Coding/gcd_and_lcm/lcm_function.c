#include<stdio.h>
int gcd(int a,int b)
{//a=2 b=5 b%a=1
 //a=1 b=2 b%a=0
 //a=0 b=1
    while(a!=0)
    {
        int temp=b%a;
        b=a;
        a=temp;        
    }
    return b;
}
int lcm(int a,int b)
{
    int result=(b*a)/gcd(a,b);
    return result;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",lcm(a,b));
    return 0;
}
//还是要自己手写变量变化规律来找代码漏洞!!!!