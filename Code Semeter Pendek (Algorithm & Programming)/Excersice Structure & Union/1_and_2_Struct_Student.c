#include <stdio.h>
#include <string.h>

struct DateOfBirth {
    int date;
    int month;
    int year;
};

struct Address {
    char street[100];
    int number;
    char city[50];
    char province[50];
};

struct Student {
    long long nim;
    char name[100];
    struct Address address;
    char place[30];
    struct DateOfBirth dob;
};

int main() {
    struct Student students[5];
    
    for(int i = 0; i < 5; i++) {
        printf("=== Student %d ===\n", i + 1);
        
        printf("Enter student number: ");
        scanf("%lld", &students[i].nim);
        
        printf("Enter name: ");
        scanf(" %[^\n]", students[i].name);
        
        printf("Enter street name: ");
        scanf(" %[^\n]", students[i].address.street);
        printf("Enter street number: ");
        scanf("%d", &students[i].address.number);
        printf("Enter city: ");
        scanf(" %[^\n]", students[i].address.city);
        printf("Enter province: ");
        scanf(" %[^\n]", students[i].address.province);
        
        printf("Enter place: ");
        scanf(" %[^\n]", students[i].place);
        
        printf("Enter birth date (DD MM YYYY): ");
        scanf("%d %d %d", &students[i].dob.date, &students[i].dob.month, &students[i].dob.year);
        printf("\n");
    }
    
    printf("=== ALL STUDENTS DATA ===\n");
    for(int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("Number: %lld\n", students[i].nim);
        printf("Name: %s\n", students[i].name);
        printf("Address: %s no.%d, %s, %s\n", students[i].address.street, students[i].address.number, students[i].address.city, students[i].address.province);
        printf("Place: %s\n", students[i].place);
        printf("Birth: %d/%d/%d\n\n", students[i].dob.date, students[i].dob.month, students[i].dob.year);
    }
    
    return 0;
}