#include <stdio.h>

int main() {
    int n, a = 0, b = 1, temp;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        temp = a + b;
        a = b;
        b = temp;
    }
    
    return 0;
}