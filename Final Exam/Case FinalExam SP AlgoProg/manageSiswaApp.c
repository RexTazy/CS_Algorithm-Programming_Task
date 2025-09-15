// Author: Fikri Aziz Biruni
// NIM: 2702356362

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Siswa {
    char nis[11];
    char nama[50];
    char mata_pelajaran[20];
    float nilai;
    int isSaved;
};

struct Siswa siswa[100];
int total = 0;

int validNIS(char *nis) { // Constraint untuk NIS agar hanya 10 digit angka
    if(strlen(nis) != 10) return 0;
    for(int i = 0; i < 10; i++) {
        if(nis[i] < '0' || nis[i] > '9') return 0;
    }
    return 1;
}

int CheckDuplicate(char *nis) { // Constraint untuk NIS agar tidak duplikat (unique)
    for(int i = 0; i < total; i++) {
        if(strcmp(siswa[i].nis, nis) == 0) {
            return 1;
        }
    }
    return 0;
}

void loadData() {
    FILE *file = fopen("data_siswa.csv", "r");
    if(file == NULL) {
        printf("File data_siswa.csv tidak ditemukan. Memulai dengan file baru.\n");
        return;
    }
    
    char header[200];
    fgets(header, sizeof(header), file);
    
    total = 0;
    while(fscanf(file, "%[^,],%[^,],%[^,],%f\n", siswa[total].nis, siswa[total].nama, siswa[total].mata_pelajaran, &siswa[total].nilai) == 4)
    {
        siswa[total].isSaved = 1;
        total++;
    }
    
    fclose(file);
}

void inputData() {
    printf("\n=== Input Data Siswa ===\n");
    
    do {
        printf("NIS: ");
        scanf("%s", siswa[total].nis);
        
        if(!validNIS(siswa[total].nis)) {
            printf("NIS harus 10 digit angka!\n");
        }
        else if(CheckDuplicate(siswa[total].nis)) {
            printf("NIS sudah terdaftar!\n");
        }
        
    } while(!validNIS(siswa[total].nis) || CheckDuplicate(siswa[total].nis));
    
    printf("Nama: ");
    scanf(" %[^\n]", siswa[total].nama);
    printf("Mata Pelajaran: ");
    scanf(" %[^\n]", siswa[total].mata_pelajaran);
    printf("Nilai: ");
    scanf("%f", &siswa[total].nilai);

    siswa[total].isSaved = 0;
    total++;
    printf("Data berhasil ditambahkan! (Belum disimpan ke dalam file)\n");
}

void displayData() {
    if(total == 0) {
        printf("Tidak ada data siswa.\n");
        return;
    }
    
    printf("\n=== Daftar Semua Siswa (urut NIS) ===\n");
    printf("%-12s %-20s %-15s %s\n", "NIS", "Nama", "Mata Pelajaran", "Nilai");
    
    for(int i = 0; i < total-1; i++) {
        for(int j = 0; j < total-i-1; j++) {
            if(strcmp(siswa[j].nis, siswa[j+1].nis) > 0) {
                struct Siswa temp = siswa[j];
                siswa[j] = siswa[j+1];
                siswa[j+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < total; i++) {
        printf("%-12s %-20s %-15s %.2f", siswa[i].nis, siswa[i].nama, siswa[i].mata_pelajaran, siswa[i].nilai);
        if(siswa[i].isSaved == 0) {
            printf(" (Data belum disimpan)");
        }
        printf("\n");
    }
    
    printf("\n=== Daftar Semua Siswa (urut Nama) ===\n");
    printf("%-12s %-20s %-15s %s\n", "NIS", "Nama", "Mata Pelajaran", "Nilai");
    
    for(int i = 0; i < total-1; i++) {
        for(int j = 0; j < total-i-1; j++) {
            if(strcmp(siswa[j].nama, siswa[j+1].nama) > 0) {
                struct Siswa temp = siswa[j];
                siswa[j] = siswa[j+1];
                siswa[j+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < total; i++) {
        printf("%-12s %-20s %-15s %.2f", siswa[i].nis, siswa[i].nama, siswa[i].mata_pelajaran, siswa[i].nilai);
        if(siswa[i].isSaved == 0) {
            printf(" (Data belum disimpan)");
        }
        printf("\n");
    }
}

void searchData() {
    char cari[11];
    printf("\nMasukkan NIS yang dicari: ");
    scanf("%s", cari);
    
    for(int i = 0; i < total; i++) {
        if(strcmp(siswa[i].nis, cari) == 0) {
            printf("\n=== Detail Siswa ===\n");
            printf("NIS: %s\n", siswa[i].nis);
            printf("Nama: %s\n", siswa[i].nama);
            printf("Mata Pelajaran: %s\n", siswa[i].mata_pelajaran);
            printf("Nilai: %.2f\n", siswa[i].nilai);
            
            if(siswa[i].isSaved == 0) {
                printf("Status: Belum disimpan ke file\n");
            } else {
                printf("Status: Sudah disimpan\n");
            }
            return;
        }
    }
    printf("Siswa tidak ditemukan!\n");
}

void saveData() {
    FILE *file = fopen("data_siswa.csv", "w");
    fprintf(file, "NIS,Nama,Mata Pelajaran,Nilai\n");
    
    for(int i = 0; i < total; i++) {
        fprintf(file, "%s,%s,%s,%.2f\n",siswa[i].nis, siswa[i].nama, siswa[i].mata_pelajaran, siswa[i].nilai); siswa[i].isSaved = 1;
    }
    
    fclose(file);
    printf("Data berhasil disimpan ke data_siswa.csv\n");
}

int main() {
    int pilihan;
    
    loadData();
    
    do {
        printf("\n=== Aplikasi Manajemen Data Siswa ===\n");
        printf("1. Input Data Siswa\n");
        printf("2. Tampilkan Semua Data Siswa\n");
        printf("3. Cari Siswa berdasarkan NIS\n");
        printf("4. Simpan Data ke File\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        
        switch(pilihan) {
            case 1: inputData(); break;
            case 2: displayData(); break;
            case 3: searchData(); break;
            case 4: saveData(); break;
            case 5: printf("Terima kasih!\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while(pilihan != 5);
    
    return 0;
}