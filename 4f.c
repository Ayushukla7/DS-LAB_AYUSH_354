#include <stdio.h>  
#include <stdlib.h> 
struct Node {
    int data;
    struct Node* next;
}; 
struct Node* last = NULL; 
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->data = value; 
    if (last == NULL) { 
        last = newNode; 
        last->next = last; 
    }
    else { 
        newNode->next = last->next; 
        last->next = newNode; 
    } 
} 
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; 
    if (last == NULL) { 
        last = newNode; 
        last->next = last;
    }
    else { 
        newNode->next = last->next; 
        last->next = newNode; 
        last = newNode;
    } 
}
void deleteAtBeginning() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = last->next; 
    if (last->next == last) { 
        last = NULL; 
    } else { 
        last->next = temp->next; 
    } 
    free(temp); 
} 
void deleteAtEnd() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = last->next; 
    if (last->next == last) { 
        free(last); 
        last = NULL;
    } else { 
        while (temp->next != last) {
            temp = temp->next; 
            temp->next = last->next; 
            free(last); 
            last = temp;
        }
    } 
 } 
void display() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    } 
    struct Node* temp = last->next; 
    printf("Circular List: "); 
    do { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } while (temp != last->next); 
    printf("\n"); 
 } 
int main() {  
    int choice, value;
    printf("\n1. Insert at Beginning\n2. Insert at End\n3. Delete at Beginning\n4. Delete at End\n5. Display\n6. Exit\n");
    while (1) { 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                 printf("Enter value: "); 
                 scanf("%d", &value); 
                 insertAtBeginning(value); 
                 break;
            case 2: 
                 printf("Enter value: "); 
                 scanf("%d", &value); 
                 insertAtEnd(value); 
                 break;
            case 3: 
                 deleteAtBeginning(); 
                 break;
            case 4: 
                 deleteAtEnd(); 
                 break;
            case 5: 
                 display(); 
                 break;
            case 6: 
                 return 0;
            default:
                 printf("Invalid choice\n");
        }
    } 
 }