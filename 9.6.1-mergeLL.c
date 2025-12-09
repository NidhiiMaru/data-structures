#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newnode = createNode(value);

    if (head == NULL)
        return newnode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

// Merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* temp = NULL;
    
    // If both lists empty
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    // Initializing result head
    if (l1->data < l2->data) {
        result = temp = l1;
        l1 = l1->next;
    } else {
        result = temp = l2;
        l2 = l2->next;
    }

    // Merge the remaining nodes
    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    // Attach remaining nodes
    if (l1 != NULL) temp->next = l1;
    if (l2 != NULL) temp->next = l2;

    return result;
}

// Display a list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL, *merged = NULL;
    int n1, n2, val;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter sorted values: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        list1 = insertEnd(list1, val);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter sorted values: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        list2 = insertEnd(list2, val);
    }

    printf("\nList 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    merged = mergeLists(list1, list2);

    printf("\nMerged Sorted List: ");
    display(merged);

    return 0;
}
