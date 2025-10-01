# Materi 8: File Handling di C

## Apa itu File Handling?

* **File handling** = cara program C membaca & menulis data ke file.
* Di C, file diakses dengan **pointer ke file** (`FILE *`).
* Gunakan library standar:

```c
#include <stdio.h>
```

### Analogi:

* File = **lemari arsip**.
* `FILE *` = **kunci lemari**.
* Kita bisa buka lemari (`fopen`), tulis isi (`fprintf`), baca isi (`fscanf`), lalu tutup lemari (`fclose`).

---

## Membuka & Menutup File

Fungsi utama:

```c
FILE *fopen(const char *nama_file, const char *mode);
int fclose(FILE *stream);
```

**Mode yang umum:**

* `"r"` → read (baca)
* `"w"` → write (tulis, hapus isi lama)
* `"a"` → append (tambah di akhir file)
* `"r+"`, `"w+"` → read/write

Contoh:

```c
FILE *file = fopen("data.txt", "w"); // buka untuk tulis
if (file == NULL) {
    printf("Gagal membuka file!\n");
    return 1;
}
fclose(file); // tutup file
```

---

## Menulis ke File

Gunakan `fprintf` (seperti `printf`, tapi output ke file).

```c
#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "w"); // buka untuk tulis
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return 1;
    }

    fprintf(file, "Halo dunia!\n");
    fprintf(file, "Angka: %d\n", 123);

    fclose(file); // tutup file
    printf("Data berhasil ditulis ke file.\n");
    return 0;
}
```

Setelah dijalankan, isi file `data.txt`:

```
Halo dunia!
Angka: 123
```

---

## Membaca dari File

Gunakan `fscanf` atau `fgets`.

### a. Baca teks baris demi baris (`fgets`)

```c
#include <stdio.h>

int main() {
    char buffer[100];
    FILE *file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("File tidak ditemukan!\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer); // tampilkan isi file
    }

    fclose(file);
    return 0;
}
```

### b. Baca data format (`fscanf`)

```c
#include <stdio.h>

int main() {
    int angka;
    FILE *file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("File tidak ditemukan!\n");
        return 1;
    }

    fscanf(file, "Angka: %d", &angka);
    printf("Angka yang dibaca: %d\n", angka);

    fclose(file);
    return 0;
}
```

---

## Append (Menambah Data di Akhir)

```c
#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "a"); // mode append
    if (file == NULL) return 1;

    fprintf(file, "Baris tambahan.\n");
    fclose(file);

    printf("Data ditambahkan ke file.\n");
    return 0;
}
```

---

## Menyimpan Struct ke File

File handling sangat berguna jika dikombinasikan dengan **struct**.

```c
#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int umur;
};

int main() {
    struct Mahasiswa mhs = {"Pandhu", 20};

    FILE *file = fopen("mhs.txt", "w");
    if (file == NULL) return 1;

    fprintf(file, "%s %d\n", mhs.nama, mhs.umur);
    fclose(file);

    printf("Data mahasiswa disimpan ke file.\n");
    return 0;
}
```

Isi file `mhs.txt`:

```
Pandhu 20
```

Kemudian bisa dibaca lagi dengan `fscanf`.

---

## Kesalahan Umum & Tips

1. **Lupa `fclose()`** → file bisa rusak/tidak tersimpan sempurna.
2. **Mode salah**:

   * `"w"` → hati-hati, akan menghapus isi file lama.
   * `"a"` → gunakan untuk menambah data tanpa menghapus.
3. **Selalu cek `NULL`** setelah `fopen`.
4. **Gunakan buffer cukup besar** saat membaca string (`fgets`).

---

## Analoginya

* File = **lemari arsip**.
* `fopen` = ambil kunci lemari.
* `fprintf` = taruh dokumen ke lemari.
* `fscanf`/`fgets` = baca dokumen dari lemari.
* `fclose` = kunci kembali lemarinya.

---

## Latihan untuk Peserta

1. Buat program yang menulis **nama & umur 3 orang** ke file `orang.txt`.
2. Baca file `orang.txt` lalu tampilkan ke layar.
3. Modifikasi program mahasiswa (Materi 7) → simpan array of struct ke file → baca lagi.

