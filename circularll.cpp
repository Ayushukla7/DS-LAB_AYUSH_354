#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node* getNode() {
    struct node* q = (struct node*)malloc(sizeof(struct node));
    return q;
}

// Insert at beginning
struct node* InsertAtBegin(struct node* start, int value) {
    struct node* newnode = getNode();
    newnode->data = value;
    if (start == NULL) {
        start = newnode;
        newnode->next = start;   // self loop
    } else {
        struct node* temp = start;
        while (temp->next != start) {  // last node tak jao
            temp = temp->next;
        }
        newnode->next = start;
        temp->next = newnode;
        start = newnode;
    }
    return start;
}

// Traversal (circular)
void Traversal(struct node* start) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    struct node* p = start;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != start);
    cout << endl;
}

// Insert after a given value
struct node* InsertAfter(struct node* start, int value, int pos) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return start;
    }
    struct node* temp = start;
    do {
        if (temp->data == pos) {
            struct node* p = getNode();
            p->data = value;
            p->next = temp->next;
            temp->next = p;
            return start;
        }
        temp = temp->next;
    } while (temp != start);

    cout << "Position not found!" << endl;
    return start;
}

// Insert at end
struct node* InsertAtEnd(struct node* start, int value) {
    struct node* newnode = getNode();
    newnode->data = value;
    if (start == NULL) {
        start = newnode;
        newnode->next = start;
    } else {
        struct node* temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = start;
    }
    return start;
}

int main() {
    int ch;
    do {
        cout << "\nenter your choice\n";
        cout << "1. Traversal\n";
        cout << "2. Insertion from the beginning\n";
        cout << "3. Insertion after a node\n";
        cout << "4. Insertion at the end\n";
        cout << "0. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                Traversal(start);
                break;
            case 2: {
                int value;
                cout << "enter the value to be inserted: ";
                cin >> value;
                start = InsertAtBegin(start, value);
                break;
            }
            case 3: {
                int value, pos;
                cout << "enter the value to be inserted: ";
                cin >> value;
                cout << "enter the node value after which to insert: ";
                cin >> pos;
                start = InsertAfter(start, value, pos);
                break;
            }
            case 4: {
                int value;
                cout << "enter the value to be inserted: ";
                cin >> value;
                start = InsertAtEnd(start, value);
                break;
            }
            case 0:
                cout << "Exit\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (ch != 0);
    return 0;
}
