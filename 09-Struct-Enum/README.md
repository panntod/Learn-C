# Materi 7: Struct & Enum

## Apa itu Struct?

* **Struct** (struktur) adalah tipe data **kombinasi beberapa variabel** dengan tipe berbeda.
* Mirip **“class ringan”** di Java tanpa method, hanya **menyimpan data**.
* Digunakan untuk **mengelompokkan data terkait**.

### Analogi:

* Bayangkan membuat **Kartu Identitas (ID Card)**:

  * Nama → string
  * Umur → int
  * Tinggi → float
* Semua info itu **satu kesatuan**, kita bisa simpan di **struct**.

---

## Deklarasi & Inisialisasi Struct

```c
#include <stdio.h>

// definisi struct
struct Mahasiswa {
    char nama[50];
    int umur;
    float tinggi;
};

int main() {
    // membuat variabel struct
    struct Mahasiswa mhs1;

    // mengisi data
    strcpy(mhs1.nama, "Andini");
    mhs1.umur = 20;
    mhs1.tinggi = 1.75;

    // menampilkan data
    printf("Nama: %s\n", mhs1.nama);
    printf("Umur: %d\n", mhs1.umur);
    printf("Tinggi: %.2f\n", mhs1.tinggi);

    return 0;
}
```

> Catatan: gunakan `#include <string.h>` untuk `strcpy`.
> Nama struct biasanya **capitalized** untuk memudahkan pembacaan.

---

## Array of Struct

* Kita bisa membuat **banyak mahasiswa** sekaligus dengan array struct:

```c
#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int umur;
    float tinggi;
};

int main() {
    struct Mahasiswa mhs[2];

    strcpy(mhs[0].nama, "Pin");
    mhs[0].umur = 20;
    mhs[0].tinggi = 1.75;

    strcpy(mhs[1].nama, "Pan");
    mhs[1].umur = 19;
    mhs[1].tinggi = 1.65;

    for(int i = 0; i < 2; i++) {
        printf("Mahasiswa ke-%d: %s, umur %d, tinggi %.2f\n",
               i+1, mhs[i].nama, mhs[i].umur, mhs[i].tinggi);
    }

    return 0;
}
```

* Analogi: seperti **daftar ID Card** → satu array untuk banyak orang.

---

## Pointer & Struct

* Pointer bisa menunjuk ke struct, sama seperti variabel biasa.
* Gunakan `->` untuk mengakses anggota struct lewat pointer.

```c
#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int umur;
};

int main() {
    struct Mahasiswa mhs;
    struct Mahasiswa *ptr = &mhs;

    strcpy(ptr->nama, "Andini");
    ptr->umur = 20;

    printf("Nama: %s\n", ptr->nama);
    printf("Umur: %d\n", ptr->umur);

    return 0;
}
```

> Analogi: pointer = kertas alamat ID Card → buka kotak ID → lihat/ubah info → gunakan `->`.

---

## Enum: Tipe Data Tetap

* **Enum** = tipe data untuk **nilai tetap** yang biasanya diberi nama.
* Berguna untuk membuat **kode lebih mudah dibaca**.

```c
#include <stdio.h>

enum Hari {Senin, Selasa, Rabu, Kamis, Jumat, Sabtu, Minggu};

int main() {
    enum Hari hari_ini;
    hari_ini = Rabu;

    printf("Hari ke-%d\n", hari_ini); // Senin=0, Selasa=1, dst.
    return 0;
}
```

* Analogi: enum = **label tetap** untuk kategori tertentu, misal **hari, bulan, level game**.

### Enum dengan nilai spesifik

```c
enum Level {Mudah = 1, Sedang = 2, Sulit = 3};
```

---

## Latihan Sederhana

1. Buat **struct Mobil**: merk, tahun, harga → isi data 2 mobil → tampilkan.
2. Buat **array struct Mahasiswa** → input nama, umur → tampilkan semua.
3. Buat **enum Status**: `AKTIF`, `LULUS`, `CUTI` → buat program menampilkan status mahasiswa.
