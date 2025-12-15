#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int n = 0;

/* ---------------- HEAPIFY (DOWN) ---------------- */
void heapify(int a[], int size, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && a[left] > a[largest])
        largest = left;

    if (right <= size && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, size, largest);
    }
}

/* ---------------- BUILD HEAP ---------------- */
void buildHeap() {
    int i;
    for (i = n / 2; i >= 1; i--) {
        heapify(heap, n, i);
    }
    printf("Heap built successfully!\n");
}

/* ---------------- HEAPIFY UP ---------------- */
void heapifyUp(int i) {
    while (i > 1 && heap[i] > heap[i / 2]) {
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;
        i = i / 2;
    }
}

/* ---------------- INSERT ---------------- */
void insert(int val) {
    if (n == MAX - 1) {
        printf("Heap Overflow!\n");
        return;
    }
    heap[++n] = val;
    heapifyUp(n);
    printf("Inserted %d\n", val);
}

/* ---------------- DELETE ROOT ---------------- */
void deleteRoot() {
    if (n == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Deleted root: %d\n", heap[1]);
    heap[1] = heap[n--];
    heapify(heap, n, 1);
}

/* ---------------- DISPLAY ---------------- */
void display() {
    int i;
    if (n == 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Heap elements: ");
    for (i = 1; i <= n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

/* ---------------- HEAP SORT ---------------- */
void heapSort() {
    int i, temp;
    int originalSize = n;

    if (n == 0) {
        printf("Heap is empty!\n");
        return;
    }

    buildHeap();   // Step 1

    for (i = n; i >= 2; i--) {   // Step 2
        temp = heap[1];
        heap[1] = heap[i];
        heap[i] = temp;

        n--;
        heapify(heap, n, 1);
    }

    n = originalSize;

    printf("Sorted Array (Ascending Order): ");
    for (i = 1; i <= n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

/* ---------------- MAIN ---------------- */
int main() {
    int choice, val;

    while (1) {
        printf("\n------ MAX HEAP MENU ------\n");
        printf("1. Insert\n");
        printf("2. Delete Root\n");
        printf("3. Display Heap\n");
        printf("4. Build Heap\n");
        printf("5. Heap Sort\n");
        printf("6. Exit\n");
        printf("---------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insert(val);
            break;

        case 2:
            deleteRoot();
            break;

        case 3:
            display();
            break;

        case 4:
            buildHeap();
            break;

        case 5:
            heapSort();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
