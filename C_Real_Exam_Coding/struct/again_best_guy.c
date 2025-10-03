#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char name[20];int chi,math,eng;int sum;
}Student;
int main()
{
    int N;
    if (scanf("%d",&N) != 1 || N <= 0)return 0;//返回的项数
    Student* a=malloc(sizeof *a*N);
    if (!a) return 0;
    for(int i=0;i<N;i++)
    {
        scanf("%19s %d %d %d",a[i].name,&a[i].chi,&a[i].math,&a[i].eng);
        a[i].sum=a[i].chi+a[i].math+a[i].eng;
    }
    for(int j=1;j<N;j++)
    {//找到第一个小于插入值的数
        int low=0;
        int high=j;
        Student key=a[j];
        int mid=j;
        while(low<high)
        {
            if(a[mid].sum<key.sum)
                high=mid;
            else
                low=mid+1;
        }
        int pos=low;
        for (int i = j; i > pos; --i) a[i] = a[i-1];
        a[low]=key;
    }
    printf("%s %d %d %d\n", a[0].name, a[0].chi, a[0].math, a[0].eng);
    free(a);
    return 0;
}
//先提前理解二分查找的原理，再写代码会特别快
//动态数组