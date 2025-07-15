#include <stdio.h>

int main() {
    float ipk;
    
    printf("Masukkan IPK: ");
    scanf("%f", &ipk);

    if (ipk >= 3.5 && ipk <= 4.0) {
        printf("Grade: Cumlaude\n");}
    else if (ipk >= 3.0 && ipk < 3.5) {
        printf("Grade: Outstanding\n");}
    else if (ipk >= 2.5 && ipk < 3.0) {
        printf("Grade: Very Good\n");}
    else if (ipk >= 2.0 && ipk < 2.5) {
        printf("Grade: Good\n");}
    else if (ipk >= 0.0 && ipk < 2.0) {
        printf("Grade: Poor\n");}
    else {
        printf("Value tidak valid! Masukkan nilai antara 0.0 dan 4.0\n");}
    
    return 0;
}