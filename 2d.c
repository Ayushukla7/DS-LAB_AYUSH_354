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
int precedence(char c) { 
if (c == '^') return 3; 
if (c == '*' || c == '/') return 2; 
if (c == '+' || c == '-') return 1; 
return 0; 
} 
int main() { 
char infix[100], postfix[100]; 
int i, j = 0; 
char ch; 
printf("Enter infix expression: "); 
    scanf("%s", infix); 
  
    for (i = 0; i < strlen(infix); i++) { 
        ch = infix[i]; 
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) { 
            postfix[j++] = ch; 
        } 
        else if (ch == '(') { 
            push(ch); 
        } 
        else if (ch == ')') { 
            while (stack[top] != '(') { 
                postfix[j++] = pop(); 
            } 
            pop(); 
        } 
        else { 
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) { 
                postfix[j++] = pop(); 
            } 
            push(ch);   } 
    }
   while (top != -1) { 
        postfix[j++] = pop(); 
    } 
  postfix[j] = '\0'; 
printf("Postfix Expression: %s\n", postfix); 
return 0; 
}