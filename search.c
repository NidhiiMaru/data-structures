#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int fibonacciSearch(int a[], int n, int key) {
    int fib2 = 0;     // (m-2)'th Fibonacci number
    int fib1 = 1;     // (m-1)'th Fibonacci number
    int fib = fib1 + fib2; // m'th Fibonacci number

    // Find the smallest Fibonacci number >= n
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if (a[i] < key) {
            fib  = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (a[i] > key) {
            fib  = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return i;
        }
    }

    if (fib1 && a[offset + 1] == key)
        return offset + 1;

    return -1;
}

void main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 85;

    int index = fibonacciSearch(arr, n, key);

    if (index >= 0)
        printf("Element found at position %d", index + 1);
    else
        printf("Element not found");
}
