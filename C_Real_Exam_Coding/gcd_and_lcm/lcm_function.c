#include<stdio.h>
int gcd(int a,int b)
{   if((a||b))
    {
        if(a==0)return b;
        if(b==0)return a;
        while(a!=0)
        {
            int temp=b%a;
            b=a;
            a=temp;        
        }
        return b;
    }
    printf("gcd的x形参不能都是0");
}
int lcm(int a,int b)
{   
    if(gcd(a,b))
    {
    int result=(b*a)/gcd(a,b);
    return result;
    }
    printf("gcd的结果不能是0");
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",gcd(a,b));
    printf("%d",lcm(a,b));
    return 0;
}
