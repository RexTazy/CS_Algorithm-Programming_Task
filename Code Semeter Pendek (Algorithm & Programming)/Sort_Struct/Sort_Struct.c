#include <stdio.h>

struct Answer {
    int num;
    char ans;
};

int main() {
    FILE *file = fopen("testdata.in", "r");
    int t, n, i, j;
    struct Answer temp;
    
    fscanf(file, "%d", &t);
    
    for(int case_num = 1; case_num <= t; case_num++) {
        fscanf(file, "%d", &n);
        struct Answer arr[n];
        
        // Read answers
        for(i = 0; i < n; i++) {
            fscanf(file, "%d. %c", &arr[i].num, &arr[i].ans);
        }
        
        // Sort by problem number (bubble sort)
        for(i = 0; i < n-1; i++) {
            for(j = 0; j < n-i-1; j++) {
                if(arr[j].num > arr[j+1].num) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        
        // Print sorted answers
        printf("Case #%d:\n", case_num);
        for(i = 0; i < n; i++) {
            printf("%d. %c\n", arr[i].num, arr[i].ans);
        }
    }
    
    fclose(file);
    return 0;
}