// Author: Fikri

#include <stdio.h>

int main() {
    FILE *file = fopen("algo.txt", "w");
    fprintf(file, "Saya suka Algoprog");
    fclose(file);
    return 0;
}