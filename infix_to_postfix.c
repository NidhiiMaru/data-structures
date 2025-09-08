#include <stdio.h>
#include <stdlib.h>
#define MAX 100  
float stack[MAX];
int top = -1;
char infix[100], postfix[100];

void push(char val) {
    if (top == MAX - 1) {
        printf("\nStack Overflow\n");
    } else {
        top++;
        stack[top] = val;
    }
}

char pop() {
    if (top == -1) {
        printf("\nStack Empty\n");
        return -1; 
    } else {
        return stack[top--];
    }
}

int priority(char op) {
    if (op == '%') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}
void itp() {
    int i = 0, j = 0; 
    char x;

    while (infix[i] != '\0') { 
        x = infix[i]; 

        if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9')) {
            postfix[j] = x;
            j++;
        }
        else if (x == '(') { 
            push(x);
        }
        else if (x == ')') {
            while (top != -1 && stack[top] != '(') { 
                postfix[j++] = pop();
            }
            pop(); 
        }
        else {  // Operator
            while (top != -1 && priority(stack[top]) >= priority(x)) {
                postfix[j++] = pop();
            }
            push(x);
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    printf("Enter infix expression: ");
    scanf("%s", infix);
    itp();
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
