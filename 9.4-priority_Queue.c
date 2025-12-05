//Higher value → Higher priority
//When inserting, elements are placed according to priority
//Deletion removes the highest-priority element

#include <stdio.h>
#define MAX 10

int pq[MAX];
int size = 0;   // current number of elements

// Function to insert an element into the priority queue
void insert(int value) {
    if (size == MAX) {
        printf("Priority Queue Overflow!\n");
        return;
    }

    int i = size - 1;

    // Shift elements to maintain priority (descending order)
    while (i >= 0 && pq[i] < value) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;

    printf("%d inserted.\n", value);
}

// Function to delete the highest priority element
int delete() {
    if (size == 0) {
        printf("Priority Queue Underflow!\n");
        return -1;
    }

    int val = pq[0];  // highest priority element
    for (int i = 0; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;
    return val;
}

// Display priority queue
void display() {
    if (size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < size; i++)
        printf("%d ", pq[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- PRIORITY QUEUE MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                value = delete();
                if (value != -1)
                    printf("Deleted highest priority element: %d\n", value);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

