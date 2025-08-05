#include <stdio.h>
#include <string.h>

struct mhs {
    int nim;
    float gpa;
    char name[20];
};

int main() {
    struct mhs students[10] = {
        {12345, 3.5, "Budi"},
        {23456, 3.2, "Ani"},
        {34567, 3.8, "Citra"},
        {45678, 3.2, "Ali"},
        {56789, 3.6, "Dodi"},
        {67890, 3.1, "Eka"},
        {78901, 3.8, "Fani"},
        {89012, 3.4, "Gita"},
        {90123, 3.7, "Hadi"},
        {01234, 3.5, "Ika"}
    };
    
    int n = sizeof(students) / sizeof(students[0]);
    
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(students[j].gpa < students[min].gpa || (students[j].gpa == students[min].gpa && 
                strcmp(students[j].name, students[min].name) < 0)) {
                min = j;
            }
        }
        
        struct mhs temp = students[min];
        students[min] = students[i];
        students[i] = temp;
    }
    
    printf("GPA     Nama       NIM\n");
    printf("-----   -------    ---------\n");
    for(int i = 0; i < n; i++) {
        printf("%.1f     %-10s %d\n", students[i].gpa, students[i].name, students[i].nim);
    }
    
    return 0;
}