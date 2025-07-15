#include <stdio.h>

int main() {
    long long nim;
    int last_digit;
    
    printf("Masukkan NIM (Nomor Induk Mahasiswa): ");
    scanf("%lld", &nim);
    
    last_digit = nim % 10;
    
    printf("\nNIM: %lld\n", nim);
    printf("Last digit: %d\n", last_digit);
    
    if (last_digit % 2 == 0) {
        printf("Gunakan Dataset A\n");
    } else {
        printf("Gunakan Dataset B\n");
    }
    
    printf("Good luck untuk Final Exam!\n");
    
    return 0;
}