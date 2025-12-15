#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left, *right;
};

/* Stack for tree nodes */
struct Node* stack[50];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

/* Create a new node */
struct Node* createNode(char ch) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = ch;
    newnode->left = newnode->right = NULL;
    return newnode;
}

/* Construct expression tree from postfix */
struct Node* constructTree(char postfix[]) {
    int i;
    struct Node *op1, *op2, *temp;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            push(createNode(postfix[i]));
        } else {
            temp = createNode(postfix[i]);
            op2 = pop();
            op1 = pop();
            temp->left = op1;
            temp->right = op2;
            push(temp);
        }
    }
    return pop();
}

/* Inorder traversal */
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

/* Evaluate expression tree */
int evaluate(struct Node* root) {
    int l, r;

    if (root->left == NULL && root->right == NULL)
        return root->data - '0';

    l = evaluate(root->left);
    r = evaluate(root->right);

    switch (root->data) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        case '/': return l / r;
    }
    return 0;
}

int main() {
    char postfix[50];
    struct Node* root;

    printf("Enter postfix expression (digits only): ");
    scanf("%s", postfix);

    root = constructTree(postfix);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nEvaluated result: %d", evaluate(root));
    return 0;
}
