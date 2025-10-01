## 1. Library dan `#define`

```c
#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LEN 50
```

* `#include <stdio.h>` → untuk input/output seperti `printf` dan `scanf`.
* `#include <string.h>` → untuk manipulasi string seperti `strncpy`.
* `#define MAX_USERS 100` → membuat **konstanta** `MAX_USERS` = 100 (batas maksimal pengguna).
* `#define NAME_LEN 50` → panjang maksimal nama pengguna = 50 karakter.

---

## 2. Struktur Data `User`

```c
typedef struct {
    int id;
    char name[NAME_LEN];
} User;
```

* `struct` = cara menyimpan data **lebih dari satu tipe dalam satu paket**.
* `User` punya dua bagian:

  * `id` → nomor unik tiap user
  * `name` → nama user (array karakter)
* `typedef` membuat kita bisa pakai `User` langsung tanpa menulis `struct User`.

---

## 3. Array dan Variabel Global

```c
User users[MAX_USERS];
int user_count = 0;
int next_id = 1;
```

* `users[MAX_USERS]` → array yang menampung semua user (maks 100).
* `user_count` → menghitung jumlah user yang ada sekarang.
* `next_id` → nomor ID yang akan diberikan ke user baru.

---

## 4. Fungsi `list_users()`

```c
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
```

* Menampilkan semua user.
* Kalau `user_count == 0`, berarti belum ada user → tampilkan pesan.
* `for` digunakan untuk menelusuri array `users`.

---

## 5. Fungsi `add_user()`

```c
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
```

* Memeriksa apakah masih bisa menambah user.
* Input nama user dengan `scanf(" %[^\n]", name)` → baca seluruh baris sampai enter.
* ID diberikan otomatis (`next_id++`).
* `strncpy` → menyalin string dengan aman agar tidak overflow.
* `user_count++` → menambah jumlah user setelah berhasil ditambahkan.

---

## 6. Fungsi `update_user()`

```c
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
```

* Cari user berdasarkan ID.
* Kalau ditemukan → minta nama baru dan update.
* Kalau tidak → tampilkan pesan “User not found”.

---

## 7. Fungsi `delete_user()`

```c
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
```

* Cari user berdasarkan ID.
* Kalau ditemukan → **geser semua data setelahnya** satu posisi ke kiri supaya array tetap rapih.
* Kurangi `user_count`.
* Kalau tidak ditemukan → tampilkan pesan “User not found”.

---

## 8. Fungsi `menu()`

```c
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
```

* Menampilkan menu pilihan.
* `switch` → pilih aksi sesuai input.
* `do...while` → menu akan terus muncul sampai pilih 0 (Exit).

---

## 9. Fungsi `main()`

```c
int main() {
    menu();
    return 0;
}
```

* Program mulai dari `main()`.
* Memanggil `menu()` → user bisa menambah, melihat, update, atau hapus user.

---

**Intinya:**

1. Program ini **mengelola data user** menggunakan array dan struct.
2. Ada fitur **CRUD**: Create (Add), Read (List), Update, Delete.
3. **ID** otomatis, **nama** disimpan sebagai array karakter.
4. Pointer atau operasi kompleks tidak terlalu digunakan, cocok untuk pemula memahami array dan struct.
