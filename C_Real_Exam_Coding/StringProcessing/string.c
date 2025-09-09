#include<stdio.h>
int main()
{
    char s[201];
    int letters=0,digits=0,others=0;
    int len=0;
    if(fgets(s,201,stdin)==NULL)
    {
        return 0;
    }
    while(s[len]!='0'&&s[len]!='\n')//避免换行符被当字符串内容处理
    {
        char c=s[len];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        {
            letters++;
            if (c >= 'a' && c <= 'z') {
                s[len] = c - 32; // 小写转大写
            }
        }else if (c >= '0' && c <= '9') {
            digits++;
        } else {
            others++;
        }
        len++;
    }  
    s[len]='\0';
    for(int i=0,j=len-1;i<j;i++,j--){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    printf("Letters=%d Digits=%d Others=%d\n", letters, digits, others);
    printf("%s\n", s);
    
    return 0;
}
/*  
模拟题（严格贴合考向）
题目：字符串统计与处理
（数组/字符串方向，设计难度与 2023/2024 大题相当）
题目描述：
编写一个程序，读入一个长度不超过 200 的字符串，完成以下功能：
统计其中 字母（a–z，A–Z）、数字（0–9）、其他字符的个数；
将字符串中所有小写字母转换为大写字母；
将处理后的字符串 原地反转；
最终输出：
第 1 行：字母个数、数字个数、其他字符个数；
第 2 行：转换并反转后的字符串。

对于对字符串的编程处理题
Hello World!；用 scanf("%s", s) 只能得到 "Hello"
fgets；能读整行：包括空格。比如 "Hello World!" 会完整读入。
题干写“输入一个字符串”，一般出题人默认没有空格 → scanf("%s", s) 就够。
题干写“输入一行字符串”，要考虑空格 → 建议用 fgets。

C语言里的字符串必须以 '\0' 结尾

严谨用法：while (s[len] != '\0' && s[len] != '\n')
不能只靠 \n，因为有时根本没有换行符。
必须靠 \0，因为它是 C 语言规定的字符串终止符。
两者结合，才既安全又符合需求
*/ 