#include <stdio.h>

int main() {
    int n, i, day;
    
    scanf("%d", &n);
    printf("N = %d\n", n);
    
    for (i = 1; i <= n; i++) {
        day = ((i - 1) % 7) + 1;
        printf("%d ", day);}
    printf("\n");
    
    return 0;
}