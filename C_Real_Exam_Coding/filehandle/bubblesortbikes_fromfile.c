#include <stdio.h>
struct tagBike{int id;int distance;float discount;};
struct tagBike arrayBikes[10];
int readfile(struct tagBike a[])
{
    FILE *p=fopen("e:/shanghaigongchengjishu/Clearn/8.1/C_Real_Exam_Coding/filehandle/Bikes.txt","r");

    int n=0;
    while(n<10&&fscanf(p,"%d %d %f",&a[n].id,&a[n].distance,&a[n].discount)==3)n++;
    fclose(p);
    for(int i=0;i<n;i++)
    {
        printf("%d %d %.2f\n",a[i].id,a[i].distance,a[i].discount);
    }
    return n;
}
void sortbikes(struct tagBike a[],int n)
{
    
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j].distance>a[j+1].distance||(a[j].distance==a[j+1].distance&&a[j].discount>a[j+1].discount))
            {
                struct tagBike t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    for(int i=0;i<n;i++)
    {
        printf("%d %d %.2f\n",a[i].id,a[i].distance,a[i].discount);
    }
}
int main(void)
{
    int n=readfile(arrayBikes);
    sortbikes(arrayBikes,n);
    return 0;
}

/*
共享单车成功解决了公共交通的“最后一公里”难题和短途出行的问题。单车上装有定
位
系统，手机 APP 上传用户位置信息，服务器会筛选出一定范围内所有的单车，并将单
车编号、距离、折扣率等信息以文件形式发送到手机上。
设文件名为 Bikes.txt，一行存放一条单车记录，每个字段之间以空格隔开，第一列为单
车编号（id, 整形），第二列为距离（distance, 整形, 单位米），第三列为折扣率
（discount, 单精度数，0~1 之间，0 为免费，1 为原件）。
1）定义结构体 tagBike，表示单车数据。定义 tagBike 数组 arrayBikes[10]，存储所有单
车数据（假设每次固定发送 10 条数据）。
2）编写函数 ReadDataFromFile()，读取文件将数据赋值到 arrayBikes 数组中，并打印
出来。
3）编写函数 SortByDistanceDiscont()，将数据按照单车距离从近到远，再按折扣率从
底到高排列，并将数据打印出来。
4）编写 main 函数，调用上述功能
*/

/*
二分插入排序 = 插入排序 + 二分查找，优化了查找插入位置的效率，
但无法减少元素移动，所以整体复杂度依然是 O(n²)
*/