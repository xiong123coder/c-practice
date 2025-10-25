#include<stdio.h>
int main()
{
    FILE *fp;
    char a[10][100];
    fp=fopen("e:/shanghaigongchengjishu/Clearn/8.1/C_Real_Exam_Coding/filehandle/data.txt", "r");
    if(fp==NULL)
    {
        printf("文件打不开!\n");
        return 1;
    }
    int j=0;
    while(j<10&&fscanf(fp,"%99s",a[j])==1)
    {
        printf("读到第%d个数:%s\n",j,a[j]);
        j++;
    }   

    fclose(fp);
    return 0;
}
//文件路径反斜杠要么写成 \\，要么直接用 /；
//e:/shanghaigongchengjishu/Clearn/8.1/C_Real_Exam_Coding/filehandle/data.txt
//使用"\"会被视为转义标识符
//直接写“data.txt”会打不开
