#include<stdio.h>
#include<string.h>
void swap(char* b,char* c)
{
    char temp=*b;
    *b=*c;
    *c=temp;
}
void lower_sort(char a[],int n)
{   
    for(int j=0;j<n;j++)
    {   
        if(a[j]<'a'||a[j]>'z')
        {
            continue;
        }
        int minindex=j;    
        for(int i=j+1;i<n;i++)
        {
            if(a[i]<a[minindex])
            {
                minindex=i;
            }
        }
        if(minindex!=j)
            swap(&a[minindex],&a[j]);
    }
}
int main()
{   
    char urstring[100];
    scanf("%s",urstring);
    int len=strlen(urstring);
    lower_sort(urstring,len);  
    printf("%s",urstring);
    return 0;
}