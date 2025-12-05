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

void insert_at_position() {
    int pos, i = 1;
    struct Node *newnode, *p;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    if (pos == 1) { // insert at beginning
        newnode->next = start;
        start = newnode;
        return;
    }

    temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
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
void search() {
    int val, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &val);
    temp = start;

    while (temp != NULL) {
        if (temp->data == val) {
            printf("Value %d found at position %d\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value not found\n");
}

void main(){
    int choice=0;
    while(choice!=6){
        printf("enter 1:create 2:display 3:insert 4:search 5:delete 6:exit ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            create();
            break;
            case 2:
            display();
            break;
            case 3:
            insert_at_position();
            break;
            case 4:
            search();
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
