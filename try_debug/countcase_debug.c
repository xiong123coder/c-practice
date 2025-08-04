#include<stdio.h>
void countcase(char a[])
{
    int count[26]={0};
    for(int i=0;a[i]!='\0';i++)
    {
        printf("this_character:%c,ASCII:%d\n",a[i],a[i]);
        if(a[i]>='a'&& a[i]<='z')
        {   
            int index=a[i]-'a';
            printf("--> is lowercase letter this_character:%c,index from this c:%d\n",a[i],index);
            count[index]++;
        }
    }
    for(int j=0;j<26;j++)
        if(count[j]>0)
        printf("%c: %d\n",j+'a',count[j]);
}
int main()
{
    char urstring[100];
    fgets(urstring,sizeof(urstring),stdin);
    countcase(urstring);
    return 0;
}
/*
abcda z
this_character:a,ASCII:97
--> is lowercase letter this_character:a,index from this c:0
this_character:b,ASCII:98
--> is lowercase letter this_character:b,index from this c:1
this_character:c,ASCII:99
--> is lowercase letter this_character:c,index from this c:2
this_character:d,ASCII:100
--> is lowercase letter this_character:d,index from this c:3
this_character:a,ASCII:97
--> is lowercase letter this_character:a,index from this c:0
this_character: ,ASCII:32
this_character:z,ASCII:122
--> is lowercase letter this_character:z,index from this c:25
this_character:
,ASCII:10
a: 2
b: 1
c: 1
d: 1
z: 1
// 【复盘总结】：调试时未明确标记是否进入 if 分支，虽然通过后续输出可以推测，
// 但缺乏显式标志容易忽略程序分支执行情况。
// ✅ 改进建议：在 if 内部增加标识语句，如 printf("--> is lowercase letter\n");
// 这样更易排查判断条件是否如预期生效。
*/