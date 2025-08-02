#include<stdio.h>
void swap(int *b,int *c)
{
    int temp=*b;
    *b=*c;
    *c=temp;
}
void selectsort(int a[],int n)
{
    for(int j=0;j<n;j++)
    {
        int minindex=j;
        for(int i=j+1;i<n;i++)
        {
            if(a[i]<a[minindex])
            {
                minindex=i;
            }            
        }
        if(minindex!=j)
        //假如其中有一轮循环中，minindex=j时已经是最小，那么没有必要swap，浪费时间
        swap(&a[minindex],&a[j]);
    }
}
int main()
{
    int arr[]={7,8,4,9,2,1};
    int len=sizeof(arr)/sizeof(arr[0]);
    selectsort(arr,len);
    for(int i=0;i<len;i++)
        printf("%d ",arr[i]); 
}