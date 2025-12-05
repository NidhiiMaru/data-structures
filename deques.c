#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
int front=-1,rear=-1,cqueue[SIZE];
void enqueue_rear(int val){
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
void dequeue_front(){
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
void enqueue_front(int val){
    if(front==(rear+1)%SIZE){
        printf("queue is full");
    }
    else if(front==-1){
        front=rear=0;
        cqueue[front]=val;
    }
    else{
        front=(front+(SIZE-1)%SIZE);
        cqueue[front]=val;
    }
}
void dequeue_rear(){
    int val;
    if(rear==-1) printf("queue empty");
    else if(front==rear){
        val=cqueue[rear];
        front=rear=-1;
        printf("deleted element is %d",val);
    }
    else{
        val=cqueue[rear];
        rear=(rear-1+SIZE)%SIZE;
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
        printf("1. Enqueue_rear 2. Dequeue_front 3. Display 4.enqueue_front 5.dequeue_rear 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue_rear(value);
                break;
            case 2:
                dequeue_front();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue_front(value);
                break;
            case 5:
                dequeue_rear();
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
