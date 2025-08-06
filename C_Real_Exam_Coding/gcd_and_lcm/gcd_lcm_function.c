#include<stdio.h>
int gcd(int a,int b)
{   
    if(b==0)
    {
        printf("a:%d就是最大公约数\n",a);
        return a;
    }
    else
    {   
        printf("调用gcd(%d, %d)\n",b%a,a);
        return gcd(b%a,a);
    }
}
int main()
{   
    int a=0,b=0;
    scanf("%d%d",&a,&b);
    printf("%d",gcd(a,b));
    return 0;
}
/*关键错误反思；
!原本错误代码：return gcd(b, b % a);  // 错误：下一次递归把较大的数又放前面了
我以为保持b在前面就行，实际上要把当前的余数（b % a）放在前面，原本较小的a放在后面
，才能实现“不断缩小问题规模”的目标
!我原代码：if (b % a == 0)终止条件写法有隐患
！建议以后调试时打印这些：printf("调用gcd(%d, %d)\n", a, b);
*/
