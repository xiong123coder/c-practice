#include<stdio.h>
int main()
{
    int ages;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&ages);
        int key=ages>=100?10:ages/10;
        int sub=0;
        switch(key)
        {
            case 6:sub=610;break;
            case 7:sub=720;break;
            case 8:sub=830;break;
            case 9:sub=940;break;
            case 10:sub=1100;break;
            default:sub=(key<6)?0:0;
        }
        printf("年龄：%d,补贴金：%d\n",ages,sub);
    }
    return 0;
}