#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int base[] = {14, 6, 23, 18, 7, 47, 2, 83, 16, 38};
    int arr[sizeof(base) / sizeof(base[0])];
    int n = sizeof(base) / sizeof(base[0]);
    
    printf("Original: ");
    printArray(base, n);
    printf("\n");
    
    printf("=== BUBBLE SORT ===\n");
    for(int i = 0; i < n; i++) arr[i] = base[i];
    
    for(int i = 0; i < n-1; i++) {
        printf("Round %d: ", i+1);
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printArray(arr, n);
    }
    
    printf("\n=== SELECTION SORT ===\n");
    for(int i = 0; i < n; i++) arr[i] = base[i];
    
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        
        printf("Round %d: ", i+1);
        printArray(arr, n);
    }
    
    printf("\n=== INSERTION SORT ===\n");
    for(int i = 0; i < n; i++) arr[i] = base[i];
    
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        
        printf("Round %d: ", i);
        printArray(arr, n);
    }
    
    return 0;
}