#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name[26];
    int score[2];
    float avg;
}Singer;

Singer *rf(int*count)
{
    Singer *singers=(Singer*)malloc(56*sizeof(Singer));
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL)//错
    {
        perror("文件打开失败！");
        return NULL;
    }
    *count = 0;
    while (*count < 56 && fscanf(file, "%26s %d %d", singers[*count].name,
                                       &singers[*count].score[0],
                                       &singers[*count].score[1]) == 3)//错，一开始用||而且fscanf不需要\n
    {
        
        singers[*count].avg = (singers[*count].score[0]
             + singers[*count].score[1])/2.0f;//错
        printf("歌手：%s    评分：%d %d    平均分：%.2f\n", singers[*count].name,
               singers[*count].score[0],
               singers[*count].score[1],
               singers[*count].avg);
               (*count)++;//错
    }
    return singers;//错  更正：C函数只能返回一个值
}

void sort(Singer*singers,int n)
{
    for(int i=0;i<n;i++)
    {
        int cur_max=i;
        for(int j=i+1;j<n-1;j++)
        {
            if(singers[j].avg>singers[cur_max].avg)
            {
                cur_max=j;
            }
        }
        Singer temp=singers[cur_max];
        singers[cur_max]=singers[i];
        singers[i]=temp;
    }
    printf("恭喜%s获得第一名,平均分是：%.2f",singers[0].name,singers[0].avg);
}
int main()
{   
    int n;
    Singer*singers=rf(&n);
    if(singers!=NULL)
    {
        sort(singers,n);
        free(singers);
    }    
    return 0;
}