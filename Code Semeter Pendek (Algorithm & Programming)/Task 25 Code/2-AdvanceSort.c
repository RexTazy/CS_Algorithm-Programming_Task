#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int round_count = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSort(int arr[], int low, int high, int n) {
    if(low < high) {
        int pi = partition(arr, low, high);
        printf("Round %d: ", ++round_count);
        printArray(arr, n);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int temp[100];
    int i = left, j = mid + 1, k = 0;
    
    while(i <= mid && j <= right) {
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    
    for(i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int left, int right, int n) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, n);
        mergeSort(arr, mid + 1, right, n);
        merge(arr, left, mid, right);
        printf("Round %d: ", ++round_count);
        printArray(arr, n);
    }
}

int main() {
    int base[] = {14, 6, 23, 18, 7, 47, 2, 83, 16, 38};
    int arr1[sizeof(base) / sizeof(base[0])], arr2[sizeof(base) / sizeof(base[0])];
    int n = sizeof(base) / sizeof(base[0]);
    
    printf("Original: ");
    printArray(base, n);
    printf("\n");
    
    printf("=== QUICKSORT ===\n");
    for(int i = 0; i < n; i++) arr1[i] = base[i];
    round_count = 0;
    quickSort(arr1, 0, n - 1, n);
    
    printf("\n=== MERGESORT ===\n");
    for(int i = 0; i < n; i++) arr2[i] = base[i];
    round_count = 0;
    mergeSort(arr2, 0, n - 1, n);
    
    return 0;
}