#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 64

typedef struct {
    char name[MAX_NAME];
    int  chi, math, eng;
    int  sum;   // chi + math + eng
} Student;

int main(void) {
    int N;
    if (scanf("%d", &N) != 1 || N <= 0) return 0;

    Student *a = (Student*)malloc(sizeof(Student) * N);
    if (!a) return 0;

    for (int i = 0; i < N; ++i) {
        if (scanf("%63s %d %d %d", a[i].name, &a[i].chi, &a[i].math, &a[i].eng) != 4) {
            free(a);
            return 0;
        }
        a[i].sum = a[i].chi + a[i].math + a[i].eng;
    }

    // 二分插入排序：按 sum 降序；相等时保持先来先留（稳定）
    for (int i = 1; i < N; ++i) {
        Student key = a[i];
        int low = 0, high = i;
        // 找到“第一个 sum < key.sum”的位置
        // 注意：相等时走到右侧，从而插到相等块后面 -> 稳定
        while (low < high) {
            int mid = (low + high) >> 1;
            if (a[mid].sum < key.sum) high = mid;
            else                      low  = mid + 1;
        }
        int pos = low; // 插入位置
        // 挪动区间 [pos, i-1] 右移一位
        for (int j = i; j > pos; --j) a[j] = a[j-1];
        a[pos] = key;
    }
    // 最厉害的学生在 a[0]（稳定排序：并列时保留最靠前）
    printf("%s %d %d %d\n", a[0].name, a[0].chi, a[0].math, a[0].eng);
    free(a);
    return 0;
}
// 输入格式 第一行输入一个正整数 N，表示学生个数。 第二行开始，往下 N 行，对于每一行首先先输入一个字符串表示学生姓名，
//再输入三个自然数表示语文、数学、英语的成绩。均用空格相隔。 输出格式 输出最厉害的学生。
//如果总分相同，则输出最靠前的那个 输入 3 senpai 114 51 4 lxl 114 10 23 fafa 51 42 60 输出 senpai 114 51 4