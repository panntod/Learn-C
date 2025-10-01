# Materi 7: Memory Management di C

## Konsep Memory di C

Program C menggunakan **dua area utama memori**:

| Area      | Fungsi                                                                                                           |
| --------- | ---------------------------------------------------------------------------------------------------------------- |
| **Stack** | Menyimpan variabel lokal, fungsi, parameter. Otomatis dihapus saat fungsi selesai.                               |
| **Heap**  | Menyimpan memori yang dialokasikan secara dinamis (`malloc`, `calloc`). Harus dibebaskan manual dengan `free()`. |

### Analogi:

* Stack = tumpukan kotak sementara → otomatis hilang saat selesai dipakai.
* Heap = gudang penyimpanan → kita yang atur masuk dan keluar barang.

---

## Variabel di Stack

```c
#include <stdio.h>

void contoh() {
    int x = 10; // disimpan di stack
    printf("x = %d\n", x);
}

int main() {
    contoh();
    // x sudah hilang dari stack, tidak bisa diakses di sini
    return 0;
}
```

* Variabel lokal fungsi → otomatis hilang saat fungsi selesai.
* Tidak perlu `free()` untuk stack.

---

## Memori Dinamis (Heap)

* Gunakan heap untuk **data yang ukurannya tidak diketahui saat compile**.
* Fungsi utama: `malloc`, `calloc`, `free`.

### a. `malloc` (memory allocation)

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *) malloc(sizeof(int)); // buat satu integer di heap
    *ptr = 50;  // isi nilai
    printf("Nilai: %d\n", *ptr);

    free(ptr); // harus dibebaskan
    return 0;
}
```

### b. `calloc` (clear allocation)

* Sama seperti `malloc`, tapi otomatis **inisialisasi nol**.

```c
int *arr = (int *) calloc(5, sizeof(int)); // 5 elemen integer, semua 0
```

### c. `free`

* Membebaskan memori heap agar bisa dipakai lagi.
* Analogi: seperti **mengembalikan kotak ke gudang**.

```c
free(arr);
```

---

## Contoh Praktis: Array Dinamis

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Masukkan jumlah angka: ");
    scanf("%d", &n);

    int *angka = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        printf("Masukkan angka ke-%d: ", i+1);
        scanf("%d", &angka[i]);
    }

    printf("Angka yang dimasukkan: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", angka[i]);
    }
    printf("\n");

    free(angka); // jangan lupa dibebaskan
    return 0;
}
```

> Dengan dynamic memory, **program bisa fleksibel menerima jumlah data yang tidak pasti**.

---

## Tips Penting untuk Peserta Awam

1. **Stack** → otomatis, cepat, tapi terbatas.
2. **Heap** → fleksibel, besar, tapi harus dibebaskan manual (`free`).
3. **Pointer** → kunci untuk mengakses memori heap.
4. Jangan lupa: **setiap `malloc/calloc` harus di-`free`** → kalau tidak, terjadi **memory leak**.
5. Gunakan `sizeof()` untuk menghitung ukuran tipe data yang dialokasikan.

---

## Latihan Sederhana

1. Buat **dynamic array** → input n angka → tampilkan → free memori.
2. Buat fungsi `createArray(int n)` yang mengembalikan pointer ke array baru di heap.
3. Eksperimen dengan `malloc` vs `calloc` → lihat perbedaan inisialisasi.