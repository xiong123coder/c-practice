#include<stdio.h>
void countcase(char a[])
{
    int count[26]={0};
    /*int count[26];本来这样写，导致输出了其他字母有
    奇怪的数量，因为没有初始化就有垃圾值
    下次使用数组前务必对数组提前{0}初始化
    */
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>='a'&& a[i]<='z')
        {
            count[a[i]-'a']++;//利用偏移量来计字母个数
        }
    }
    for(int j=0;j<26;j++)
        if(count[j]>0)//一开始没有剔除个数为0的字母，导致输出内容冗余
        //以后要考虑是否需要利用if判断将没必要的输出排除
        printf("%c: %d\n",j+'a',count[j]);//利用ASCII码+j
}
int main()
{
    char urstring[100];
    /*scanf("%s",urstring);scanf会被空格截断，是默认在中间不会输入空格的情况
    原理：scanf("%s") 读取字符串时是以空白字符（空格、换行、tab）为“分隔符”结束的。*/
    fgets(urstring,sizeof(urstring),stdin);
    //fgets支持含空格的输入
    countcase(urstring);
    return 0;
}
/*stdin：输入流
表示从“标准输入”读取内容，也就是键盘输入。
如果你以后要从文件读取，就可以用其他 FILE*，如：
FILE *fp = fopen("data.txt", "r");
fgets(buffer, sizeof(buffer), fp);
*/