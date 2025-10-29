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

文件路径反斜杠要么写成 \\，要么直接用 /；
fp=fopen("e:/shanghaigongchengjishu/Clearn/8.1/C_Real_Exam_Coding/filehandle/data.txt", "r");
使用"\"会被视为转义标识符
如果data.txt没有放在与.exe并列的位置，直接写“data.txt”会打不开*/
