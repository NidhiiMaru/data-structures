#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue() {
    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);
    struct Node* nn = (struct Node*) malloc(sizeof(struct Node));
    nn->data = value;
    nn->next = NULL;
    if (front == NULL) {
        front = rear = nn;
    } else {
        rear->next = nn;
        rear = nn;
    }
}
int dequeue() {
    if (front == NULL) {
        printf("Queue underflow! (Empty queue)\n");
        return -9999; 
    }
    struct Node* temp = front;
    int value = temp->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    return value;
}
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void main() {
    int ch, val;
    while (ch!=-1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("-1. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            enqueue();
            break;
        case 2:
            val = dequeue();
            printf("Dequeued value: %d\n", val);
            break;
        case 3:
            display();
            break;
        case -1:
            printf("Exiting program...\n");
        default:
            printf("Invalid choice\n");
        }
    }
}

