# Materi 3: Operator & Kontrol Alur

## Operator di C

Operator digunakan untuk melakukan **operasi pada variabel/data**.

### a. Operator Aritmatika

| Operator | Contoh  | Hasil               |
| -------- | ------- | ------------------- |
| `+`      | `a + b` | Penjumlahan         |
| `-`      | `a - b` | Pengurangan         |
| `*`      | `a * b` | Perkalian           |
| `/`      | `a / b` | Pembagian           |
| `%`      | `a % b` | Modulus (sisa bagi) |

**Contoh Program:**

```c
#include <stdio.h>

int main() {
    int a = 10, b = 3;
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b); // %% untuk % di printf
    return 0;
}
```

---

### b. Operator Relasi

Digunakan untuk **membandingkan nilai**

| Operator | Contoh   | Hasil                      |
| -------- | -------- | -------------------------- |
| `==`     | `a == b` | true jika sama             |
| `!=`     | `a != b` | true jika tidak sama       |
| `>`      | `a > b`  | true jika lebih besar      |
| `<`      | `a < b`  | true jika lebih kecil      |
| `>=`     | `a >= b` | true jika lebih besar/sama |
| `<=`     | `a <= b` | true jika lebih kecil/sama |

---

### c. Operator Logika

Digunakan untuk **menggabungkan kondisi**

| Operator | Contoh           | Keterangan                      |        |   |        |                       |
| -------- | ---------------- | ------------------------------- | ------ | - | ------ | --------------------- |
| `&&`     | `a > 0 && b > 0` | AND (kedua kondisi harus benar) |        |   |        |                       |
| `        |                  | `                               | `a > 0 |   | b > 0` | OR (salah satu benar) |
| `!`      | `!(a > 0)`       | NOT (negasi)                    |        |   |        |                       |

---

## Struktur Kontrol: `if` / `else`

Digunakan untuk membuat **keputusan** di program.

**Contoh:**

```c
#include <stdio.h>

int main() {
    int umur;
    printf("Masukkan umur Anda: ");
    scanf("%d", &umur);

    if (umur >= 18) {
        printf("Anda sudah dewasa\n");
    } else {
        printf("Anda masih anak-anak\n");
    }
    return 0;
}
```

---

## 3️⃣ `else if` untuk Banyak Kondisi

```c
#include <stdio.h>

int main() {
    int nilai;
    printf("Masukkan nilai Anda: ");
    scanf("%d", &nilai);

    if (nilai >= 90) {
        printf("Nilai: A\n");
    } else if (nilai >= 80) {
        printf("Nilai: B\n");
    } else if (nilai >= 70) {
        printf("Nilai: C\n");
    } else {
        printf("Nilai: D\n");
    }
    return 0;
}
```

---

## 4️⃣ `switch-case` (Alternatif `if-else`)

```c
#include <stdio.h>

int main() {
    int menu;
    printf("Pilih menu (1-3): ");
    scanf("%d", &menu);

    switch(menu) {
        case 1:
            printf("Menu 1 dipilih\n");
            break;
        case 2:
            printf("Menu 2 dipilih\n");
            break;
        case 3:
            printf("Menu 3 dipilih\n");
            break;
        default:
            printf("Menu tidak tersedia\n");
    }
    return 0;
}
```

> `break` penting agar program tidak lanjut ke case berikutnya.

---

## Looping (Perulangan)

### a. `for` Loop

Digunakan jika jumlah iterasi sudah diketahui:

```c
#include <stdio.h>

int main() {
    int i;
    for(i = 1; i <= 5; i++) {
        printf("Perulangan ke-%d\n", i);
    }
    return 0;
}
```

### b. `while` Loop

Digunakan jika jumlah iterasi **tidak diketahui awalnya**:

```c
#include <stdio.h>

int main() {
    int i = 1;
    while(i <= 5) {
        printf("Perulangan ke-%d\n", i);
        i++;
    }
    return 0;
}
```

### c. `do-while` Loop

Loop minimal dijalankan **sekali**, baru cek kondisi:

```c
#include <stdio.h>

int main() {
    int i = 1;
    do {
        printf("Perulangan ke-%d\n", i);
        i++;
    } while(i <= 5);
    return 0;
}
```

---

## Latihan Sederhana

1. Program menentukan **bilangan ganjil/genap**
2. Program menghitung **total nilai** dari input beberapa mata pelajaran
3. Program **menu sederhana**: pilih 1-3, tampilkan pesan sesuai pilihan
