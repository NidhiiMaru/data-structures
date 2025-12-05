#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*top;
void push(int data){
    struct Node *newnode;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("stack full");
    }
    else{
        newnode->data=data;
        if(top==NULL){
            top=newnode;
        }
        else{
            newnode->next=top;
            top=newnode;
        }
    }
}
int pop(){
    struct Node *temp;
    int x;
    if(top==NULL){
        printf("stack empty");
        return -1;
    }
    else{
        x=top->data;
        temp=top;
        top=top->next;
        free(temp);
        return x;
    }
}

void display(){
    struct Node *temp=top;
    if(top==NULL){
        printf("stack empty");
    }
    else{
        while(temp->next!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
        printf("\n");
    }
}

void main(){
    int choice,data,p;
    while(choice!=4){
        printf("enter 1:push 2:pop 3:display 4:exit ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enter data ");
            scanf("%d",&data);
            push(data);
            break;
            case 2:p=pop();
            printf("%d is popped ",p);
            break;
            case 3:display();
            break;
            case 4:
            exit(0);
            break;
        }
    }
}
