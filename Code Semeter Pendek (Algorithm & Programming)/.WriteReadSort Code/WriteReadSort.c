// Author: Fikri

#include <stdio.h>

void writeSort(int arr[], int n) {
    FILE *file = fopen("sorted.txt", "w");
    for(int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

void readSort() {
    FILE *file = fopen("sorted.txt", "r");
    int num;
    while(fscanf(file, "%d", &num) == 1) {
        printf("%d ", num);
    }
    printf("\n");
    fclose(file);
}

int main() {
    int arr[] = {1, 5, 9, 2, 4, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    writeSort(arr, n);
    readSort();
    
    return 0;
}