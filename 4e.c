#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct Node* temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void display(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            insertTerm(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insertTerm(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            insertTerm(&result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}
struct Node* subtractPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            insertTerm(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insertTerm(&result, -p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            insertTerm(&result, p1->coeff - p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&result, -p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}
struct Node* multiplyPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    for (struct Node* ptr1 = p1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (struct Node* ptr2 = p2; ptr2 != NULL; ptr2 = ptr2->next) {
            int coeff = ptr1->coeff * ptr2->coeff;
            int pow = ptr1->pow + ptr2->pow;
            struct Node* temp = result;
            struct Node* prev = NULL;
            while (temp != NULL && temp->pow > pow) {
                prev = temp;
                temp = temp->next;
            }
            if (temp != NULL && temp->pow == pow) {
                temp->coeff += coeff;
            } else {
                struct Node* newNode = createNode(coeff, pow);
                if (prev == NULL) {
                    newNode->next = result;
                    result = newNode;
                } else {
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
            }
        }
    }
    return result;
}
struct Node* createPoly() {
    struct Node* poly = NULL;
    int n, coeff, pow;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertTerm(&poly, coeff, pow);
    }
    return poly;
}
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice;
    printf("Create Polynomial 1:\n");
    poly1 = createPoly();
    printf("\nCreate Polynomial 2:\n");
    poly2 = createPoly();
    printf("Menu\n");
    printf("1. Display Polynomials\n");
    printf("2. Add Polynomials\n");
    printf("3. Subtract Polynomials\n");
    printf("4. Multiply Polynomials\n");
    printf("5. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nPolynomial 1: ");
                display(poly1);
                printf("Polynomial 2: ");
                display(poly2);
                break;
            case 2:
                result = addPoly(poly1, poly2);
                printf("\nSum: ");
                display(result);
                break;
            case 3:
                result = subtractPoly(poly1, poly2);
                printf("\nDifference: ");
                display(result);
                break;
            case 4:
                result = multiplyPoly(poly1, poly2);
                printf("\nProduct: ");
                display(result);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}