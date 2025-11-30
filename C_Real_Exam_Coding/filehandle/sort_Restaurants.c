#include<stdio.h>
struct TagRest
{
    int id;
    int distance;
    float rating;
};
struct TagRest arrayRests[10];
int Rest_cmp(struct TagRest *x,struct TagRest *y)
{
    if (x->distance < y->distance) return -1;
    if (x->distance > y->distance) return  1;
    /* distance 相等时按 rating 升序 */
    if (x->rating < y->rating) return 1;
    if (x->rating > y->rating) return -1;
    /* distance和rating 相等时按 id 升序 */
    if (x->id < y->id) return -1;
    if (x->id > y->id) return  1;
    return 0;
}
int ReadDataFromFile(struct TagRest a[])
{
    int n=0;
    FILE *p=fopen("E:/shanghaigongchengjishu/Clearn/8.1/C_Real_Exam_Coding/filehandle/Restaurants.txt","r");
    while(n<10&&fscanf(p,"%d %d %f",&a[n].id,&a[n].distance,&a[n].rating)==3)
    n++;
    fclose(p);
    for(int i=0;i<10;i++)
    {
        printf("%d %d %.2f\n",a[i].id,a[i].distance,a[i].rating);
    }
    return n;
}
void SortByDistanceRating(struct TagRest a[],int n)
{
    for(int i=1;i<n;i++)
    {   
        struct TagRest key=a[i];
        int left=0;int right=i;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(Rest_cmp(&a[mid],&key)<=0)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        int pos=left;
        for(int j=i-1;j>pos;j--)
        {
            a[j+1]=a[j];
        }
        a[pos]=key;
    }
    for(int i=0;i<10;i++)
    {
        printf("%d %d %.2f\n",a[i].id,a[i].distance,a[i].rating);
    }
}
int main()
{
    int n=ReadDataFromFile(arrayRests);
    SortByDistanceRating(arrayRests,n);
    return 0;
}
/*
某外卖平台需要在 App 中展示附近餐馆的基础信息。服务器会将筛选后的餐馆数据写到文本文件并下发到手机端。
设文件名为 Restaurants.txt，一行存放一条餐馆记录，每个字段之间以一个空格隔开：
第 1 列：餐馆编号 id（整型）
第 2 列：距离 distance（整型，单位米）
第 3 列：评分 rating（单精度浮点，范围 0.0 ~ 5.0）
例如单行数据：101 850 4.5
定义结构体 tagRest，表示餐馆数据。定义数组 arrayRests[10] 存储所有餐馆记录（假设每次固定发送 10 条数据）。
编写函数 ReadDataFromFile()：从文件 Restaurants.txt 读取数据到 arrayRests，并按读入顺序逐行打印（每行打印 id distance rating，用单个空格分隔，rating保留一位小数）。
编写函数 SortByDistanceRating()：将 arrayRests 按 距离从近到远 排序；若距离相同，则按 评分从高到低 排序；若评分也相同，则按 id 从小到大 排序。排序完成后再次打印全部数据（格式同上）。
编写 main 函数 调用上述功能：依次完成读入并打印 → 排序并打印的流程。
（提示：自行选择排序算法；注意 float 比较与输出格式控制。）
*/ 

