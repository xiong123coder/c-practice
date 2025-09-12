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
        printf("调用gcd(%d, %d)\n",b,a%b);
        return gcd(b,a%b);
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
我的漏洞总结：
1.我先写了 if (b == 0)，以为这样就避免了除零错误，但在递归调用时却用了 b % a
这逻辑其实是先确认 b ≠ 0，却拿 b 去除以 a，
等 a 变成 0 的时候就会触发 b % 0，导致程序崩溃。
正确的逻辑应该是：
如果 b ≠ 0，就用 a % b 来递归，
这样才能确保除法操作的分母永远不为 0。

2.找到关键出错的具体代码，自己拿数据推演
*/
