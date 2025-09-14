#include <stdio.h>
struct tagBike{int id;int distance;float discount;};
struct tagBike arrayBikes[10];
int readfile(struct tagBike a[])
{
    FILE *p=fopen("e:/shanghaigongchengjishu/Clearn/8.1/C_Real_Exam_Coding/filehandle/Bikes.txt","r");

    int n=0;
    while(n<10&&fscanf(p,"%d %d %f",&a[n].id,&a[n].distance,&a[n].discount)==3)n++;
    fclose(p);
    for(int i=0;i<n;i++)
    {
        printf("%d %d %.2f\n",a[i].id,a[i].distance,a[i].discount);
    }
    return n;
}
/* 比较函数：x<y 返回 -1，x==y 返回 0，x>y 返回 1 */
static int bike_cmp(const struct tagBike *x, const struct tagBike *y) {
    if (x->distance < y->distance) return -1;
    if (x->distance > y->distance) return  1;
    /* distance 相等时按 discount 升序 */
    if (x->discount < y->discount) return -1;
    if (x->discount > y->discount) return  1;
    return 0;
}
//[left, right) 这个区间始终表示“插入点可能在的范围”。
//每次二分操作就是排除掉一部分候选，直到只剩一个位置，那就是最终插入点
/* 二分插入排序（稳定） */
void binary_insertion(struct tagBike a[], int n) {
    for (int i = 1; i < n; i++) {
        struct tagBike key = a[i];
        int left = 0, right = i;
        while (left < right) {
            int mid = (left + right)/2;
            if (bike_cmp(&a[mid], &key) <= 0)  // a[mid] <= key，则插入点在右侧(不含mid)
                left = mid + 1;
            else                               // a[mid] > key，则插入点在左侧（含 mid）
                right = mid;
        }
        int pos = left;

        /* 整体右移一段 [pos..i-1]，空出 a[pos] */
        for (int j = i - 1; j >= pos; j--) a[j + 1] = a[j];

        /* 插入 */
        a[pos] = key;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d %.2f\n",a[i].id,a[i].distance,a[i].discount);
    }
}

int main(void)
{
    int n=readfile(arrayBikes);
    binary_insertion(arrayBikes,n);
    return 0;
}
/*我的理解：
原理是通过二分查找要找到第一个比key大的位置(pos),
查找最后会通过left来确定pos的位置，所以最终left要位于第一个比key大的位置，
要达到这个目的，必须在中间值比关键字小时，让left=mid+1，
相反如果，在中间值比关键字小时，使left=mid，那么left上的元素任然小于关键字，
无法推进到比关键字大的位置

AI:
1.我们要找的是第一个大于 key 的位置 pos（也就是“上界”/upper_bound）。

2.循环不变式选用区间 [left, right)：
若 a[mid] <= key，说明 mid 不可能是 pos，必须排除掉 mid，所以 left = mid + 1；
若 a[mid] > key，pos 在左半边（含 mid），所以 right = mid。
终止时 left == right，它就落在第一个 > key 的元素上，因此 pos = left。

3.如果你将“a[mid] <= key 时让 left = mid”，会有两个问题：
无法推进：当 mid == left 时，left 不变，区间不收缩，可能卡住；
语义错误：a[mid] <= key 已证 mid 不是 pos，却仍把它留在区间里。

*/