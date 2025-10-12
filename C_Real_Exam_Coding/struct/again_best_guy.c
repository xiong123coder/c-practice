#include<stdio.h>
#include<stdlib.h>
//结构体和变量定义
typedef struct{
    char name[20];
    int chi,math,eng;
    int sum;
}Student;
int main()
{
    int N;//学生人数
    if(scanf("%d",&N)!=1||N<=0){
        printf("无效的学生人数输入！\n");
        return 0;
    }
    Student* a=malloc(sizeof(Student)*N);
    if(!a){
        printf("内存分配失败\n");
        return 0;
    }
    printf("请输入学生数据(姓名，语文，数学，英语):\n");
    for(int i=0;i<N;i++){
        if(scanf("%19s %d %d %d",a[i].name,&a[i].chi,&a[i].math,&a[i].eng)!=4)
        {
            printf("输入格式错误\n");
            free(a);
            return 0;
        }
        a[i].sum = a[i].chi + a[i].math + a[i].eng;
    }
    for(int i=1;i<N;i++)
    {
        Student key=a[i];
        int low=0;
        int high=i;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(a[mid].sum<key.sum)
                high=mid;
            else
                low=mid+1;
        }
        int pos=low;
        for(int j=i;i>pos;i--)
        {
            a[j]=a[j-1];
        }
        a[pos]=key;
    }
    printf("\n总分最高的学生:\n");
    printf("姓名: %s\n", a[0].name);
    printf("语文: %d, 数学: %d, 英语: %d\n", a[0].chi, a[0].math, a[0].eng);
    printf("总分: %d\n", a[0].sum);
    free(a);
    return 0;
}
/*
1.scanf返回读取的个数
所以便于用if检查是否正确读取输入
2.if(!a)的含义​​
a是指向分配内存的指针
！a等同于a==NULL
可以检查内存分配是否失败
3.a[i]=a[i-1]
如果是a[i+1]=a[i]会覆盖key后面的元素
4.（降序）二分插入排序，时间复杂度是O(n^2)但比较次数O(logn)
目标找第一个比key小的位置，
每次比较mid和key的sum时，小于就是要往左找，并且high==mid，因为high的位置任然有可能恰好是要插入的位置
如果大于，则说明mid的位置一定不是，并且需要往mid右找，所以low=mid+1;
因为mid每次都是一段区间的中间，所以即便找到了大的位置，但是还不能确定，必须要当low==high才行，
*/