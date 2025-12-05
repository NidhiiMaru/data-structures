#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function call frame
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop function call frame
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Simulate recursive factorial using stack
int factorial_simulated(int n) {
    int result = 1;

    // Simulate recursive calls by pushing onto stack
    while (n > 0) {
        push(n);
        n--;
    }

    // Pop like returning from recursive calls
    while (top != -1) {
        result *= pop();
    }

    return result;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int ans = factorial_simulated(n);

    printf("Factorial = %d\n", ans);

    return 0;
}
