#include <stdio.h>

struct studentScore {
    char nim[11];
    char name[30];
    char subjectCode[5];
    int sks;
    char grade;
};

int main() {
    struct studentScore student;
    
    printf("Enter NIM: ");
    scanf("%s", student.nim);
    printf("Enter name: ");
    scanf("%s", student.name);
    printf("Enter subject code: ");
    scanf("%s", student.subjectCode);
    printf("Enter SKS: ");
    scanf("%d", &student.sks);
    printf("Enter grade: ");
    scanf(" %c", &student.grade);
    
    printf("\n=== STUDENT SCORE ===\n");
    printf("NIM: %s\n", student.nim);
    printf("Name: %s\n", student.name);
    printf("Subject Code: %s\n", student.subjectCode);
    printf("SKS: %d\n", student.sks);
    printf("Grade: %c\n", student.grade);
    
    return 0;
}