# Materi 2: Variabel, Tipe Data, dan Input

## Variabel: Apa itu dan untuk apa?

* **Variabel** adalah tempat untuk menyimpan data sementara di memori.
* Setiap variabel punya **nama** dan **tipe data**.
* Mirip seperti **variabel di Java**, tapi di C kita harus **mendeklarasikan tipe datanya**.

### Contoh:

```c
#include <stdio.h>

int main() {
    int umur = 20;           // integer
    float tinggi = 1.75;     // desimal
    char inisial = 'A';      // karakter
    printf("Umur: %d\n", umur);
    printf("Tinggi: %.2f\n", tinggi);
    printf("Inisial: %c\n", inisial);
    return 0;
}
```

**Penjelasan tipe data:**

| Tipe Data       | Contoh               | Deskripsi                                           |
| --------------- | -------------------- | --------------------------------------------------- |
| `int`           | 10                   | Bilangan bulat                                      |
| `short int`     | 32000                | Bilangan bulat pendek                               |
| `long int`      | 1000000              | Bilangan bulat panjang                              |
| `long long int` | 1000000000000        | Bilangan bulat sangat panjang                       |
| `unsigned int`  | 20                   | Bilangan bulat positif (tanpa tanda)                |
| `float`         | 1.75                 | Bilangan desimal (presisi tunggal)                  |
| `double`        | 3.1415               | Bilangan desimal presisi ganda                      |
| `long double`   | 3.141592653589793238 | Bilangan desimal presisi sangat tinggi              |
| `char`          | 'A'                  | Karakter tunggal                                    |
| `unsigned char` | 255                  | Karakter/byte positif                               |
| `const`         | `const int x = 5;`   | Nilai tetap, tidak bisa diubah                      |
| `_Bool`         | 1                    | Nilai boolean (`0` = false, `1` = true)             |
| `void`          | `void func()`        | Tidak mengembalikan nilai (fungsi) atau tipe kosong |


> Tip: Di printf, `%d` untuk integer, `%f` untuk float, `%c` untuk char.

---

## Input dari Keyboard

Di C, untuk membaca input kita pakai **`scanf`**.

### Contoh membaca integer

```c
#include <stdio.h>

int main() {
    int umur;
    printf("Masukkan umur Anda: ");
    scanf("%d", &umur);   // &umur → alamat memori variabel
    printf("Umur Anda adalah: %d\n", umur);
    return 0;
}
```

### Contoh membaca float

```c
#include <stdio.h>

int main() {
    float tinggi;
    printf("Masukkan tinggi badan Anda (meter): ");
    scanf("%f", &tinggi);
    printf("Tinggi Anda: %.2f meter\n", tinggi);
    return 0;
}
```

### Contoh membaca char

```c
#include <stdio.h>

int main() {
    char inisial;
    printf("Masukkan inisial nama Anda: ");
    scanf(" %c", &inisial);  // spasi sebelum %c untuk menangkap newline
    printf("Inisial Anda: %c\n", inisial);
    return 0;
}
```

> Note: `&` sebelum nama variabel itu penting karena scanf butuh **alamat memori**.

---

## Operator Sederhana

Kita bisa langsung menggabungkan input dan operasi:

```c
#include <stdio.h>

int main() {
    int a, b;
    printf("Masukkan angka pertama: ");
    scanf("%d", &a);
    printf("Masukkan angka kedua: ");
    scanf("%d", &b);
    printf("Hasil penjumlahan: %d\n", a + b);
    return 0;
}
```

---

## Latihan Sederhana

1. Program untuk menampilkan **nama dan umur** peserta.
2. Program menghitung **luas persegi panjang** (input panjang & lebar).
3. Program sederhana **kalkulator penjumlahan** dua angka dari input.
