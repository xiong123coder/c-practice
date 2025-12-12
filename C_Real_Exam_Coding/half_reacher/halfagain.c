// 有一个升序排列的包含 10 个整数的数组，编写程序实现以下功能：
// （1）输入一个整数，使用折半查找算法判断该整数是否在数组中；
// （2）若该整数在数组中，输出该整数在数组中的下标（下标从 0 开始）；
// （3）若该整数不在数组中，将该整数插入到数组中合适的位置，使数组仍然保持升序，并
// 输出插入后的数组
#include<stdio.h>
int half_search(int a[],int size,int target){
    int low=0;int high=size-1;int mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
void insert(int a[],int size,int target){
    int index=0;
    for(int i=0;i<size;i++){
        if(a[i]>target){
            index=i;
            break;
        }
    }

    for(int j=size;j>index;j--){
        a[j]=a[j-1];
    }
    a[index]=target;
    printf("插入后的数组是：\n");
    for(int k=0;k<=size;k++){
        printf("%d\n",a[k]);
    }
}
int main(){
    int a[11]={1,4,5,6,8,9,12,14,16,19};
    int target=0;
    scanf("%d",&target);
    int pos=half_search(a,10,target);
    if(pos!=-1){
        printf("恭喜你，找到啦，该整数在数组中的下标是：%d\n",pos);
    }else{
        printf("没有找到，插入中，等等......\n");
        insert(a,10,target);
    }
    return 0;
}
