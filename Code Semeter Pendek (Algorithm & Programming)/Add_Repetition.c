#include <stdio.h>

int main() {
    int nilai;
    int pilihan;
    int target = 65;  // Misalkan nilai lulus adalah 65 (Grade C - sesuai ketentuan BINUS)
    
    printf("Masukkan nilai saat ini: ");
    scanf("%d", &nilai);
    
    if (nilai >= target) { // Best case: nilai sudah cukup untuk lulus
        printf("\nSELAMAT! Anda telah lulus mata kuliah \"Algorithm and Programming\"!\n");
        printf("Nilai Anda: %d (Minimum Kelulusan>= %d)\n", nilai, target);
        return 0;
    }
    
    printf("\nNilai Anda: %d (Belum Lulus)\n", nilai);
    printf("Target lulus: %d\n", target);
    printf("Perlu menambah %d poin lagi\n\n", target - nilai);
    
    while (nilai < target) { //repetition sampe nilai cukup untuk lulus
        printf("Pilih Aktivitas Belajar\n");
        printf("1. Mengerjakan tugas (+5 poin)\n");
        printf("2. Belajar algoritma (+8 poin)\n");
        printf("3. Praktik coding (+10 poin)\n");
        printf("4. Ikut kuis (+7 poin)\n");
        printf("Pilih aktivitas (1-4): ");
        scanf("%d", &pilihan);
        
        printf("\n");
        
        // Tambah hal lain sampe lulus
        switch (pilihan) {
            case 1:
                printf("Anda mengerjakan tugas...\n");
                nilai += 5;
                printf("Poin bertambah +5\n");
                break;
            case 2:
                printf("Anda belajar algoritma...\n");
                nilai += 8;
                printf("Poin bertambah +8\n");
                break;
            case 3:
                printf("Anda praktik coding...\n");
                nilai += 10;
                printf("Poin bertambah +10\n");
                break;
            case 4:
                printf("Anda ikut kuis...\n");
                nilai += 7;
                printf("Poin bertambah +7\n");
                break;
            default:
                printf("Pilihan tidak valid! Tidak ada poin yang ditambahkan.\n");
                break;
        }
        
        printf("Nilai sekarang: %d\n", nilai); // Print nilai setiap repetition
        
        if (nilai >= target) { // Jika nilai sudah cukup 
            printf("\nSELAMAT! Anda telah lulus mata kuliah \"Algorithm and Programming\"!\n");
            printf("Nilai akhir: %d\n", nilai);
        } else { // Jika nilai masih kurang untuk lulus
            printf("Masih perlu %d poin lagi\n", target - nilai);
            printf("=================================\n\n");
        }
    }
    
    return 0;
}