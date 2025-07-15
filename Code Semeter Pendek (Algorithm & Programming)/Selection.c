#include <stdio.h>

int main() {
    int num;
    printf("Masukkan sebuah angka: ");
    scanf("%d", &num);

    if (num > 0 && num <= 10) {
        printf("Value tersebut berada diantara 0 dan 10\n");
    } else if (num > 10 && num <= 100) {
        printf("Value tersebut berada diantara 10 dan 100\n");
    } else if (num > 100) {
        printf("Value tersebut berada diatas 100\n");
    } else {
        printf("Value tersebut berada di bawah 0\n");
    }

    return 0;
}