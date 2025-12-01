/*
题目（符合2025真题编程题考向）
共享单车管理系统
已知共享单车结构体定义如下：
<C>
编号 骑行距离 折扣
使用选择排序算法对所有单车
按骑行距离进行降序排列。当骑行距离相同时，按折扣进行升序排列。
排序后输出所有单车的完整信息。
*/
#include<stdio.h>
typedef struct {
    int id;        // 单车编号
    int distance;  // 骑行距离（单位：米）
    float discount; // 优惠折扣
}tagBike;
void read(tagBike b[],int *valid_n){
    FILE*f=fopen("Bikes.txt","r");
    if(f==NULL)return ;
    int i=0;
    *valid_n=0;
    while(i<15&&(fscanf(f,"%d %d %f",&b[i].id,&b[i].distance,&b[i].discount))==3)
    {   
        (*valid_n)++;
        printf("第%d个共享单车系统的信息:%d %d %.2f\n",i,b[i].id,b[i].distance,b[i].discount);
        i++;
    }
}
void select_sort(tagBike b[],int size){
    for(int i=0;i<size-1;i++){
        int cur=i;
        for(int j=i+1;j<size;j++){
            if(b[j].distance>b[cur].distance||(b[j].distance==b[cur].distance&&b[j].discount<b[cur].discount))
            {
                cur=j;
            }
        }
        tagBike t=b[cur];
        b[cur]=b[i];
        b[i]=t;   
    }
    printf("排序后的数组是:\n");
    for(int k=0;k<size;k++){
        printf("第%d个自行车的id是：%d 距离是：%d 折扣是：%.2f\n",k,b[k].id,b[k].distance,b[k].discount);
    }
}
int main(){
    int size=0;
    tagBike b[15];
    read(b,&size);
    select_sort(b,size);
}