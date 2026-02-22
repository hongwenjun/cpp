#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
  int data;           // 节点存储的数据
  struct Node *next;  // 指向下一个节点的指针
} Node;

/**
 * 向链表中插入新节点
 * @param head: 指向链表头节点的指针的地址
 * @param data: 要插入的新节点的数据
 */
void insert(Node **head, int data) {
  // 创建新节点并分配内存
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  // 如果链表为空，则将新节点设为头节点
  if (*head == NULL) {
    *head = newNode;
  } else {
    // 遍历链表找到最后一个节点，并将新节点连接到末尾
    Node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

/**
 * 打印链表中的所有节点数据
 * @param head: 链表的头节点指针
 */
void display(Node *head) {
  // 遍历链表并打印每个节点的数据
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

/**
 * 主函数：测试链表的插入和显示功能
 */
int main() {
  Node *head = NULL;  // 初始化链表头节点为空

  // 插入三个节点到链表中
  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);

  // 显示链表内容
  display(head);

  return 0;
}