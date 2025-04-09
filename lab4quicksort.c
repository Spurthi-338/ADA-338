#include<stdio.h>

void quickSort(int A[], int low, int high);
int partition(int A[], int low, int high);
void display(int A[], int n);

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pos = partition(A, low, high);
        quickSort(A, low, pos - 1);
        quickSort(A, pos + 1, high);
    }
}

int partition(int A[], int low, int high) {
    int pivot = A[low];  
    int p = low + 1, q = high;

    while (p <= q) {
        while (p <= high && A[p] <= pivot) p++;  
        while (q > low && A[q] > pivot) q--;     

        if (p < q) {
            int temp = A[p];
            A[p] = A[q];
            A[q] = temp;
        }
    }

    int temp = A[low];
    A[low] = A[q];
    A[q] = temp;

    return q;  
}

void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {21, 45, 3, 30, 57, 81, 39};
    int n = sizeof(A) / sizeof(A[0]);
    quickSort(A, 0, n - 1);
    display(A, n);
    return 0;
}
