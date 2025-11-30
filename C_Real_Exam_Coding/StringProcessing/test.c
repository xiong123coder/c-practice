#include <stdio.h>

int main() {
    char *p1 = "hello";
    char *p2 = "hello";

    printf("%p %p\n", p1, p2);
    printf("%s %s\n", p1 + 2, p2 + 3);

    return 0;
}
