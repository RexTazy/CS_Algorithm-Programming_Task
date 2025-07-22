#include <stdio.h>

int main() {
    int n, m;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);
    printf("Masukkan jumlah mata kuliah: ");
    scanf("%d", &m);
    
    char nama[n][20];
    int nilai[n][m];
    float rata[n];
    
    for (int i = 0; i < n; i++) {
        printf("\n--- Data Mahasiswa ke-%d ---\n", i + 1);
        printf("Nama: ");
        scanf("%s", nama[i]);
        printf("Masukkan %d nilai (BERI SPASI UNTUK SETIAP NILAI!!!): ", m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &nilai[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        int total = 0;
        int *ptr = nilai[i];
        for (int j = 0; j < m; j++) {
            total += *(ptr + j);
        }
        rata[i] = (float)total / m;
    }
    
    printf("\n===== DATA NILAI MAHASISWA =====\n");
    printf("No. Nama    ");
    for (int i = 0; i < m; i++) printf("Nilai-%d ", i + 1);
    printf("Rata-rata\n");
    
    for (int i = 0; i < n; i++) {
        printf("%-3d %-8s", i + 1, nama[i]);
        for (int j = 0; j < m; j++) {
            printf("%-8d", nilai[i][j]);
        }
        printf("%.2f\n", rata[i]);
    }
    
    return 0;
}