// Game Store Inventory
// Author: Fikri Aziz Biruni 
// Made in 2023 For Algorithm and Programming coding practice (Semester 1)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GAMES 100
#define FILENAME "gameStore.txt"

typedef struct {
    char id[20];
    char title[50];
    char developer[50];
    int year;
} Game;

Game games[MAX_GAMES];
int count = 0;

void menu() {
    printf("\n=== GAME STORE ===\n");
    printf("1. Add Game\n");
    printf("2. Display Games\n");
    printf("3. Update Game\n");
    printf("4. Delete Game\n");
    printf("5. Save & Exit\n");
    printf("Choice: ");
}

void addGame() {
    if (count >= MAX_GAMES) {
        printf("Storage full!\n");
        return;
    }
    
    printf("\nAdd New Game:\n");
    printf("ID: ");
    fgets(games[count].id, 20, stdin);
    games[count].id[strcspn(games[count].id, "\n")] = 0;
    
    printf("Title: ");
    fgets(games[count].title, 50, stdin);
    games[count].title[strcspn(games[count].title, "\n")] = 0;
    
    printf("Developer: ");
    fgets(games[count].developer, 50, stdin);
    games[count].developer[strcspn(games[count].developer, "\n")] = 0;
    
    printf("Year: ");
    scanf("%d", &games[count].year);
    getchar();
    
    count++;
    printf("Game added!\n");
}

void displayGames() {
    if (count == 0) {
        printf("No games found.\n");
        return;
    }
    sort();
    printf("\n=== GAME INVENTORY (Sorted by Title A-Z) ===\n");
    printf("%-10s %-30s %-25s %-10s\n", "ID", "Title", "Developer", "Year");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-30s %-25s %-10d\n", games[i].id, games[i].title, games[i].developer, games[i].year);
    }
    printf("Total games: %d\n", count);
}

void updateGame() {
    char id[20];
    printf("Enter Game ID: ");
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = 0;
    int index = search(id);
    if (index == -1) {
        printf("Game not found!\n");
        return;
    }
    printf("Current: %s | %s | %s | %d\n", games[index].id, games[index].title, games[index].developer, games[index].year);
    printf("New Title: ");
    fgets(games[index].title, 50, stdin);
    games[index].title[strcspn(games[index].title, "\n")] = 0;
    printf("New Developer: ");
    fgets(games[index].developer, 50, stdin);
    games[index].developer[strcspn(games[index].developer, "\n")] = 0;
    printf("New Year: ");
    scanf("%d", &games[index].year);
    getchar();
    printf("Game updated!\n");
}

void deleteGame() {
    char id[20];
    printf("Enter Game ID to delete: ");
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = 0;
    int index = search(id);
    if (index == -1) {
        printf("Game not found!\n");
        return;
    }
    for (int i = index; i < count - 1; i++) {
        games[i] = games[i + 1];
    }
    count--;
    printf("Game deleted!\n");
}

void load() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) return;
    
    char line[200];
    while (fgets(line, 200, file) && count < MAX_GAMES) {
        line[strcspn(line, "\n")] = 0;
        char *token = strtok(line, "#");
        if (token) strcpy(games[count].id, token);
        token = strtok(NULL, "#");
        if (token) strcpy(games[count].title, token);
        token = strtok(NULL, "#");
        if (token) strcpy(games[count].developer, token);        
        token = strtok(NULL, "#");
        if (token) games[count].year = atoi(token);
        count++;
    }
    fclose(file);
}

void save() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) return;
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s#%s#%s#%d\n", 
                games[i].id, games[i].title, 
                games[i].developer, games[i].year);
    }
    fclose(file);
    printf("Data saved!\n");
}

int search(char *id) {
    for (int i = 0; i < count; i++) {
        if (strcmp(games[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void sort() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(games[j].title, games[j + 1].title) > 0) {
                Game temp = games[j];
                games[j] = games[j + 1];
                games[j + 1] = temp;
            }
        }
    }
}

int main() {
    load();
    int choice;
    
    do {
        menu();
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1: addGame(); break;
            case 2: displayGames(); break;
            case 3: updateGame(); break;
            case 4: deleteGame(); break;
            case 5: save(); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    
    return 0;
}