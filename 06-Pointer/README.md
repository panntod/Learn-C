# Materi 6: Pointer & Memory di C

## Apa itu Pointer?

* **Pointer** adalah variabel yang menyimpan **alamat memori** dari variabel lain, bukan nilai langsung.
* Analogi:

  * Bayangkan kamu punya **kotak** bernama `umur` berisi angka `20`.
  * Alamat memori = **alamat rumah kotak itu di memori komputer**.
  * Pointer = **kertas yang berisi alamat rumah kotak itu**, bukan angka `20` langsung.

```c
int umur = 20;     // kotak umur berisi 20
int *ptr = &umur;  // kertas (pointer) menunjuk ke alamat umur
```

* `&` = “ambil alamat memori”
* `*` = “akses nilai di alamat tersebut” (dereference)

---

## Contoh Pointer Sederhana

```c
#include <stdio.h>

int main() {
    int umur = 20;
    int *ptr = &umur;  // pointer menyimpan alamat umur

    printf("Nilai umur: %d\n", umur);       // langsung
    printf("Alamat umur: %p\n", &umur);     // alamat memori
    printf("Nilai lewat pointer: %d\n", *ptr); // dereference pointer
    return 0;
}
```

**Output contoh:**

```
Nilai umur: 20
Alamat umur: 0x7ffee3b2c88c
Nilai lewat pointer: 20
```

> `%p` digunakan untuk menampilkan alamat memori.

---

## 3️⃣ Pointer & Mengubah Nilai Variabel

Pointer bisa digunakan untuk **mengubah nilai variabel dari alamatnya**:

```c
#include <stdio.h>

int main() {
    int angka = 10;
    int *ptr = &angka;

    *ptr = 25;  // ubah nilai variabel lewat pointer

    printf("Nilai angka: %d\n", angka); // 25
    return 0;
}
```

* Analoginya: pointer = kertas alamat kotak → kamu buka kotaknya → ubah isi kotak → nilai asli berubah.

---

## Pointer & Array

* Nama array **adalah alamat pertama** dari array.
* Pointer & array saling terkait.

```c
#include <stdio.h>

int main() {
    int angka[3] = {10, 20, 30};
    int *ptr = angka;  // sama dengan &angka[0]

    printf("Elemen pertama: %d\n", *ptr);        // 10
    printf("Elemen kedua: %d\n", *(ptr + 1));    // 20
    printf("Elemen ketiga: %d\n", *(ptr + 2));   // 30

    return 0;
}
```

> `ptr + 1` → pindah ke alamat memori elemen berikutnya (sesuai tipe data).

---

## Pointer & Fungsi

Pointer bisa digunakan untuk **mengubah nilai variabel di fungsi**, mirip pass-by-reference di Java (pakai objek).

```c
#include <stdio.h>

void ubah(int *x) {
    *x = 100;  // ubah nilai asli lewat pointer
}

int main() {
    int angka = 10;
    printf("Sebelum: %d\n", angka);
    ubah(&angka);  // kirim alamat ke fungsi
    printf("Sesudah: %d\n", angka);
    return 0;
}
```

**Output:**

```
Sebelum: 10
Sesudah: 100
```

* Analogi: fungsi punya kertas alamat → buka kotak asli → ubah isinya → efek langsung ke variabel asli.

---

## Pointer & Dynamic Memory (`malloc` / `free`)

* Di C, kita bisa **meminta memori secara manual**.
* `malloc` = “buat kotak baru di memori”
* `free` = “buang kotak agar memori bebas”

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    ptr = (int *)malloc(sizeof(int));  // buat satu kotak untuk integer

    *ptr = 50;   // isi kotak
    printf("Nilai: %d\n", *ptr);

    free(ptr);   // buang kotak
    return 0;
}
```

> Analogi:
>
> * `malloc` → pergi ke toko memori, ambil kotak kosong
> * `*ptr = 50` → isi kotak
> * `free` → kembalikan kotak ke toko agar bisa dipakai lagi

---

## Pointer ke Pointer

* Pointer bisa menunjuk ke **pointer lain** (alamat dari pointer).

```c
#include <stdio.h>

int main() {
    int angka = 10;
    int *ptr = &angka;
    int **ptr2 = &ptr;

    printf("Nilai angka: %d\n", angka);       // 10
    printf("Nilai lewat ptr: %d\n", *ptr);    // 10
    printf("Nilai lewat ptr2: %d\n", **ptr2); // 10
    return 0;
}
```

* Analogi:

  * Kotak angka → kertas alamat kotak → kertas alamat kertas → dereference dua kali → dapat isi kotak.

---

## Latihan Sederhana

1. Buat pointer untuk **mengubah nilai variabel**.
2. Gunakan pointer untuk **mengakses dan mencetak array**.
3. Buat fungsi swap dengan **pointer** agar nilai dua variabel tertukar.

Contoh swap:

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
```

**Output:**

```
x = 10, y = 5
```

