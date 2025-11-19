#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int a[7] = {50, 30, 20, 40, 80, 10, 60};
void swap(int x, int y) {
int temp = a[x];
a[x] = a[y];
a[y] = temp;
}
int partition(int low, int high){
    int pivot=a[low];
    int i=low;
    int j=high;
    while(i<j){
        while(a[i]<=pivot && i<=high-1){
            i++;
        }
        while(a[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(i,j);
    }
    swap(low,j);
    return j;
    
}

void quickSort(int low, int high) {
    if (low < high) {
      int pi = partition(low, high);
      quickSort(low, pi - 1);
      quickSort(pi + 1, high);
    }
}

void main() {
    int n = 7;
    quickSort(0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
}
