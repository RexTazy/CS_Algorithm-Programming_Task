// Author: Fikri

#include <stdio.h>

int main() {
    FILE *file = fopen("algo.txt", "r");
    char text[50];
    fgets(text, 50, file);
    printf("%s", text);
    fclose(file);
    return 0;
}