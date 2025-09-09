#include <stdio.h>
#include <conio.h>
#define MAX 10  // Maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    int num;
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &num);

    if(rear == MAX - 1) {
        printf("\n OVERFLOW");
    }
    else if(front == -1 && rear == -1) {  // Queue empty initially
        front = rear = 0;
        queue[rear] = num;
    }
    else {
        rear++;
        queue[rear] = num;
    }
}

int dequeue() {
    int val;
    if(front == -1 || front > rear) {
        printf("UNDERFLOW\n");
        return -1;
    }
    else {
        val = queue[front];
        front++;
        if(front > rear) {  // Reset when queue becomes empty
            front = rear = -1;
        }
        return val;
    }
}

int peek() {
    if(front == -1 || front > rear) {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else {
        return queue[front];
    }
}

void display() {
    int i;
    if(front == -1 || front > rear) {
        printf("\n QUEUE IS EMPTY");
    }
    else {
        printf("\n Queue elements are: ");
        for(i = front; i <= rear; i++) {
            printf("\t %d", queue[i]);
        }
    }
}


int main() {
    int option, val;
    do {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                enqueue();
                break;
            case 2:
                val = dequeue();
                if (val != -1)
                    printf("The number deleted is : %d", val);
                break;
            case 3:
                val = peek();
                if (val != -1)
                    printf("The first value in queue is : %d\n", val);
                break;
            case 4:
                display();
                break;
        }
    } while(option != 5);

    getch();
    return 0;
}

