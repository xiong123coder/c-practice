#include<stdio.h>
#include<string.h>
#define MAXSINGER 10
typedef struct {char name[20];int sone;int stwo;int ave=0;}Singer;
//假如在打开文件之前就已知有效个数为6
Singer* read_file_sort(){
    FILE*f=fopen("scores.txt","r");
    if(f==NULL)return NULL;
    Singer singers[MAXSINGER];
    Singer temp;
    for(int i=0;i<MAXSINGER;i++)
    {
        if(fscanf("%19s %d %d",singers[i].name,&singers[i].sone,&singers[i].stwo)!=3)
        {
            fclose(f);
            f=NULL;
        }
        singers[i].ave=singers[i].sone+singers[i].stwo;
    }
    for(int i=0;i<5;i++)
    {
        int cur_max=i;
        for(int j=i+1;j<6;j++)
        {
            if(singers[j].ave>singers[cur_max].ave)
            {
                cur_max=j;
            }
        }
        temp=singers[cur_max];
        singers[cur_max]=singers[i];
        singers[i]=temp;
    }
    return singers;
}

int half(Singer s[],int n){
    int low=0;int high=n-1;int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(s[mid])
    }
}
int main(){
    Singer*singers=read_file_sort();
    return 0;
}