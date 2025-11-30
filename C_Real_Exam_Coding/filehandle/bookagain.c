// 题目：图书数据统计与排序
// 从 Books.txt 读取图书数据，每行格式：
// book_id year borrow_count score
// 例：201 2020 156 8.7
// 要求：
// 定义结构体 tagBook，数组 arrayBooks[15]
// 读取文件并打印原始数据（score保留1位小数）
// 计算平均评分和总借阅次数
// 排序：先按借阅次数（高→低），再按评分（高→低）
// 输出：原始数据、统计结果、排序后数据
#include<stdio.h>
typedef struct {int book_id;int year;int borrow_count;float score;}book;
void read(book b[],int *size){
    size=0;
    FILE*f=fopen("books.txt","r");
    if(f==NULL)return ;
    int i=0;
    float sumscores=0.0;
    int sumlend=0; 
    while(i<15&&(fscanf(f,"%d %d %d %f",&b[i].book_id,&b[i].year,&b[i].borrow_count,&b[i].score)==4))
    {
        *size=i;
        printf("读取到的第%d本书: %d %d %d %f\n",i+1,b[i].book_id,b[i].year,b[i].borrow_count,b[i].score);
        sumscores+=b[i].score;
        sumlend+=b[i].borrow_count;
        i++;
    }
    fclose(f);
    printf("平均分是:%.1f,总借阅次数:%d\n",(double)sumscores / *size,sumlend);
}
void select_sort(book b[], int size){
    book t;
    for(int i=0;i<size-1;i++){
        int curmax=i;
        for(int j=i+1;j<size;j++){
            if(b[j].borrow_count<b[curmax].borrow_count||(b[j].borrow_count==b[curmax].borrow_count)&&(b[j].score>b[curmax].score))
                curmax=j;
        }
        if (curmax != i) {
            book t = b[curmax];
            b[curmax] = b[i];
            b[i] = t;
        }
    }
    printf("排序后如下:\n");
    for(int k=0;k<size;k++){
        printf("读取到的第%d本书: %d %d %d %f\n",k+1,b[k].book_id,b[k].year,b[k].borrow_count,b[k].score);
    }
}
int main(){
    book b[15];
    int size=0;
    read(b,&size);
    select_sort(b,size);
    return 0;
}