#include <stdio.h>

// Case: Mencari Nilai Maksimum, Minimum, dan Rata-Rata dari 10 Angka menggunakan Modular programming (Function)

void inputArray(int arr[]) {
    printf("Enter 10 numbers: ");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
}

int findMax(int arr[]) {
    int max = arr[0];
    for(int i = 1; i < 10; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

int findMin(int arr[]) {
    int min = arr[0];
    for(int i = 1; i < 10; i++) {
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

float Rata(int arr[]) {
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    return (float)sum / 10;
}

void Result(int arr[], int max, int min, float avg) {
    printf("\n ===============Results==============\n");
    printf("Numbers: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nMax: %d\n", max);
    printf("Min: %d\n", min);
    printf("Rata-rata: %.2f\n", avg);
}

int main() {
    int arr[10];
    
    inputArray(arr);
    int max = findMax(arr);
    int min = findMin(arr);
    float avg = Rata(arr);
    Result(arr, max, min, avg);

    return 0;
}