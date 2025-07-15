#include <stdio.h>

int main() {
    int x;

    printf("Input a number between 1 and 1000: ");
    scanf("%d", &x);

    if (x >= 1 && x <= 1000) { //Constraints
        if (x % 2 == 0) {
            printf("%d is even number\n", x);
        } else {
            printf("%d is odd number\n", x);
        }
    } else {
        printf("Input out of range.\n");
    }

    return 0;
}