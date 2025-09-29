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

struct node* InsertAtBegin(struct node* start, int value) {
    struct node* newnode = getNode();
    newnode->data = value;
    newnode->next = start;
    start = newnode;
    return start;
}

void Traversal(struct node* start) {
    struct node* p = start;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

struct node* InsertAfter(struct node* start, int value, int pos) {
    struct node* temp = start;
    while (temp != NULL && temp->data != pos) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position not found!" << endl;
        return start;
    }
    struct node* p = getNode();
    p->data = value;
    p->next = temp->next;
    temp->next = p;
    return start;
}
int CountNodes(struct node* start) {
    int count = 0;
    struct node* temp = start;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void Search(struct node* start, int key) {
    struct node* temp = start;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element " << key << " not found!" << endl;
}

int main() {
    int ch;
    do {
        cout << "\nenter your choice\n";
        cout << "1. Traversal\n";
        cout << "2. Insertion from the beginning\n";
        cout << "3. Insertion after a node\n";
        cout << "4. Count nodes\n";
        cout << "5. Search an element\n";
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
                cout << "enter the position after which to insert: ";
                cin >> pos;
                start = InsertAfter(start, value, pos);
                break;
            }
            case 4: {
                cout << "Total nodes = " << CountNodes(start) << endl;
                break;
            }
            case 5: {
                int key;
                cout << "Enter the element to search: ";
                cin >> key;
                Search(start, key);
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
