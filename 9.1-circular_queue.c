#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
int front=-1,rear=-1,cqueue[SIZE];
void enqueue(int val){
    if(front==(rear+1)%SIZE){
        printf("queue is full");
    }
    else if(rear==-1){
        front=rear=0;
        cqueue[rear]=val;
    }
    else{
        rear=(rear+1)%SIZE;
        cqueue[rear]=val;
    }
}
void dequeue(){
    int val;
    if(front==-1) printf("queue empty");
    else if(front==rear){
        val=cqueue[front];
        front=rear=-1;
        printf("deleted element is %d",val);
    }
    else{
        val=cqueue[front];
        front=(front+1)%SIZE;
        printf("deleted element is %d",val);
    }
}
void display(){
    int i;
    if(front==-1) printf("queue empty");
    else{
        for(i=front;i!=rear;i=(i+1)%SIZE){
            printf("%d",cqueue[i]);
        }
        printf("%d",cqueue[i]);
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
