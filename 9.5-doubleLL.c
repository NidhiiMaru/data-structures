#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev, *next;
} *start = NULL;

/*------------------------------------
        CREATE DOUBLY LINKED LIST
  ------------------------------------*/
void create() {
    struct Node *newnode, *temp;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    start = NULL;

    for (i = 0; i < n; i++) {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;
        newnode->prev = NULL;

        if (start == NULL) {
            start = newnode;
            temp = start;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

/*------------------------------------
           DISPLAY FORWARD
  ------------------------------------*/
void display() {
    struct Node *temp = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/*------------------------------------
        DISPLAY IN REVERSE ORDER
  ------------------------------------*/
void reverse_display() {
    struct Node *temp = start;

    if (start == NULL) {
        printf("List empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/*------------------------------------
          COUNT / LENGTH
  ------------------------------------*/
int count() {
    int c = 0;
    struct Node *temp = start;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

/*------------------------------------
         INSERT BEFORE A VALUE
  ------------------------------------*/
void insert_before() {
    struct Node *newnode, *temp;
    int x;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to insert: ");
    scanf("%d", &newnode->data);

    printf("Insert before value: ");
    scanf("%d", &x);

    temp = start;

    while (temp!=NULL &&temp->data!= x){
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL){
        temp->prev->next = newnode;
    }
    else{
        start = newnode;
    }
    temp->prev = newnode;
}

/*------------------------------------
         INSERT AFTER A VALUE
  ------------------------------------*/
void insert_after() {
    struct Node *newnode, *temp;
    int x;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to insert: ");
    scanf("%d", &newnode->data);

    printf("Insert after value: ");
    scanf("%d", &x);

    temp = start;

    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    newnode->prev = temp;
    newnode->next = temp->next;

    if (temp->next != NULL){
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

/*------------------------------------
        INSERT AT POSITION
  ------------------------------------*/
void insert_at_position() {
    int pos, i, n = count();
    struct Node *newnode, *temp;

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1) {
        newnode->next = start;
        newnode->prev = NULL;

        if (start != NULL){
            start->prev = newnode;
        }
        start = newnode;
        return;
    }

    temp = start;
    for (i = 1; i < pos - 1; i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL){
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

/*------------------------------------
              DELETE A NODE
  ------------------------------------*/
void delete_node() {
    int val;
    struct Node *temp = start;

    printf("Enter value to delete: ");
    scanf("%d", &val);

    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    if (temp == start) {
        start = temp->next;
        if (start != NULL)
            start->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node deleted\n");
}

/*------------------------------------
                MAIN MENU
  ------------------------------------*/
int main() {
    int choice;

    while (1) {
        printf("\nMENU:\n"
               "1. Create\n"
               "2. Display Forward\n"
               "3. Display Reverse\n"
               "4. Insert Before\n"
               "5. Insert After\n"
               "6. Insert at Position\n"
               "7. Delete\n"
               "8. Count Nodes\n"
               "9. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1: create(); break;
        case 2: display(); break;
        case 3: reverse_display(); break;
        case 4: insert_before(); break;
        case 5: insert_after(); break;
        case 6: insert_at_position(); break;
        case 7: delete_node(); break;
        case 8: printf("Length = %d\n", count()); break;
        case 9: exit(0);
        default: printf("Invalid choice\n");
        }
    }
}
