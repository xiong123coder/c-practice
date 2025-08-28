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
