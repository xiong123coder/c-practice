// 能独立写出 append 函数（尾插）
// 能写 print 函数（遍历链表）
// 能写 create_node 函数

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    float price;
    float score;
} Product;
typedef struct Node
{
    Product product;
    struct Node *next;
} Node;

Node *create(Product p)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->product = p;
    node->next = NULL;
    return node;
}
// 创建节点时必须使用指针：
// Node *node = malloc(sizeof(Node));
// 因为：
// 节点必须存活在堆上（生命周期长）
// 链表依靠指针连接节点
// malloc 返回的是地址，所以必须用指针接
// 栈变量（Node node）退出作用域就会被销毁，链表必崩
void append(Node **head, Node *node)
{
    if (*head == NULL)
    {
        *head = node;
        return;
    }
    Node *cur = *head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = node;
}
void read(Node **head)
{
    FILE *f = fopen("data.txt", "r");
    if (f == NULL)
        return;
    Product p;
    int count = 0;
    while (count < 10 && (fscanf(f,"%d%f%f", &p.id, &p.price, &p.score) == 3))
    {
        append(head, create(p));
        count++;
    }
    fclose(f);
}
void printff(Node *head)
{
    Node *cur = head;
    while (cur->next != NULL)
    {
        printf("%d %.1f %.1f\n",
               cur->product.id,
               cur->product.price,
               cur->product.score);
        cur = cur->next;
    }
}
int main()
{   
    Node *head = NULL;
     // 调用独立的文件读取函数
    read(&head);

    printf("链表内容如下：\n");
    printff(head);
    return 0;
}