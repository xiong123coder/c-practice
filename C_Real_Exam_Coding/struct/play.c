/*定义一个运动员结构体，包含姓名（name[20]）、编号（no[10]）和成绩（score，浮点
型）三个成员。编写程序实现以下功能：
（1）初始化 3 个运动员的信息并存储；
（2）根据输入的姓名查找对应的运动员信息，如果找到则输出该运动员的姓名、编号和成
绩；如果未找到则输出 “未找到该运动员”；
（3）在指定的位置（下标）插入一条新的运动员信息，并输出插入后所有运动员的信息（插
入位置需在有效范围内，即 0 到当前运动员数量之间）。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {char name[20];int no;float score;}player;
int find(player s[],char target[]){
    for(int i=0;i<3;i++){
        if(strcmp(s[i].name,target)==0)
            return i;
    }
    return -1;//不要写在循环内部，否则find函数只能找第一次
}
/*（3）在指定的位置（下标）插入一条新的运动员信息，并输出插入后所有运动员的信息（插
入位置需在有效范围内，即 0 到当前运动员数量之间）。*/
void insert(player s[],int play_num){
    int target_i;
    scanf("%d",&target_i);
    if(target_i<0||target_i>play_num){
        printf("请你输入有效下标");
        return;
    }else{
        for(int j=play_num;j>target_i;j--){
            s[j]=s[j-1];
        }

        player new={"新",999,0.78};
        s[target_i]=new;
    }
    for (int i = 0; i < play_num + 1; i++) {
        printf("%s %d %.2f\n", s[i].name, s[i].no, s[i].score);
    }    
}
int main(){
    player s[4]={{"刘翔",1,0.89},{"小何",2,0.88},{"小欣",3,0.90}};
    char target[25];
    scanf("%s",target);
    int pos=find(s,target);
    
    if(pos!=-1)
    {
        printf("找到%s啦,她的id是%d,成绩是%.2f\n",s[pos].name,s[pos].no,s[pos].score);
    }else{
        printf("没有找到该运动员");
    }
    insert(s,2);
    return 0;
}