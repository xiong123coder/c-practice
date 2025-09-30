#include<stdio.h>
#define COU_NUM 3
#define STU_NUM 3
struct Student{char name[20];float scores[COU_NUM];};
struct Student students[STU_NUM];
int main()
{
    for(int i=0;i<STU_NUM;i++)
    {
        double average=0.0;
        printf("请你输入第%d个学生的信息:\n",i+1);
        //精度小数只能影响printf，不能影响scanf，并且%.1f不规范
        if (scanf("%19s %f %f %f",
                  students[i].name,
                  &students[i].scores[0],
                  &students[i].scores[1],
                  &students[i].scores[2]) != 4) {
            fprintf(stderr, "输入格式错误。\n");
            return 1;
        }
        average=(students[i].scores[0]
                +students[i].scores[1]
                +students[i].scores[2])/COU_NUM;
        printf("%s同学的平均分是:%.1f\n",students[i].name,average);
    }
    for(int j=0;j<STU_NUM;j++)
    {
        printf("%s同学的各科成绩是%.1f %.1f %.1f\n",students[j].name,
            students[j].scores[0],
            students[j].scores[1],
            students[j].scores[2]
        );
    }
    return 0;
} 

/*
if (scanf("%19s %f %f %f",
          students[i].name,
          &students[i].scores[0],
          &students[i].scores[1],
          &students[i].scores[2]) != 4) {
    fprintf(stderr, "输入格式错误。\n");
    return 1;
}
最显著的作用可以简短总结为：
在输入学生信息时做输入校验，确保用户确实输入了 1 个字符串和 3 个浮点数。
如果输入数量不对，就立即报错并退出程序
避免后续使用未定义数据造成崩溃或错误结果。
防御性编程：帮你在源头拦截掉格式错误输入，保证程序运行安全。
*/
/*
/*
id 是一个变量，它存放的是值。
scanf 需要一个地址，才能把输入的值写到内存里。
所以要用 &id，取出变量的地址。
数组名 name 在表达式里，自动退化为指向第一个元素的指针。
所以 name 等价于 &name[0]。
也就是说，这里 name 已经是地址了，不需要再写 &
*/ 