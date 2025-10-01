#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
} User;

User users[MAX_USERS];
int user_count = 0;
int next_id = 1;

void list_users() {
    printf("\n=== List Users ===\n");
    if (user_count == 0) {
        printf("No users found.\n");
        return;
    }
    for (int i = 0; i < user_count; i++) {
        printf("ID: %d | Name: %s\n", users[i].id, users[i].name);
    }
}

void add_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }
    printf("Enter user name: ");
    char name[NAME_LEN];
    scanf(" %[^\n]", name);
    users[user_count].id = next_id++;
    strncpy(users[user_count].name, name, NAME_LEN - 1);
    users[user_count].name[NAME_LEN - 1] = '\0';
    user_count++;
    printf("User added.\n");
}

void update_user() {
    int id, found = 0;
    printf("Enter user ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == id) {
            printf("Enter new name: ");
            char name[NAME_LEN];
            scanf(" %[^\n]", name);
            strncpy(users[i].name, name, NAME_LEN - 1);
            users[i].name[NAME_LEN - 1] = '\0';
            printf("User updated.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("User not found.\n");
    }
}

void delete_user() {
    int id, found = 0;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == id) {
            for (int j = i; j < user_count - 1; j++) {
                users[j] = users[j + 1];
            }
            user_count--;
            printf("User deleted.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("User not found.\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\n=== Admin Panel ===\n");
        printf("1. List Users\n");
        printf("2. Add User\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: list_users(); break;
            case 2: add_user(); break;
            case 3: update_user(); break;
            case 4: delete_user(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}