/*有一个升序排列的包含 10 个整数的数组，编写程序实现以下功能：
（1）输入一个整数，使用折半查找算法判断该整数是否在数组中；
（2）若该整数在数组中，输出该整数在数组中的下标（下标从 0 开始）；
（3）若该整数不在数组中，将该整数插入到数组中合适的位置，使数组仍然保持升序，并
输出插入后的数组。
*/
#include <stdio.h>
int half(int a[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int a[11] = {3, 5, 6, 8, 9, 11, 12, 16, 19, 22};
    int target;
    scanf("%d", &target);
    int result = half(a, 10, target);
    if (result != -1)
    {
        printf("%d", result);
    }
    else
    {
        int index = 10;
        for (int i = 0; i < 10; i++)
        {
            if (a[i] > target)
            {
                index = i;
                break;
            }
        }

        for (int j = 10; j > index; j++)
        {
            a[j] = a[j - 1];
        }

        a[index] = target;

        printf("插入后的数组:");
        for (int k = 0; k < 11; k++)
        {
            printf("%d ", a[k]);
        }
    }
    return 0;
}
/*更正后总结错误：
数组扩容成 11 个，避免越界。
插入位置 index 初始化成 10（默认插到末尾）。
元素移动反向执行，从后往前。
打印和注释更清晰。
*/