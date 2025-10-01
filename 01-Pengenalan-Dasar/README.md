# Materi 1: Pengenalan Bahasa C & Hello World

## Apa itu Bahasa C?

* Bahasa pemrograman prosedural yang dibuat tahun 1972 oleh **Dennis Ritchie**.
* Digunakan untuk:

  * Sistem operasi (Linux, Unix)
  * Embedded system
  * Program yang butuh performa tinggi
* C adalah **bahasa dasar** untuk banyak bahasa modern (Java, C++, C# terinspirasi dari C).

### Karakteristik C:

* **Prosedural**: tidak ada class/method seperti Java OOP, tapi ada fungsi.
* **Deklaratif & tiped**: setiap variabel harus punya tipe.
* **Manual memory management**: berbeda dengan Java yang ada Garbage Collector.
* **Dekat dengan hardware**: bisa kontrol memori, pointer, dll.

---

## Struktur Dasar Program C

Sebuah program C minimal terlihat seperti ini:

```c
#include <stdio.h>  // Import library standard input-output

int main() {        // Fungsi utama
    printf("Hello, World!\n");  // Mencetak teks ke layar
    return 0;       // Mengembalikan nilai 0 (program selesai sukses)
}
```

### Penjelasan:

| Bagian               | Fungsi                                                                                      |
| -------------------- | ------------------------------------------------------------------------------------------- |
| `#include <stdio.h>` | Memasukkan library standar untuk input & output                                             |
| `int main()`         | Fungsi utama yang akan dijalankan pertama kali, mengembalikan nilai integer (`0` = sukses). |
| `printf()`           | Fungsi untuk menampilkan output ke layar                                                    |
| `return 0;`          | Memberi tahu sistem bahwa program selesai dengan sukses                                     |


---

## Menjalankan Program C di Mac

### Langkah 1: Cek compiler

```bash
clang --version
# OR
gcc --version
```

Jika belum ada, install Xcode Command Line Tools:

```bash
xcode-select --install
```

### Langkah 2: Buat file program

* File: `hello.c`

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

### Langkah 3: Compile & Run

```bash
clang hello.c -o hello   # compile
./hello                  # jalankan program
```

### Penjelasan:

| Bagian       | Fungsi                                                                                     |
| ------------ | ------------------------------------------------------------------------------------------ |
| `Compile`    | Proses mengubah kode sumber C (`.c`) menjadi **executable** (binary yang bisa dijalankan). |
| `clang /gcc` | Compiler yang menerjemahkan kode C ke bahasa mesin.                                        |
| `-o hello`   | Opsi untuk memberi nama output file menjadi `hello`.                                       |
| `./hello`    | Menjalankan file hasil compile.                                                            |

Output:

```
Hello, World!
```

> Tip: Gunakan VS Code untuk menulis kode, terminal bawaan Mac untuk compile/run.

---

## Latihan Sederhana

1. Tampilkan nama peserta:

```c
#include <stdio.h>

int main() {
    printf("Halo, nama saya [Nama Peserta]!\n");
    return 0;
}
```

2. Tampilkan beberapa baris teks:

```c
#include <stdio.h>

int main() {
    printf("Baris pertama\n");
    printf("Baris kedua\n");
    return 0;
}
```

3. Variasi: cetak hasil perhitungan sederhana

```c
#include <stdio.h>

int main() {
    printf("2 + 3 = %d\n", 2 + 3);
    return 0;
}
```
