#include <stdio.h>

void main() {
    int y = 33, x = 45;

    y = y && x;
    printf("y && x = %d\n", y);

    y = y & x;
    printf("y & x = %d\n", y);

    y = 33;
    x = 45;

    y = y & x;
    printf("y & x = %d\n", y);

    y = y && x;
    printf("y && x = %d\n", y);
}