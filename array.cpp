#include <iostream>
#include <cstdlib> 
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node*& head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "Linked List: ";
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // 3 nodes insert kar rahe hain
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);

    // Display linked list
    displayList(head);

    // Memory free karna
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
