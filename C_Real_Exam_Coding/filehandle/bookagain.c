// 题目：图书数据统计与排序
// 从 Books.txt 读取图书数据，每行格式：
// id year borrow_count score
// 例：201 2020 156 8.7
// 要求：
// 定义结构体 tagBook，数组 arrayBooks[15]
// 读取文件并打印原始数据（score保留1位小数）
// 计算平均评分和总借阅次数
// 排序：先按借阅次数（高→低），再按评分（高→低）
// 输出：原始数据、统计结果、排序后数据
#include<stdio.h>
typedef struct tagBook{
    int id;int year;float borrow_count;float score;
}tagBook;
void read(tagBook b[],int *size){
    FILE*f=fopen("books.txt","r");
    if(f==NULL)return;
    int all_bo=0;
    float all_score=0.0;
    while(*size<15&&(fscanf(f,"%d %d %f %f",&b[*size].id,&b[*size].year,&b[*size].borrow_count,&b[*size].score))==4){
        printf("%d %d %.1f %.1f\n",b[*size].id,b[*size].year,b[*size].borrow_count,b[*size].score);
        all_bo+=b[*size].borrow_count;
        all_score+=b[*size].score;
        (*size)++;
    }
    printf("总借阅数:%d\n",all_bo);
    printf("平均分:%.1f\n",all_score/(*size));
}
//计算平均评分和总借阅次数
void se_sort(tagBook b[],int size){
    for(int i=0;i<size-1;i++){
        int curmax=i;
        for(int j=i+1;j<size;j++){
            if((b[curmax].borrow_count<b[j].borrow_count)||(b[curmax].borrow_count==b[j].borrow_count&&b[curmax].score>b[j].score)){
                curmax=j;// 排序：先按借阅次数（高→低），再按评分（高→低）
            }
        }
        tagBook temp=b[curmax];
        b[curmax]=b[i];
        b[i]=temp;
    }
    printf("排序后的数组:\n");
    for(int k=0;k<size;k++){
        printf("%d %d %.1f %.1f\n",b[k].id,b[k].year,b[k].borrow_count,b[k].score);
    }
}
int main(){
    tagBook b[15];
    int valid=0;
    read(b,&valid);
    se_sort(b,valid);
    return 0;
}