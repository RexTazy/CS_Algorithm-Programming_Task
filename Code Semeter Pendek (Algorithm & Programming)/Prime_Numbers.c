#include <stdio.h>

int isPrime(int n, int i) {
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    if(i * i > n) return 1;
    if(n % i == 0) return 0;
    return isPrime(n, i + 2);
}

int main() {
    int t, x;
    scanf("%d", &t);
    
    for(int case_num = 1; case_num <= t; case_num++) {
        scanf("%d", &x);
        printf("Case #%d: ", case_num);
        if(isPrime(x, 3))
            printf("Prime Number\n");
        else
            printf("Not Prime Number\n");
    }
    
    return 0;
}