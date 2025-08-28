#include<stdio.h>
int main()
{
    int scores;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&scores);
        int key=(scores<0||scores>100)?-1:(scores==100)?10:(scores>=60)?scores/10:5;
        char grade='?';  
        switch(key)
        {
            case 10:
            case 9:grade='A';break;
            case 8:grade='B';break;
            case 7:grade='C';break;
            case 6:grade='D';break;
            case 5:grade='E';break;
            case -1:
                printf("无效输入\n");continue; 
        }
        printf("学生成绩:%d,评级:%c\n",scores,grade);
    }
    return 0;
}
/*
你在成绩评级代码中有了两点收获：
三目运算符的嵌套：通过 (scores<0||scores>100)?-1:(scores==100)?10:(scores>=60)?scores/10:5; 把 switch 的输入范围控制住，避免了非法分支。
continue 的用法：在检测到无效输入时，直接 continue 跳过本轮循环，避免多余的输出。
整体来说，你学到的不只是语法点，而是“用逻辑预处理输入，保证后面结构更清晰”，这比单纯会写 switch 更进了一步。
*/