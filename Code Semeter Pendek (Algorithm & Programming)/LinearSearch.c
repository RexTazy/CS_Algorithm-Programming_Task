//Author: @FikriBiruni

#include <stdio.h>

int main() {
    int arr[] = {1, 3, 5, 7, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target, found = 0;
    
    printf("Enter target: ");
    scanf("%d", &target);
    
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            found = 1;
            break;
        }
    }
    
    if(found)
        printf("found!\n");
    else
        printf("not found!\n");
    
    return 0;
}