#include <stdio.h>

struct studentScore {
    char nim[11];
    char name[30];
    char subjectCode[5];
    int sks;
    char grade;
};

int Grade(char grade) {
    switch(grade) {
        case 'A': return 4;
        case 'B': return 3;
        case 'C': return 2;
        case 'D': return 1;
        case 'E': return 0;
        default: return 0;
    }
}

int main() {
    struct studentScore subjects[5];
    int i, totalSKS = 0, totalPoints = 0;
    float gpa;
    
    printf("Enter NIM: ");
    scanf("%s", subjects[0].nim);
    printf("Enter name: ");
    scanf("%s", subjects[0].name);
    
    printf("\nEnter 5 subjects:\n");
    for(i = 0; i < 5; i++) {
        printf("Subject %d:\n", i + 1);
        printf("Subject Code: ");
        scanf("%s", subjects[i].subjectCode);
        printf("SKS: ");
        scanf("%d", &subjects[i].sks);
        printf("Grade (A/B/C/D/E): ");
        scanf(" %c", &subjects[i].grade);
        
        totalSKS += subjects[i].sks;
        totalPoints += Grade(subjects[i].grade) * subjects[i].sks;
        printf("\n");
    }
    
    gpa = (float)totalPoints / totalSKS;
    
    printf("=== STUDENT GPA ===\n");
    printf("NIM: %s\n", subjects[0].nim);
    printf("Name: %s\n", subjects[0].name);
    printf("Total SKS: %d\n", totalSKS);
    printf("GPA: %.2f\n", gpa);
    
    return 0;
}