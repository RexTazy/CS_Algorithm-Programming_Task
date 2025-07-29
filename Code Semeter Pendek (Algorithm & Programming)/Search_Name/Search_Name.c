#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("testdata.in", "r");
    int t, n, i, found;
    char names[100][30], search[30];
    
    fscanf(file, "%d", &t);
    
    for(int case_num = 1; case_num <= t; case_num++) {
        fscanf(file, "%d", &n);
        
        //Read nama dari file
        for(i = 0; i < n; i++) {
            fscanf(file, "%s", names[i]);
        }
        
        //Read yang dicari dari file
        fscanf(file, "%s", search);
        
        //Cari nama yang dicari dari list
        found = -1;
        for(i = 0; i < n; i++) {
            if(strcmp(names[i], search) == 0) {
                found = i + 1;
                break;
            }
        }
        
        //Print hasil
        printf("Case #%d: ", case_num);
        if(found != -1)
            printf("%d\n", found);
        else
            printf("Not found\n");
    }
    
    fclose(file);
    return 0;
}