#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void decToBinary(int n) {
    if (n == 0) {   // special case
        printf("0");
        return;
    }

    while (n > 0) {
        push(n % 2);   // push remainder
        n = n / 2;
    }

    // popping prints binary in correct order
    while (top != -1) {
        printf("%d", pop());
    }
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Binary: ");
    decToBinary(num);

    return 0;
}
