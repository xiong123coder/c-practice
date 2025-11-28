/* 定义一个书籍结构体，包含：
   书名（title[30]）、ISBN编号（isbn[15]）和价格（price，浮点型）
   三个成员。编写程序实现以下功能：

   （1）初始化 3 本书的信息并存储；
   （2）根据输入的书名查找对应书籍，如果找到则输出该书的书名、ISBN和价格；
       如果未找到则输出 “未找到该书籍”；
   （3）在指定的位置（下标）插入一本新的书籍信息，并输出插入后所有书籍的信息
       （插入位置需在有效范围内，即 0 到当前书籍数量之间）。
*/
#include<stdio.h>
#include<string.h>
typedef struct{char title[30];int isbn;float price;}Book;
int find_printf(Book b[],char target[],int n){
    for(int i=0;i<n-1;i++){
        if(strcmp(b[i].title,target)==0)
            return i;
    }
    return -1;
}

void insert(Book b[],int len,Book new){
    int given;
    scanf("%d",&given);
    if(given<0||given>len){
        return;
    }else{
        for(int j=len;j>given;j--){
            b[j]=b[j-1];
        }
        b[given]=new;
        printf("插入后的所有书籍信息\n");
        for(int i=0;i<len;i++)
        {
            printf("书名%s 编号%d 价格%.2f\n",b[i].title,b[i].isbn,b[i].price);
        }
    }
}
int main(){
    Book new={"欣书",666,999.99};
    Book books[4]={{"红与黑",2,52},{"爱欣日记",1,99},{"小王子",3,66}};
    char target[25];
    scanf("%25s",target);
    int pos=find_printf(books,target,4);
    if(pos!=-1){
        printf("找到%s了,编号和价格分别是%d %.2f\n",books[pos].title,books[pos].isbn,books[pos].price);
    }else{
        printf("未找到该书籍\n");
    }
    insert(books,4,new);
    return 0;
}