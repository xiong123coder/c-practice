#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int score[2];
    char *name;
    int max;
    float avg;
}STU;
void readfile(FILE* p,STU stu[]){
    int j=0;
    while(j<4&&fscanf(p,"%5s %3d %3d",stu[j].name,&stu[j].score[0],&stu[j].score[1])==3)
    {
        int sum=0;
        sum=stu[j].score[0]+stu[j].score[1];
        stu[j].avg=sum/2.0;
        printf("%s同学的数学分数是:%d, c语言分数是%d,平均分是%.1f\n",stu[j].name,stu[j].score[0],stu[j].score[1],stu[j].avg);
        j++;
    }
}
int main(){
    FILE*p=fopen("studata.txt","r");
    if(!p){
        perror("指针不存在");
        return 1;
    }
    STU stu[4];
    for(int i=0;i<4;i++)
    {
        stu[i].name=(char*)malloc(6*sizeof(char));
    }
    readfile(p,stu);
    for(int i=0;i<4;i++)
    {
        free(stu[i].name);
        stu[i].name=NULL;
    }
    fclose(p);
    return 0;
}
/*
如何去掉多余的 0？
如果希望只显示指定位数的小数（比如 1 位或 2 位），可以在%f中指定精度，格式为%.nf（n是要保留的小数位数）。
*/ 