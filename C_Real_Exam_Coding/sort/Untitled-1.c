#include<stdio.h>
void swap(int* c,int* b)
{
    int temp=*c;
    *c=*b;
    *b=temp;
}
void selectsort(int a[],int n)
{
    for(int j=0;j<n;j++)
    {   
        int minindex=j;
        int i;
        for(i=j;i<n;i++)
        {
            if(a[i]<a[minindex])            
                minindex=i;
        }
        if(minindex!=j){
            swap(&a[minindex],&a[j]);
            // int temp=a[j];
            // a[j]=a[minindex];
            // a[minindex]=temp;
        }
    }
}

int main()
{
    int arr[]={7,8,4,6,1};
    int len=sizeof(arr)/sizeof(arr[0]);
    selectsort(arr,len);
    for(int i=0;i<len;i++)    
        printf("%d ",arr[i]);
    return 0;
}