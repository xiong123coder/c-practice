#include<stdio.h>
#define COURSE_NUM 3
#define STU_NUM 3
struct Student
{
     int id;
     char name[20];
     int scores[COURSE_NUM];   
};
int main()
{
    struct Student students[STU_NUM];
    int totalscores=0;
    for(int i=0;i<STU_NUM;i++)
    {
        printf("请输入第%i个学生的信息:",i+1);
        scanf("%d %s %d %d %d",
        &students[i].id,
        students[i].name,
        &students[i].scores[0],
        &students[i].scores[1],
        &students[i].scores[2]);
    }
    for(int i=0;i<STU_NUM;i++)
    {
        int sum=0;
        for(int j=0;j<COURSE_NUM;j++)
        {
            sum+=students[i].scores[j];
        }
        totalscores+=sum;
    }
    double avg=totalscores/3.0;
    printf("三人平均分是:%.1f\n",avg);
}
/*
id 是一个变量，它存放的是值。
scanf 需要一个地址，才能把输入的值写到内存里。
所以要用 &id，取出变量的地址。

数组名 name 在表达式里，自动退化为指向第一个元素的指针。
所以 name 等价于 &name[0]。
也就是说，这里 name 已经是地址了，不需要再写 &
*/