#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int t[100], i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right) t[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    while(i <= mid) t[k++] = arr[i++];
    while(j <= right) t[k++] = arr[j++];
    for(i = left, k = 0; i <= right; i++, k++) arr[i] = t[k];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {98, 79, 90, 88, 69, 73, 93, 100, 85, 95};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    mergeSort(arr, 0, n - 1);
    
    printf("\nSort: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}