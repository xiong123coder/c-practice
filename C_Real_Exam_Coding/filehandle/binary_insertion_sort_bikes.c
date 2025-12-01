/*
题目（符合2025真题编程题考向）
共享单车管理系统
typedef struct
{
    int id;         
    int distance;   
    float discount; 
} tagBike;
使用选择排序算法对所有单车
按骑行距离进行降序排列。当骑行距离相同时，按折扣进行升序排列。
排序后输出所有单车的完整信息。
*/
#include <stdio.h>
typedef struct
{
    int id;         
    int distance;   
    float discount; 
} tagBike;
void read(tagBike b[], int *valid_n)
{
    FILE *f = fopen("Bikes.txt", "r");
    if (f == NULL)
        return;
    int i = 0;
    *valid_n = 0;
    while (i < 15 && (fscanf(f, "%d %d %f", &b[i].id, &b[i].distance, &b[i].discount)) == 3)
    {
        (*valid_n)++;
        printf("第%d个共享单车系统的信息:%d %d %.2f\n", i + 1, b[i].id, b[i].distance, b[i].discount);
        i++;
    }
}
void select_sort(tagBike b[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int cur = i;
        for (int j = i + 1; j < size; j++)
        {
            if (b[j].distance > b[cur].distance || (b[j].distance == b[cur].distance && b[j].discount < b[cur].discount))
            {
                cur = j;
            }
        }
        tagBike t = b[cur];
        b[cur] = b[i];
        b[i] = t;
    }
    printf("排序后的数组是:\n");
    for (int k = 0; k < size; k++)
    {
        printf("第%d个自行车的id是：%d 距离是：%d 折扣是：%.2f\n", k + 1, b[k].id, b[k].distance, b[k].discount);
    }
}
int find(tagBike b[], int size, tagBike target)
{

    for (int i = 0; i < size; i++)
    {
        if (b[i].distance == target.distance)
        {
            return i;
        }
    }
    return -1;
}
void insert(tagBike b[],int *size,tagBike target){
    if(*size>=15){
        fprintf(stderr,"数组已满，无法插入");
        return ;
    }
    int index=*size;
    for(int i=0;i<(*size);i++){
        if(b[i].distance<target.distance||((b[i].distance==target.distance)&&(b[i].discount>target.discount)))
        {
            index=i;
            break;
        }
    }
    for(int j=(*size);j>index;j--){
        b[j]=b[j-1];
    }
    b[index]=target;
    (*size)++;
    printf("排序后的数组:/n");
    for(int i=0;i<*(size);i++){
        printf("第%d个自行车的距离:%d ,折扣是%.2f\n",i+1,b[i].distance,b[i].discount);
    }
}

int main()
{
    int size = 0;
    tagBike b[15];
    read(b, &size);
    select_sort(b, size);
    tagBike target;
    printf("你要查找的目标信息是：");
    scanf("%d %d %f", &target.id, &target.distance, &target.discount);
    int pos = find(b, size, target);
    if (pos != -1)
    {
        printf("找到啦！这个自行车距离你的距离：%d\n", b[pos].distance);
    }
    else
    {
        printf("没有找到，正在插入.....\n");
        insert(b, &size, target);
    }
    return 0;
}
