# Materi 11: Debugging & Error Handling di C

## Apa itu Debugging?

* **Debugging** = proses mencari dan memperbaiki bug (kesalahan) di program.
* Bug bisa berupa:

  * Program **crash** (tiba-tiba berhenti).
  * Program **jalan tapi hasil salah**.
  * Program **jalan terus tanpa berhenti**.

### Analogi:

Bayangkan kamu bikin mesin kopi:

* Kalau mesinnya **meledak** → crash.
* Kalau mesinnya **jalan tapi keluar teh bukan kopi** → logic error.
* Kalau mesinnya **nggak berhenti-berhenti** → infinite loop.

---

## Jenis Error di C

1. **Compile-time error** (saat di-compile)

   * Contoh: typo, lupa titik koma, tipe data salah.
   * Compiler biasanya kasih pesan jelas.
   * Solusi: baca error message.

   ```c
   int main() {
       printf("Hello") // ERROR: lupa titik koma
       return 0;
   }
   ```

2. **Run-time error** (saat program dijalankan)

   * Contoh: bagi 0, akses memori invalid.

   ```c
   int main() {
       int x = 10 / 0; // ERROR: runtime
       return 0;
   }
   ```

3. **Logic error** (hasil salah)

   * Compiler tidak tahu, hanya kita yang bisa deteksi.

   ```c
   int main() {
       int x = 5, y = 10;
       printf("Hasil tambah: %d\n", x - y); // salah logika
       return 0;
   }
   ```

---

## Cara Debugging Sederhana

1. **Gunakan `printf` debugging**

   * Tambahkan `printf` untuk cek nilai variabel.
   * Analogi: seperti menempel catatan kecil untuk cek jalannya proses.

   ```c
   printf("Nilai x: %d\n", x);
   ```

2. **Periksa step-by-step**

   * Jalankan program bagian kecil dulu.
   * Jangan langsung buat kode 300 baris, susah cari error.

3. **Gunakan komentar**

   * Nonaktifkan bagian kode → jalankan sisanya.
   * Cara ini bisa membantu menemukan lokasi error.

---

## Menggunakan Debugger (`gdb`)

Kalau di Mac/Linux, kita bisa pakai **GNU Debugger (gdb)**.

### a. Compile dengan flag debugging

```bash
gcc -g main.c -o program
```

### b. Jalankan dengan gdb

```bash
gdb ./program
```

### c. Perintah penting di gdb

* `run` → jalankan program
* `break 10` → berhenti di baris 10 (breakpoint)
* `next` → eksekusi baris berikutnya
* `print x` → lihat nilai variabel `x`
* `quit` → keluar

### Contoh workflow:

```bash
(gdb) break 12
(gdb) run
(gdb) print x
(gdb) next
```

Analogi: debugger itu seperti **remote control** → bisa pause, step by step, dan lihat isi mesin saat jalan.

---

## Error Handling di C

C tidak punya `try-catch` seperti Java, tapi ada beberapa teknik:

### a. Cek kondisi sebelum operasi

```c
if (y == 0) {
    printf("Error: tidak bisa bagi nol!\n");
} else {
    printf("Hasil: %d\n", x / y);
}
```

### b. Gunakan `errno` untuk fungsi library

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *f = fopen("tidak_ada.txt", "r");
    if (f == NULL) {
        printf("Gagal membuka file: %s\n", strerror(errno));
    }
    return 0;
}
```

### c. Gunakan `assert` untuk validasi

```c
#include <assert.h>

int main() {
    int x = -5;
    assert(x >= 0); // program berhenti kalau kondisi salah
    return 0;
}
```

---

## Tips Debugging untuk Pemula

1. **Baca pesan error dengan teliti** (jangan langsung panik).
2. **Cek baris error + baris sebelumnya** (kadang error muncul karena baris sebelumnya).
3. **Gunakan `printf` debugging** sebelum belajar gdb.
4. **Cek pointer & array** (sering jadi sumber bug di C).
5. **Pisahkan kode jadi modul kecil** → lebih mudah menemukan bug.

---

## Analogi Penutup

* Debugging = **detektif mencari jejak kasus**.
* `printf` = catatan manual.
* `gdb` = CCTV untuk lihat program berjalan.
* `errno` = laporan resmi dari sistem.
* `assert` = alarm otomatis kalau kondisi salah.

---

## Latihan

1. Buat program bagi dua angka → tambahkan error handling kalau pembagi 0.
2. Buat program buka file → tampilkan pesan error kalau file tidak ada.
3. Gunakan `assert` untuk memastikan input angka positif.
