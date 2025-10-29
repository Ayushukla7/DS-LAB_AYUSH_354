#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
int search(struct Node* head, int key) {
    int pos = 1;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}
int main() {
    struct Node* head = createNode(5);
    head->next = createNode(7);
    head->next->next = createNode(13);
    head->next->next->next = createNode(16);
    int key;
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    int result = search(head, key);
    if (result != -1) {
        printf("Element %d found at position %d\n", key, result);
    }
    else {
        printf("Element %d not found\n", key);
    }
    return 0;
}