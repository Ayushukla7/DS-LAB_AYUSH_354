#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
void printList(struct Node* head) {
    while (head->next != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("%d\n",head->data);
}
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
int main() {
    struct Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("Original Linked List:\n");
    printList(head);
    head = reverse(head);
    printf("Reversed Linked List:\n");
    printList(head);
    return 0;
}