#include <stdio.h>

int main() {
    int a[4][4], b[4][4], c[4][4];
    int i, j, k;
    
    printf("Enter first matrix (4x4):\n");
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);
    
    printf("Enter second matrix (4x4):\n");
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            scanf("%d", &b[i][j]);
    
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++) {
            c[i][j] = 0;
            for(k = 0; k < 4; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    
    printf("Result:\n");
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    
    return 0;
}