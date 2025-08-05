#include <stdio.h>

int main() {
    FILE *file = fopen("birth.txt", "r");
    int day, month, year, age;
    int above51 = 0, age44_51 = 0, age36_43 = 0, age28_35 = 0, below28 = 0;
    
    while(fscanf(file, "%d/%d/%d", &day, &month, &year) == 3) {
        age = 2025 - (1900 + year); //menggunakan tahun 2025 sebagai tahun saat ini (tanpa bulan dan tanggal)
        
        if(age > 51) above51++;
        else if(age >= 44) age44_51++;
        else if(age >= 36) age36_43++;
        else if(age >= 28) age28_35++;
        else below28++;
    }
    
    fclose(file);
    
    printf("Above 51: %d\n", above51);
    printf("Between 44-51: %d\n", age44_51);
    printf("Between 36-43: %d\n", age36_43);
    printf("Between 28-35: %d\n", age28_35);
    printf("Below 28: %d\n", below28);
    
    return 0;
}