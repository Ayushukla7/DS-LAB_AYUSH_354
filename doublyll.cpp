#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Insert at head
void insertAtHead(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head != nullptr)
        head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert at tail
void insertAtTail(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after a given value
void insertAfter(Node* head, int target, int value) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Target not found.\n";
        return;
    }
    Node* newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete head node
void deleteHead(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
}

// Delete tail node
void deleteTail(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    if (temp->next == nullptr) { // Only one node
        delete head;
        head = nullptr;
        return;
    }
    while (temp->next != nullptr)
        temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

// Delete a node with a specific value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;
    Node* temp = head;

    while (temp != nullptr && temp->data != value)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Value not found.\n";
        return;
    }

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}

// Display forward
void displayForward(Node* head) {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display backward
void displayBackward(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    cout << "Backward: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Main menu
int main() {
    Node* head = nullptr;
    int choice, value, target;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Head\n2. Insert at Tail\n3. Insert After Node\n";
        cout << "4. Delete Head\n5. Delete Tail\n6. Delete Node\n";
        cout << "7. Display Forward\n8. Display Backward\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> value;
                insertAtHead(head, value);
                break;
            case 2:
                cout << "Enter value: "; cin >> value;
                insertAtTail(head, value);
                break;
            case 3:
                cout << "Enter target value: "; cin >> target;
                cout << "Enter value to insert: "; cin >> value;
                insertAfter(head, target, value);
                break;
            case 4:
                deleteHead(head);
                break;
            case 5:
                deleteTail(head);
                break;
            case 6:
                cout << "Enter value to delete: "; cin >> value;
                deleteNode(head, value);
                break;
            case 7:
                displayForward(head);
                break;
            case 8:
                displayBackward(head);
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
