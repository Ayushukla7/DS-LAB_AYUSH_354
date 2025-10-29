#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* insertAtBeginning(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    return new_node;
}
struct Node* insertAtEnd(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL) {
        return new_node;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}
struct Node* insertAfter(struct Node* head, int key, int new_data) {
    struct Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: key %d not found\n", key);
        return head;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = current->next;
    current->next = new_node;
    return head;
}
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp->next != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
struct Node* deleteAfter(struct Node* head, int key) {
    if (head == NULL) return head;
    struct Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Error: Key not found or no node after key\n");
        return head;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
int main() {
    struct Node* head = NULL;
    int choice, data, key;
    printf("Menu\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert After a Key\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete After a Key\n");
    printf("7. Display List\n");
    printf("0. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAfter(head, key, data);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter key after which to delete: ");
                scanf("%d", &key);
                head = deleteAfter(head, key);
                break;
            case 7:
                displayList(head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);
    return 0;
}