
#include <stdio.h>  
#include <ctype.h>  
#include <stdlib.h> 
#define MAX 100 
 int stack[MAX];  
int top = -1; 
void push(int x){ 
 stack[++top] = x; } 
int pop() {  
return stack[top--]; } 
int main() {  
char postfix[100];  
printf("Enter a postfix expression: ");  
scanf("%s", postfix); 
for (int i = 0; postfix[i] != '\0'; i++) { 
char ch = postfix[i]; 
 
    if (isdigit(ch)) { 
        push(ch - '0');} 
    else { 
        int val2 = pop(); 
        int val1 = pop(); 
        int result; 
 
        switch (ch) { 
            case '+': result = val1 + val2; break; 
            case '-': result = val1 - val2; break; 
            case '*': result = val1 * val2; break; 
            case '/': result = val1 / val2; break; 
            default: 
                printf("Invalid operator encountered\n"); 
                exit(1); 
        } 
        push(result); 
    } 
} 
 
printf("Result = %d\n", pop()); 
return 0;
}