#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 100

char tasks[MAX][LEN];
int count = 0;

void load() {
    FILE *f = fopen("tasks.txt", "r");
    if (!f) return;

    while (fgets(tasks[count], LEN, f)) {
        tasks[count][strcspn(tasks[count], "\n")] = 0;
        count++;
    }
    fclose(f);
}

void save() {
    FILE *f = fopen("tasks.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s\n", tasks[i]);
    }
    fclose(f);
}

void addTask() {
    printf("Yeni görev: ");
    getchar();
    fgets(tasks[count], LEN, stdin);
    tasks[count][strcspn(tasks[count], "\n")] = 0;
    count++;
    save();
}

void listTasks() {
    printf("\n--- Görevler ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void deleteTask() {
    int n;
    printf("Silinecek görev numarası: ");
    scanf("%d", &n);

    if (n < 1 || n > count) {
        printf("Hatalı seçim!\n");
        return;
    }

    for (int i = n - 1; i < count - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }

    count--;
    save();
}

int main() {
    int choice;
    load();

    while (1) {
        printf("\n1-Ekle  2-Listele  3-Sil  4-Çıkış\nSeçim: ");
        scanf("%d", &choice);

        if (choice == 1) addTask();
        else if (choice == 2) listTasks();
        else if (choice == 3) deleteTask();
        else if (choice == 4) break;
        else printf("Geçersiz!\n");
    }

    return 0;
}