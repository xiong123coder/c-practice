#include<stdio.h>
int str_len(char s[])//计算字符串长度
{   
    int n=0;
    while(s[n]!='\0')n++;
    return n;
}
char per_letter_upper(char c)//字符小转大
{
    if (c >= 'a' && c <= 'z') return (c - 32);
    return c;   
}
void allupperchar(char s[])//整串字符串小转大
{   
    int len=0;
    while(s[len]!='\0')
    {
        if(s[len] >= 'a' && s[len] <= 'z')
            s[len]-=32;    
        len++;
    }
}
void nomal_spaces(char s[])
{
    int r = 0;//：读头，从左到右扫描源字符串。
    int w = 0;//：写头，把保留的字符写回到更靠前的位置。
    int started = 0;//：是否已经写过第一个非空格字符。用它挡掉开头的空格。
    int prev_space = 0;//：写入端上一个字符是不是空格。用它把连续空格压成 1 个。
    while(s[r]==' ')r++;
    for (; s[r] != '\0' && s[r] != '\n'; r++) {
    if (s[r] == ' ') {
        if (started && !prev_space) {//已经写过非空格并且写入端上一个不是空格
            s[w++] = ' ';
            prev_space = 1;
        }
    } else {
        s[w++] = s[r];
        started = 1;//started是到目前为止是否写过非空格字符，写入过后会一直保持1，这样防止在字符串最前面写空隔
        prev_space = 0;
    }
    }
    /*去掉尾随空格*/
    if(w>0&&s[w-1]==' ')w--;
        s[w]='\0';
}
/*删除所有小写字母ab*/
void del_sub_ab(char s[])
{
    int r=0,w=0;
    while(s[r]!='\0'){
        if(s[r]=='a'&&s[r+1]=='b')r+=2;
        else s[w++]=s[r++];
    }
    s[w]='\0';
}
/*反转闭区间*/
void reverse_range(char s[],int L,int R){
    while(L<R){
        char t=s[L];
        s[L]=s[R];
        s[R]=t;
    }
}
//每个单词反转
void reverse_each_word(char s[]){
    int n=str_len(s);
    int i=0;
    while(i<n)//虽然外层while已经限定i<n了，但是内层循环依旧需要
    {
        while (i<n&&s[i]==' ')i++;
        if(i>=n)break;
        int L=i;
        while(i<n&&s[i]!=' ')i++;
        int R=i-1;
        reverse_range(s,L,R);
    }
}
/*大小写不敏感*/
int icmp(const char *a,const char *b)//const char *a 表示：指针 a 指向的字符内容不能被修改
{//const我只读，不写；
    for(;;)
    {
        unsigned char ca=(unsigned char)*a++;
        unsigned char cb=(unsigned char)*b++; 

        if (ca >= 'a' && ca <= 'z') ca -= 32;     // a..z -> A..Z
        if (cb >= 'a' && cb <= 'z') cb -= 32;

        if(ca!=cb||ca=='\0'||cb=='\0')return (int)ca -(int)cb;
    }
}
int main()
{
    char A[201],B[201];
    
    if (fgets(A,201,stdin)==NULL)return 0;
    if (fgets(B,201,stdin)==NULL)return 0;

    /*如果存在去掉末尾换行*/
    int la=str_len(A);if(la>0&&A[la-1]=='\n')A[la-1]='\0';
    int lb=str_len(B);if(lb>0&&B[lb-1]=='\n')A[lb-1]='\0';

    nomal_spaces(A);
    del_sub_ab(A);
    allupperchar(A);
    nomal_spaces(B);
    del_sub_ab(B);
    allupperchar(B);
    printf("%s\n",A);
    printf("%s\n",B);

    return 0;
}

/*
编程模拟题（凝练真题考点、一次性覆盖）
题名：字符串规范化、删除与比较（原地、无额外数组）
任务
读入两行字符串 A、B（长度 ≤ 200，可能含空格）。请只在原缓冲区内完成下列操作并输出结果：
去首尾空格 + 压缩中间空格：把连续 ≥2 个空格压成 1 个空格（用覆盖式左移实现）。
删除所有小写子串 "ab"（允许重叠）：如 "ababx" → 删除两次后为 "x"（同样用覆盖式左移）。
小写转大写：仅针对英文字母。
词内反转：对处理后的每个“单词”（以单个空格分隔）做原地反转（整体词序不变）。
实现 int icmp(const char *s1, const char *s2)：大小写不敏感比较，返回 <0/0/>0 语义与 strcmp 一致。
输出
第 1 行：规范化后的 A
第 2 行：规范化后的 B
第 3 行：icmp(A,B) 的返回值
*/

/*
一张小演示：怎么一步步变干净

输入（用 ␠ 表示空格）：
s = "␠␠a␠␠␠b␠␠\0"

初始：r=0,w=0, started=0, prev_space=0

跳过行首空格 → r 直接跳到 'a'

读 'a'：写 'a' → s="a..."，w=1, started=1, prev_space=0

读到一串空格：第一个空格满足“已开始且上一个不是空格”，写入 1 个空格；后续空格被跳过 → 现在 s="a␠...", w=2, prev_space=1

读 'b'：写 'b' → s="a␠b..."，w=3, prev_space=0

读到收尾空格：因为 prev_space 规则，最终不会写入；如果写入了一个，末尾清理步骤会把它删掉

收尾加 '\0'：得到 "a␠b\0"

结果就是 "a b"：

没有前导空格

中间连续空格变一个

没有尾随空格
*/