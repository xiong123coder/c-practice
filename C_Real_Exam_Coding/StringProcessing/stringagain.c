#include<stdio.h>
int main()
{
    char s[201];
    int digits=0,letters=0,others=0;
    int len=0;
    if(fgets(s,201,stdin)==NULL)
    {
        return 0;
    }
    while(s[len]!='\0'&&s[len]!='\n')
    {
        if((s[len]>='a'&&s[len]<='z')||(s[len]>='A'&&s[len]<='Z'))
        {   
            letters++;
            if(s[len]>='a'&&s[len]<='z')
            {
                s[len] -= 32;
            }
        }else if(s[len]>='0'&&s[len]<='9')
        {
            digits++;
        }else
        {
            others++;
        }
        len++;
    }
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        int temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    printf("字符串中有%d个数字,%d个字母,%d个其他字符",digits,letters,others);
    printf("%s",s);
}
/*
在练习：
1：fgets在读取失败时会返回NULL
或者交互输入时，用户手动输入ctrl+D就会触发EOF，fgets也会返回NULL

用以下判断，程序就能在没有输入时提前安全退出，而不会继续处理垃圾数据
if(fgets(s,201,stdin)==NULL)
    {
        return 0;
    }

2:我的错误：错在只要一处成立就可以继续循环
while(s[len]!='\0'||s[len]!='\n')
实际上：必须两者都成立才能继续循环
正确：
while(s[len]!='\0'&&s[len]!='\n')

3:ascii码中：大写字母对应的数字比小写字母小
所以小写转大写：小写减32、
正确：
s[len] -= 32;

4:忘记在反转之前把字符串中的换行符去掉换成字符串结束标志了
这样导致后续反转时 会将换行符一起处理
假如输入“abc”，如果\n不去掉换成“\0”,字符串反转后
会变成“\n c b a”
而且后面再统计时，\n会被计入
*/