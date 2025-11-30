/*
题目：学生成绩统计与排序系统
题目描述：
编写一个C语言程序，从名为"data.txt"的文件中读取学生成绩数据，并对这些成绩进行统计分析。
程序需要实现以下功能：
文件读取：从"data.txt"文件中读取数据，如果文件不存在或无法打开，给出提示信息
数据统计：计算成功读取的所有成绩的平均分
成绩排序：使用选择排序算法将成绩按从高到低的顺序排列
结果输出：输出读取的每个成绩、平均分以及排序后的成绩列表
*/
#include<stdio.h>
int main()
{
    FILE *fp;
    int a[10];
    //char a[10][100];
    fp=fopen("data.txt", "r");
    if(fp==NULL)
    {
        printf("文件打不开!\n");
        return 1;
    }
    int j=0;
    float sum=0.0;
    while(j<10&&fscanf(fp,"%d",&a[j])==1)
    // while(j<10&&fscanf(fp,"%99s",a[j])==1)
    {
        printf("读到第%d个数:%d\n",j+1,a[j]);
        sum+=a[j];
        j++;
    }
    if(j==0){  
        printf("没有读入数据");
    }
    else
        {
            printf("平均分:%1f\n",sum/j);
            for(int i=0;i<j;i++)
            {
                int cur_max=i;
                for(int k=i;k<j;k++)
                {
                    if(a[cur_max]<a[k])
                    {
                        cur_max=k;
                    }
                }
                //换位而不是覆盖
                int t=a[i];
                a[i]=a[cur_max];
                a[cur_max]=t;
            }
            for(int i=0;i<j;i++){
                printf("%d ",a[i]);
            }
        }
    fclose(fp);
    return 0;
}
/*
优化建议：
将外循环的结束条件从 i < j 改为 i < j-1
减少最后一轮不必要的循环和交换
（因为当 i = j-1 时，数组只剩最后一个元素，必然是已排序状态）。

如果data.txt没有放在与output里面，直接写“data.txt”会打不开*/
