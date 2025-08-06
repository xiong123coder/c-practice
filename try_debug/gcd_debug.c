#include <stdio.h>

int gcd(int b, int a, int depth) {
    // 构造缩进前缀，就是递归深度显示
    for(int i = 0; i < depth; i++) putchar(' ');
    // 入口状态
    printf("-> gcd(b=%d, a=%d)\n", b, a);

    if (a == 0) {// 当 a 为 0 时，gcd 是 b
        for(int i = 0; i < depth; i++) putchar(' ');
        printf("   终于找到了,return %d\n", b);
        return b;
    } else {
        for(int i = 0; i < depth; i++) putchar(' ');
        printf("   compute next: gcd(b=%d, a=%d)\n",a,b%a);
        int result = gcd(a, b%a, depth + 2);
        for(int i = 0; i < depth; i++) putchar(' ');
        printf("<- gcd(b=%d, a=%d) returns %d\n", a, b%a, result);
        return result;
    }
}
int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 1;
    printf("Computing gcd(%d, %d):\n", a, b);
    int g = gcd(a, b, 0);
    printf("Result: %d\n", g);
    return 0;
}
// | 点位      | 像什么      | 关键语                    |
// | -----     | -------- | --------------------------- |
// | 函数入口  | 摄像头盯着门口  | `>>> 入口: gcd(a, b)`  |
// | 参数传递  | 快递地址写错了？ | `... compute next:`   |
// | 基准情形  | 是否找到出口？  | `return结果是`      |
// | 返回值追踪 | 快递是否被签收？| `<- 返回值: gcd(...) = result` |
