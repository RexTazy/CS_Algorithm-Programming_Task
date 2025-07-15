#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++) {
        int N;
        int biner[32];
        int idx = 0;
        
        // Input
        scanf("%d", &N);
        if (N == 0) { // Best case
            biner[0] = 0;
            idx = 1;
        } else {
            while (N > 0) {
                biner[idx++] = N % 2;
                N = N / 2;              
            }
        }
        
        // Print ke-i dan bilangan biner
        printf("Case #%d: ", i);
        for (int j = idx - 1; j >= 0; j--) {
            printf("%d", biner[j]);
        }
        printf("\n");
    }
    
    return 0;
}