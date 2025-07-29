#include <stdio.h>

struct automobile {
    int year;
    char model[8];
    int engine_power;
    float weight;
};

int main() {
    struct automobile cars[5];
    int i;
    
    printf("Enter data for 5 cars:\n");
    for(i = 0; i < 5; i++) {
        printf("Car %d:\n", i + 1);
        printf("Year: ");
        scanf("%d", &cars[i].year);
        printf("Model: ");
        scanf("%s", cars[i].model);
        printf("Engine Power: ");
        scanf("%d", &cars[i].engine_power);
        printf("Weight: ");
        scanf("%f", &cars[i].weight);
        printf("\n");
    }
    
    printf("=== CAR DATA ===\n");
    for(i = 0; i < 5; i++) {
        printf("Car %d: %d %s %d HP %.1f kg\n", i + 1, cars[i].year, cars[i].model, cars[i].engine_power, cars[i].weight);
    }
    
    return 0;
}