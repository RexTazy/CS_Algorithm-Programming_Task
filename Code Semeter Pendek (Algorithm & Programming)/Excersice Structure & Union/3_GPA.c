#include <stdio.h>

struct ipkmhs {
    char nim[11];
    char name[30];
    float gpa;
};

int main() {
    struct ipkmhs students[5];
    int i;
    
    printf("Enter data 5 Mahasiswa:\n");
    for(i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("NIM: ");
        scanf("%s", students[i].nim);
        printf("Name: ");
        scanf("%s", students[i].name);
        
        do {
            printf("GPA (0.0-4.0): ");
            scanf("%f", &students[i].gpa);
            if(students[i].gpa < 0.0 || students[i].gpa > 4.0) {
                printf("Invalid! GPA harus antara 0.0 dan 4.0\n");
            }
        } while(students[i].gpa < 0.0 || students[i].gpa > 4.0);
        printf("\n");
    }
    
    printf("Mhs gpa >= 3.0:\n");
    for(i = 0; i < 5; i++) {
        if(students[i].gpa >= 3.0) {
            printf("%s\n", students[i].name);
        }
    }
    
    printf("\nMhs gpa < 3.0:\n");
    for(i = 0; i < 5; i++) {
        if(students[i].gpa < 3.0) {
            printf("%s\n", students[i].name);
        }
    }
    
    return 0;
}