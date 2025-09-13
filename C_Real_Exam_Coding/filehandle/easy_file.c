#include<stdio.h>
int main()
{
    FILE *fp;
    int x;
fp=fopen("data.txt", "r");
//文件路径反斜杠要么写成 \\，要么直接用 /；
//e:/shanghaigongchengjishu/Clearn/8.1/C_Real_Exam_Coding/filehandle/data.txt
//使用"\"会被视为转义标识符
//直接写“data.txt”会打不开
    if(fp==NULL)
    {
        printf("文件打不开!\n");
        return 1;
    }

    while(fscanf(fp,"%d",&x)==1)
    {
        printf("读到一个数:%d\n",x);
    }

    fclose(fp);
    return 0;
}

