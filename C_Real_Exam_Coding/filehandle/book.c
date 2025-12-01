/*定义一个图书结构体，包含以下成员：
bookID（int 型）pages（int 型，页数）rating（float 型，评分）
程序要求：
从文件 Books.txt 中读取最多 10 本图书的信息
将读取到的结构体数据存入结构体数组中，并在读取后输出所有图书的信息
对图书数组排序，排序规则为：
先按 pages 从小到大,如果页数相同，则按 rating 从大到小
排序完成后输出排序后的结果。
*/  
#include<stdio.h>
typedef struct{int bookID;int pages;float rating;}book;
void read_from_file(book b[]){
    FILE*f=fopen("book.txt","r");    
    if(f==NULL){return;}
    int i = 0;
    while (i < 10 && fscanf(f, "%d %d %f", 
            &b[i].bookID, &b[i].pages, &b[i].rating) == 3) {
        i++;
    }

    fclose(f);        
    printf("以下为读取的文件数据：\n");
    for(int j=0;j<10;j++)
    {
        printf("%d  %d  %.2f\n",b[j].bookID,b[j].pages,b[j].rating);    
    }
}    
void select_sort(book b[],int n){
    book t;
    for(int i=0;i<n-1;i++)
    {
        int cur_min=i;
        for(int j=i+1;j<n;j++){
            if(b[j].pages<b[cur_min].pages||(b[j].pages==b[cur_min].pages&&b[j].rating>b[cur_min].rating)){
                cur_min=j;
            }
        }
        t=b[cur_min];
        b[cur_min]=b[i];
        b[i]=t;
    }
    printf("以下是排序后的数组：\n");
    for(int k=0;k<n;k++){
        printf("%d %d %f\n",b[k].bookID,b[k].pages,b[k].rating);
    }
}
int main(){
    book b[10];
    read_from_file(b);
    select_sort(b,10);
    return 0;
}