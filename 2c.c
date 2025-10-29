#include <stdio.h> 
#include <string.h> 
char stack[100]; 
int top = -1; 
void push(char c) { 
top++; 
stack[top] = c; 
} 
char pop() { 
char c = stack[top]; 
top--; 
return c; 
} 
int isMatching(char open, char close) { 
if (open == '(' && close == ')') return 1; 
if (open == '[' && close == ']') return 1; 
if (open == '{' && close == '}') return 1; 
return 0; 
} 
int main() { 
char expr[100]; 
int i; 
printf("Enter expression: "); 
    scanf("%s", expr); 
  
    for (i = 0; i < strlen(expr); i++) { 
        char ch = expr[i]; 
        if (ch == '(' || ch == '[' || ch == '{') { 
            push(ch); 
        } 
        else if (ch == ')' || ch == ']' || ch == '}') { 
            if (top == -1 || !isMatching(stack[top], ch)) { 
                printf("Not Balanced\n"); 
                return 0; 
            } 
            pop(); 
        } 
    } 
if (top == -1) 
        printf("Balanced\n"); 
    else 
        printf("Not Balanced\n"); 
 return 0; 
}