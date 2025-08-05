#include <stdio.h>

struct Mhs {
    char name[20];
    int nim;
    float gpa;
};

int main() {
    struct Mhs students[5];
    FILE *file;
    
    printf("Enter 5 students data:\n");
    for(int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("NIM: ");
        scanf("%d", &students[i].nim);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
        printf("\n");
    }
    
    file = fopen("Mhs.dat", "wb");
    fwrite(students, sizeof(struct Mhs), 5, file);
    fclose(file);
    
    printf("Data saved to Mhs.dat\n");
    
    return 0;
}