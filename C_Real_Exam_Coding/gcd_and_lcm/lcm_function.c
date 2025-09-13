#include<stdio.h>
int gcd(int a,int b)
{
    if(a==0&&b==0)return 0;
    /*没有理解欧几里得算法的逻辑，
    写了冗余的判定，以下省略部分已经被while包括在内
    if(a=0)return b;
    if(b=0)return a;
    */
    while(b!=0)
    {
        int temp=0;
        temp=b;
        b=a%b;//因为while判断写的是b!=0,所以需要把a%b赋值给b
        a=temp;
    }
    return a;
}
int lcm(int a,int b)
{
    
    if(gcd(a,b))
    {     
        return (a/gcd(a,b))*b;
    }
}
int main()
{
    int a=0,b=0;
    printf("请你输入要计算的两个数:\n");
    scanf("%d %d",&a,&b);
    printf("最大公约数：%d\n",gcd(a,b));
    printf("最小公倍数：%d",lcm(a,b));
    return 0;
}