#include <stdio.h>
#include <string.h>

int main() {
    char nim[12];
    int pilihan;
    char peminatan[50];

    do {
        printf("=== PENDAFTARAN Peminatan COMPUTER SCIENCE ===\n");
        printf("Masukkan NIM (harus 10 karakter): ");
        scanf("%s", nim);
        if (strlen(nim) != 10) {
            printf("Error: NIM harus 10 karakter!\n");
        }
    } while (strlen(nim) != 10); // Loop sampai NIM valid (10 karakter)

    do {
        printf("\nPilih Peminatan Computer Science:\n");
        printf("1. Digital Creative Technology\n");
        printf("2. Intelligent System\n");
        printf("3. Database Technology\n");
        printf("4. Network Technology\n");
        printf("5. Game Technology\n");
        printf("6. Cyber Security\n");
        printf("7. Software Engineering\n");
        printf("8. Mobile Technology\n");
        
        printf("\nMasukkan pilihan (1-8): ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            strcpy(peminatan, "Digital Creative Technology");}
        else if (pilihan == 2) {
            strcpy(peminatan, "Intelligent System");}
        else if (pilihan == 3) {
            strcpy(peminatan, "Database Technology");}
        else if (pilihan == 4) {
            strcpy(peminatan, "Network Technology");}
        else if (pilihan == 5) {
            strcpy(peminatan, "Game Technology");}
        else if (pilihan == 6) {
            strcpy(peminatan, "Cyber Security");}
        else if (pilihan == 7) {
            strcpy(peminatan, "Software Engineering");}
        else if (pilihan == 8) {
            strcpy(peminatan, "Mobile Technology");}
        else {
            printf("Error: Pilihan tidak valid! Silakan pilih angka 1-8.\n");}
        
    } while (pilihan < 1 || pilihan > 8); // Jika pilihan tidak valid akan loop sampai pilihan valid
    
    printf("%s telah terdaftar pada peminatan %s\n", nim, peminatan);
    
    return 0;
}