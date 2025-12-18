#include <stdio.h>
#include <stdlib.h>

// 第一小题：声明商品信息结构体和链表节点
typedef struct Product{
    int id;
    float price;
    float score; 
}Product;

typedef struct Node{
    Product p;
    struct Node* next; 
}Node;
// 创建新节点
Node* create(Product product){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->p=product;
    new_node->next=NULL;
    return new_node;
}
// 尾插法添加节点（只使用 head）
void append(Node**head,Node* node){
    Node*cur=*head;
    if(cur==NULL){
        *head=node;
    }else{
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=node;
    }
}
// 第二小题：从文件读取数据并存入链表（假设文件为 data.txt）
void readfromfile(Node**head){
    FILE*f=fopen("data.txt","r");
    if(f==NULL){
        printf("文件打开失败！\n");
        return;
    }
    Product product;
    printf("====从文件中读取的数据:====\n");
    while(fscanf(f,"%d %f %f",&product.id,&product.price,&product.score)==3)
    {   
        printf("%d %.2f %.2f\n",product.id,product.price,product.score);
        Node*node=create(product);
        append(head,node);
        
    }
    fclose(f);
}
// 第三小题：按价格进行选择排序
void select(Node*head){ 
    if(head==NULL||head->next==NULL){
        return;
    }
    Node* cur=head;
    while(cur->next!=NULL){
        Node*min=cur;
        Node*search=cur->next;
        while(search!=NULL){
            if(search->p.price<min->p.price){
                min=search;            
            }
            search = search->next;
        }
        if(min!=cur){
            Product temp=min->p;
            min->p=cur->p;
            cur->p=temp;
        }
        cur=cur->next;
    }

}

// 输出链表内容
void printList(Node* head) {
    if (head == NULL) {
        printf("链表为空！\n");
        return;
    }
    Node* cur = head;
    printf("\n链表中的数据:\n");
    while (cur != NULL) {
        printf("%d %.2f %.2f\n", cur->p.id, cur->p.price, cur->p.score);
        cur = cur->next;
    }
}

// 释放链表内存
void freelink(Node*head){
    Node*cur=head;
    while(cur!=NULL){
        Node*temp=cur;
        cur=cur->next;  
        free(temp);   
    }
}
// 第五小题：main 函数
int main() {
    Node* head = NULL;

    // 第二小题：读取文件
    readfromfile(&head);

    // 第三小题：排序
    printf("\n=== 按价格排序后 ===\n");
    select(head);
    printList(head);

    // 释放内存
    freelink(head);

    return 0;
}



