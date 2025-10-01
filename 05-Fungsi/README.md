# Materi 5: Fungsi di C

## Apa itu Fungsi?

* Fungsi adalah **blok kode yang bisa dipanggil berkali-kali**.
* Memudahkan program menjadi **lebih rapi dan modular**.
* Fungsi bisa:

  * Menerima input (**parameter**)
  * Mengembalikan output (**return value**)

### Struktur Fungsi

```c
return_type nama_fungsi(parameter_list) {
    // kode yang dijalankan
    return value; // jika return_type bukan void
}
```

---

## Contoh Fungsi Sederhana

### Fungsi tanpa parameter dan tanpa return

```c
#include <stdio.h>

void sapa() {  // void = tidak mengembalikan nilai
    printf("Halo, selamat datang!\n");
}

int main() {
    sapa();  // panggil fungsi
    return 0;
}
```

---

### Fungsi dengan parameter

```c
#include <stdio.h>

void sapa_nama(char nama[]) {
    printf("Halo, %s!\n", nama);
}

int main() {
    sapa_nama("Pandhu");
    sapa_nama("Mira");
    return 0;
}
```

> Parameter = data yang dikirim ke fungsi.

---

### Fungsi dengan return value

```c
#include <stdio.h>

int tambah(int a, int b) {
    return a + b;
}

int main() {
    int hasil = tambah(5, 3);
    printf("Hasil penjumlahan: %d\n", hasil);
    return 0;
}
```

> `return` mengembalikan hasil dari fungsi.

---

## Fungsi dengan beberapa parameter

```c
#include <stdio.h>

float rata_rata(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

int main() {
    float hasil = rata_rata(70, 80, 90);
    printf("Rata-rata: %.2f\n", hasil);
    return 0;
}
```

> Note: gunakan `3.0` agar pembagian menjadi float, bukan integer.

---

## Fungsi Void & Return Bersamaan

* Fungsi **void** → tidak mengembalikan nilai, hanya melakukan aksi.
* Fungsi **non-void** → mengembalikan nilai, bisa dipakai di ekspresi.

---

## Fungsi dengan Array

Fungsi bisa menerima array sebagai parameter:

```c
#include <stdio.h>

int jumlah_array(int arr[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int angka[5] = {1, 2, 3, 4, 5};
    int total = jumlah_array(angka, 5);
    printf("Total angka: %d\n", total);
    return 0;
}
```

---

## Latihan Sederhana

1. Fungsi `kuadrat(int x)` → mengembalikan x²
2. Fungsi `max(int a, int b)` → mengembalikan nilai terbesar
3. Fungsi `tampilkan_nama()` → mencetak nama peserta
4. Fungsi untuk menghitung rata-rata array nilai siswa
