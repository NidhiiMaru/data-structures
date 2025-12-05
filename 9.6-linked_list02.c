#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *start, *temp;

// ----------------------------------
// CREATE (your version, unchanged)
// ----------------------------------
void create() {
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter data ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
        temp = start;
    } else {
        temp->next = newnode;
        temp = newnode;
    }
}

// ----------------------------------
// DISPLAY FORWARD
// ----------------------------------
void display() {
    temp = start;
    if (start == NULL) {
        printf("no elements added\n");
    } else {
        printf("elements: ");
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// ----------------------------------
// REVERSE DISPLAY (using recursion)
// ----------------------------------
void reverse_recursive(struct Node *node) {
    if (node == NULL) return;
    reverse_recursive(node->next);
    printf("%d\t", node->data);
}

void reverse_display() {
    if (start == NULL) {
        printf("no elements added\n");
        return;
    }
    printf("reverse: ");
    reverse_recursive(start);
    printf("\n");
}

// ----------------------------------
// COUNT NODES
// ----------------------------------
int count() {
    int c = 0;
    temp = start;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

// ----------------------------------
// INSERT BEFORE A VALUE
// ----------------------------------
void insert_before() {
    struct Node *p, *newnode;
    int val;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter data");
    scanf("%d", &newnode->data);

    printf("value before which you want to insert");
    scanf("%d", &val);

    temp = start;
    p = start;

    while (temp != NULL && temp->data != val) {
        p = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp == start) {     // insert at beginning
        newnode->next = start;
        start = newnode;
    } else {
        p->next = newnode;
        newnode->next = temp;
    }
}

// ----------------------------------
// INSERT AFTER A VALUE
// ----------------------------------
void insert_after() {
    struct Node *newnode;
    int val;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter data");
    scanf("%d", &newnode->data);

    printf("value after which you want to insert");
    scanf("%d", &val);

    temp = start;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// ----------------------------------
// INSERT AT POSITION (1-based index)
// ----------------------------------
void insert_at_position() {
    int pos, i=1;
    struct Node *newnode, *p = start;

    printf("enter position ");
    scanf("%d", &pos);

    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter data ");
    scanf("%d", &newnode->data);

    if (pos == 1) {
        newnode->next = start;
        start = newnode;
        return;
    }

    while (i < pos - 1 && p != NULL) {
        p = p->next;
        i++;
    }

    if (p == NULL) {
        printf("Invalid position\n");
        return;
    }

    newnode->next = p->next;
    p->next = newnode;
}

// ----------------------------------
// DELETE NODE BY VALUE
// ----------------------------------
void delete_node() {
    int val;
    printf("enter val to delete");
    scanf("%d", &val);

    struct Node *p;
    temp = p = start;

    while (temp != NULL && temp->data != val) {
        p = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp == start) {
        start = temp->next;
    } else {
        p->next = temp->next;
    }

    free(temp);
}

// ----------------------------------
// MAIN MENU
// ----------------------------------
void main() {
    int choice = 0;

    while (choice != 9) {
        printf("\nenter:\n"
               "1:create\n"
               "2:display\n"
               "3:reverse display\n"
               "4:insert before\n"
               "5:insert after\n"
               "6:insert at position\n"
               "7:delete\n"
               "8:count nodes\n"
               "9:exit\n");

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
        }
    }
}
