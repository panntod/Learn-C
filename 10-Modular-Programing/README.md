# Materi 10: Modular Programming di C

## Kenapa Perlu Modular Programming?

* Kalau program kecil (misalnya hanya `main.c`), masih gampang dibaca.
* Kalau program besar (ratusan/ribuan baris), **kode berantakan** kalau tidak dipisah.
* Solusinya: **bagi program jadi beberapa file**:

  * **Header file (.h)** → deklarasi fungsi, struct, constant
  * **Source file (.c)** → implementasi fungsi
  * **Main file (.c)** → tempat `main()`

### Analogi:

Bayangkan kamu bikin proyek **rumah**:

* **Header (.h)** = blueprint (gambarnya)
* **Source (.c)** = tukang yang ngerjain sesuai blueprint
* **Main** = mandor yang jalankan proyek

---

## Struktur Project Modular

Contoh struktur sederhana:

```
project/
├── main.c
├── math_utils.c
├── math_utils.h
```

---

## Membuat Header File (`.h`)

Isi deklarasi fungsi/struct/konstanta.

```c
// math_utils.h
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int tambah(int a, int b);
int kurang(int a, int b);

#endif
```

### Catatan:

* `#ifndef ... #define ... #endif` = **header guard** → mencegah duplikasi saat include.

---

## Membuat Source File (`.c`)

Isi implementasi fungsi.

```c
// math_utils.c
#include "math_utils.h"

int tambah(int a, int b) {
    return a + b;
}

int kurang(int a, int b) {
    return a - b;
}
```

---

## Menggunakan di `main.c`

```c
// main.c
#include <stdio.h>
#include "math_utils.h"

int main() {
    int x = 10, y = 5;
    printf("Tambah: %d\n", tambah(x, y));
    printf("Kurang: %d\n", kurang(x, y));
    return 0;
}
```

---

## Compile Program Modular

Kalau satu file:

```bash
gcc main.c -o program
```

Kalau banyak file:

```bash
gcc main.c math_utils.c -o program
```

Jalankan:

```bash
./program
```

**Output:**

```
Tambah: 15
Kurang: 5
```

---

## Makefile (Build Automation)

Kalau file sudah banyak, compile satu-satu capek. Kita bisa pakai **Makefile**.

Contoh `Makefile` sederhana:

```makefile
program: main.o math_utils.o
	gcc main.o math_utils.o -o program

main.o: main.c math_utils.h
	gcc -c main.c

math_utils.o: math_utils.c math_utils.h
	gcc -c math_utils.c

clean:
	rm -f *.o program
```

Cara pakai:

```bash
make        # build program
make clean  # hapus file .o dan executable
```

---

## Modular Programming Lebih Kompleks

Kita bisa buat banyak modul:

```
project/
├── main.c
├── mahasiswa.c
├── mahasiswa.h
├── file_utils.c
├── file_utils.h
├── Makefile
```

* `mahasiswa.c/.h` → struct & fungsi untuk data mahasiswa
* `file_utils.c/.h` → fungsi baca/tulis file
* `main.c` → hanya menjalankan program

Dengan cara ini, kode jadi **mudah dibaca, dipelihara, dan dibagi ke tim**.

---

## Latihan untuk Peserta

1. Buat modul `aritmatika` (header & source) → berisi tambah, kurang, kali, bagi.
2. Buat modul `mahasiswa` (header & source) → struct mahasiswa & fungsi print data.
3. Buat `main.c` yang memanggil keduanya.
4. Buat `Makefile` untuk compile otomatis.

---

## Tips & Analogi

* **Header** = kontrak/blueprint → menjelaskan “fungsi apa yang tersedia”.
* **Source** = implementasi detail.
* **Main** = pengguna yang hanya peduli hasilnya.
* Dengan modular programming, kita bisa **membagi kerja antar anggota tim**.
