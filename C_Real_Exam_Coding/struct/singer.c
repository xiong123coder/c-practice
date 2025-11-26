#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {char name[20];int sone;int stwo;int sum;}Singer;
//假如在打开文件之前就已知有效个数为6
Singer* read_file_sort(){
    FILE*f=fopen("scores.txt","r");
    if(f==NULL)return NULL;
    Singer* singers=malloc(7*sizeof(Singer));
    if(singers==NULL){fclose(f);return NULL;}
    Singer temp;
    for(int i=0;i<6;i++)
    {
        if(fscanf(f,"%19s %d %d",singers[i].name,&singers[i].sone,&singers[i].stwo)!=3)
        {
            fclose(f);
            free(singers);
            return NULL;
            /*
            singers 是你自己 malloc 的，所以你负责 free。
            f 是系统通过 fopen 创建的，所以你只能 fclose。
            */
        }
        singers[i].sum=singers[i].sone+singers[i].stwo;
    }
    for(int i=0;i<5;i++)
    {
        int cur_max=i;
        for(int j=i+1;j<6;j++)
        {
            if(singers[j].sum>singers[cur_max].sum)
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

int half_search(Singer s[],int n,int target){
    int low=0;int high=n-1;int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(s[mid].sone==target)//降序由高到低99 88 77 66 找89
            return mid;
        else if(s[mid].sone<target)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
void insert_printf(Singer s[],int n,Singer new){
    int index=n;//默认插入到最后
    for(int i=0;i<n-1;i++)
    {
        if(s[i].sone<new.sone)
        {
            index=i;
            break;
        }
    }
    for(int j=n;j>=index;j--)s[j]=s[j-1];
    s[index]=new;
    for(int j=0;j<7;j++){
        printf("MR.%s 的总分是:%d!!\n",s[j].name,s[j].sum);
    }
}
int main(){
    Singer*singers=read_file_sort();
    Singer new={"欣欣",82,77,159};
    int result=half_search(singers,6,new.sone);
    if(result!=-1){//找到了
        printf("找到%s %.2d",singers[result].name,singers[result].sum);
    }
    else{//没找到->insert
        insert_printf(singers,6,new);
    }
    free(singers);
    return 0;
}