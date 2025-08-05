#include <stdio.h>
#include <string.h>

int main() {
    char names[10][20] = {"Ali", "Ani", "Tono", "Bayu", "Amir", "Ani", "Budi", "Tini", "Ucok", "Paijo"};
    char temp[20];
    int n = 10;
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(strcmp(names[j], names[j+1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }
    
    printf("Nama (Ascending)\n");
    printf("---------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
    
    return 0;
}