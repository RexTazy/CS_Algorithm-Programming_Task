#include <stdio.h>

struct Mhs {
    char name[20];
    int nim;
    float gpa;
};

int main() {
    struct Mhs students[5];
    FILE *file;
    
    file = fopen("Mhs.dat", "rb");
    fread(students, sizeof(struct Mhs), 5, file);
    fclose(file);
    
    printf("Nim\t\tName\t\tGPA\n");
    printf("-----\t\t-------\t\t----\n");
    
    for(int i = 0; i < 5; i++) {
        printf("%d\t\t%s\t\t%.2f\n", 
               students[i].nim, students[i].name, students[i].gpa);
    }
    
    return 0;
}