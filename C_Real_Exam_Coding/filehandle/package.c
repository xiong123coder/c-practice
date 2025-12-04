/*
题目：快递包裹信息处理系统
设文件名为 Packages.txt，一行存放一条包裹记录，每个字段之间以空格隔开。
第一列为包裹单号（id, 整型），
第二列为包裹重量（weight, 整型, 单位克），
第三列为运费（fee, 单精度浮点数，单位元）。

定义结构体 tagPackage，用于表示包裹数据。定义 tagPackage 类型的数组 arrayPkgs[10]，用于存储所有包裹数据（假设每次固定处理 10 条数据）。
编写函数 ReadDataFromFile()，读取完毕后在屏幕上打印原始数据。
编写函数 SortByWeightAndFee()，对数组进行排序。排序规则如下：
优先按重量 (weight) 从轻到重（升序）排列；
如果重量相同，则按运费 (fee) 从高到低（降序）排列。
排序完成后，打印排序后的数据。
编写 main 函数，依次调用上述功能，完成程序的执行。
*/
#include<stdio.h>
typedef struct {
    int id;int weight;float fee;
}tagPackage;
void read(tagPackage p[],int* size){
    FILE* f=fopen("Packages.txt","r");
    if(f==NULL){
        fprintf(stderr,"读取失败！");    
        return ;
    }
    int i=0;
    *size=0;
    while(i<15&&fscanf(f,"%d %d %f",&p[i].id,&p[i].weight,&p[i].fee)==3)
    {
        (*size)++;
        printf("文件中读取到的包裹的单号是:%d 重量是:%d 运费是:%.1f\n",p[i].id,p[i].weight,p[i].fee);
        i++;//一开始写错了i的位置,应该先printf再i++，如果先i++再printf当前包裹信息就乱码
    }
}
void SortByWeightAndFee(tagPackage p[],int index){
    for(int i=0;i<index-1;i++){
        int curmin=i;
        for(int j=i+1;j<index;j++){
            if(p[j].weight<p[curmin].weight||((p[j].weight==p[curmin].weight)&&(p[j].fee>p[curmin].fee)))
                curmin=j;
        }
        tagPackage temp=p[curmin];
        p[curmin]=p[i];
        p[i]=temp;
    }
    printf("排序好的数组是:\n");
    for(int k=0;k<index;k++){
        printf("第%d个包裹的单号是：%d 重量是：%d 运费是：%.1f\n",k+1,p[k].id,p[k].weight,p[k].fee);
    }
}
int main(){
    tagPackage p[15];
    int index=0;
    read(p,&index);
    SortByWeightAndFee(p,index);
    return 0;
}