/*
c程序设计编程大题
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
添加给定的单车信息
*/
#include<stdio.h>
typedef struct {
    int id;
    int distance;
    float discount;
}tagBike;
void read_selectsort(tagBike b[],int *size){
    FILE*f=fopen("Bikes.txt","r");
    if(f==NULL){
        fprintf(stderr,"不能以读模式打开Bikes.txt文件\n");
        return ;
    }
    int i=0;
    while(i<15&&fscanf(f,"%d %d %f",&b[i].id,&b[i].distance,&b[i].discount)==3){
        (*size)++;
        printf("第%d个自行车的信息是:%d %d %.2f\n",i+1,b[i].id,b[i].distance,b[i].discount);
        i++;
    }
    tagBike temp;
    for(int j=0;j<(*size)-1;j++){
        int cur=j;
        for(int k=j+1;k<*size;k++){
            if(b[k].distance>b[cur].distance||((b[k].distance==b[cur].distance)&&b[k].discount<b[cur].discount))
            cur=k;     
        }
        temp=b[cur];
        b[cur]=b[j];
        b[j]=temp;
    }
    printf("排序后的数组是:\n");
    for(int k=0;k<*size;k++){
        printf("第%d个自行车的id:%d 距离是:%d 折扣是:%.2f\n",k+1,b[k].id,b[k].distance,b[k].discount);
    }
}
int find(tagBike b[],tagBike t,int size){
    for(int i=0;i<size;i++){
        if(b[i].distance==t.distance){
            return i;
        }
    }
    return -1;
}
void insert(tagBike b[],int* size,tagBike target){
    if(*size>=15){
        fprintf(stderr,"抱歉，数组已满暂时无法插入！\n");
        return ;
    }
    int index=*size;
    for(int i=0;i<*size;i++){
        if(b[i].distance<target.distance||((b[i].distance==target.distance)&&b[i].discount>target.discount))
        {
            index=i;
            break;
        }
    }
    for(int j=*size;j>index;j--){
        b[j]=b[j-1];
    }
    b[index]=target;
    (*size)++;
    printf("添加后的数组是:\n");
    for(int k=0;k<*size;k++){
        printf("第%d个自行车的id:%d 距离是:%d 折扣是:%.2f\n",k+1,b[k].id,b[k].distance,b[k].discount);
    }
}
int main(){
    tagBike b[15];
    int size=0;
    read_selectsort(b,&size);
    tagBike target;
    printf("请你输入你要找的自行车:\n");
    scanf("%d %d %f",&target.id,&target.distance,&target.discount);
    int pos=find(b,target,size);
    if(pos==-1){
        printf("没有找到奥\n");
        printf("正在插入中，请稍后。。。\n");
        insert(b,&size,target);
    }else{
        printf("找到了，这个自行车距离你%d米!\n",b[pos].distance);
    }
}