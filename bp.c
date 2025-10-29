#include <stdio.h>

int stack[100];
int top = -1;
int size;

void push(int x) {
	if (top == size - 1) {
		printf("Stack Overflow\n");
	} else {
		top++;
		stack[top] = x;
		printf("%d pushed\n", x);
	}
}

void pop() {
	if (top == -1) {
		printf("Stack Underflow\n");
	} else {
		printf("%d popped\n", stack[top]);
		top--;
	}
}

void display() {
	if (top == -1) {
		printf("Stack is empty\n");
	} else {
		printf("Stack elements: ");
		for (int i = top; i >= 0; i--) {
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}

int main() {
	int choice, value;
	printf("Enter stack size: ");
	if (scanf("%d", &size) != 1 || size <= 0 || size > 100) {
		printf("Invalid size. Using default size 100.\n");
		size = 100;
	}

	while (1) {
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) {
			// clear invalid input
			int c;
			while ((c = getchar()) != '\n' && c != EOF) { }
			printf("Invalid input. Please enter a number.\n");
			continue;
		}

		switch (choice) {
			case 1:
				printf("Enter value to push: ");
				if (scanf("%d", &value) == 1) {
					push(value);
				} else {
					int c;
					while ((c = getchar()) != '\n' && c != EOF) { }
					printf("Invalid value.\n");
				}
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default:
				printf("Invalid choice\n");
		}
	}

	return 0;
}