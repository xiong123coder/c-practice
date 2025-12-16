// 能独立写出 append 函数（尾插）
// 能写 print 函数（遍历链表）
// 能写 create_node 函数
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int id;
    float price;
    float score;
}Product;
typedef struct Node{//先苦后甜
    Product p;
    struct Node* next;
}Node;
Node* create(Product product){
    Node* node=(Node*)malloc(sizeof(Node));
    node->p=product;
    node->next=NULL;
    return node;
}
void append(Node** head,Node* node){//尾插
    if(*head==NULL){
        *head=node;
        return;
    }
    Node* cur=*head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=node;
}
void read(Node** head){
    FILE* f=fopen("data.txt","r");
    if(f==NULL)return;
    Product p;
    int count=0;
    while(count<10&&(fscanf(f,"%d %f %f",&p.id,&p.price,&p.score)==3))
    {
        append(head,create(p));
        count++;
    }    
}
void printff(Node** head){
    if(*head==NULL){
        printf("链表为空！\n");
        return ;
    }
    Node*cur=*head;
    while(cur!=NULL){
        printf("%d %.1f %.1f/n",cur->p.id,cur->p.price,cur->p.score);
    }
}
int main()
{
    Node* head=NULL;
    read(&head);
    printff(&head);
    return 0;
}