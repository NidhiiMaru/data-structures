#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*start,*temp;

void create(){
    struct Node *newnode;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    printf("enter data ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(start==NULL){
        start=newnode;
        temp=start;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
void display(){
    temp=start;
    if(start==NULL){
        printf("no elements added");
    }
    else{
        printf("elements: ");
        while(temp->next!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\t",temp->data);
        printf("\n");
    }
}

void insert_before(){
    struct Node *p,*newnode;
    int val,data;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    printf("enter data");
    scanf("%d",&newnode->data);
    printf("value before which you want to insert");
    scanf("%d",&val);
    temp=start;
    p=start;
    while(temp->data!=val){
            p=temp;
            temp=temp->next;
        }
    if(temp==start){
        newnode->next=start;
        start=newnode;
    }
    else{
        p->next=newnode;
        newnode->next=temp;
    }
}
void insert_after(){
    struct Node *newnode;
    int val,data;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    printf("enter data");
    scanf("%d",&newnode->data);
    printf("value after which you want to insert");
    scanf("%d",&val);
    temp=start;
    while(temp->data!=val){
            temp=temp->next;
        }
  
        newnode->next=temp->next;
        temp->next=newnode;
}

void delete_node(){
    int val;
    printf("enter val to delete");
    scanf("%d",&val);
    struct Node *p;
    temp=p=start;
    while(temp!=NULL && temp->data!=val){
            p=temp;
            temp=temp->next;
        }
    if(temp==start){
      start=temp->next;
    }
    else if(temp==NULL) return;
    else{
        p->next=temp->next;
    }
    free(temp);
}
void main(){
    int choice=0;
    while(choice!=6){
        printf("enter 1:create 2:display 3:insert before 4:insert after 5:delete 6:exit ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            create();
            break;
            case 2:
            display();
            break;
            case 3:
            insert_before();
            break;
            case 4:
            insert_after();
            break;
            case 5:
            delete_node();
            break;
            case 6:
            exit(0);
            break;
        }
    }
}
