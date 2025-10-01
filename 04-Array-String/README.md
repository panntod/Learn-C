# Materi 4: Array & String

## Array: Menyimpan Banyak Data

* **Array** adalah kumpulan variabel dengan **tipe sama** yang disimpan secara berurutan di memori.
* Array membantu kita menyimpan data yang banyak tanpa membuat variabel baru satu per satu.

### Deklarasi & Inisialisasi

```c
#include <stdio.h>

int main() {
    int angka[5];           // array integer dengan 5 elemen
    angka[0] = 10;          // assign nilai
    angka[1] = 20;
    angka[2] = 30;
    angka[3] = 40;
    angka[4] = 50;

    printf("Angka pertama: %d\n", angka[0]);
    printf("Angka terakhir: %d\n", angka[4]);
    return 0;
}
```

### Inisialisasi langsung

```c
int angka[5] = {10, 20, 30, 40, 50};
```

> Catatan: Indeks array **dimulai dari 0**. Jadi `angka[0]` adalah elemen pertama.

---

## Looping Array

Sering digunakan `for` loop untuk mengakses semua elemen:

```c
#include <stdio.h>

int main() {
    int angka[5] = {10, 20, 30, 40, 50};
    int i;
    for(i = 0; i < 5; i++) {
        printf("Angka ke-%d: %d\n", i+1, angka[i]);
    }
    return 0;
}
```

---

## Array & Input dari Keyboard

```c
#include <stdio.h>

int main() {
    int nilai[3];
    int i;

    for(i = 0; i < 3; i++) {
        printf("Masukkan nilai ke-%d: ", i+1);
        scanf("%d", &nilai[i]);
    }

    printf("Nilai yang dimasukkan: ");
    for(i = 0; i < 3; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");
    return 0;
}
```

---

## String di C

* String adalah **array karakter** yang diakhiri dengan karakter `'\0'` (null terminator).
* String digunakan untuk teks, berbeda dengan Java yang ada tipe `String` built-in.

### Deklarasi & Inisialisasi

```c
#include <stdio.h>

int main() {
    char nama[20] = "Asfina";
    printf("Nama saya: %s\n", nama);
    return 0;
}
```

> `%s` digunakan di `printf` untuk menampilkan string.

---

### Input String

```c
#include <stdio.h>

int main() {
    char nama[50];
    printf("Masukkan nama Anda: ");
    scanf("%s", nama);  // input sampai spasi pertama
    printf("Halo, %s!\n", nama);
    return 0;
}
```

> Catatan: `scanf("%s", nama)` **hanya membaca satu kata**. Untuk kalimat pakai `fgets`.

```c
#include <stdio.h>

int main() {
    char kalimat[100];
    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin); // input sampai newline
    printf("Anda menulis: %s", kalimat);
    return 0;
}
```

---

## Operasi String

Gunakan library `<string.h>` untuk operasi string:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char a[20] = "Halo";
    char b[20] = "Dunia";

    printf("Panjang string a: %lu\n", strlen(a)); // panjang string
    strcat(a, b);   // gabungkan string a + b
    printf("Hasil gabungan: %s\n", a);

    return 0;
}
```

---

## Latihan Sederhana

1. Buat program input **5 angka**, tampilkan jumlah dan rata-rata.
2. Input **nama peserta**, tampilkan kembali dengan pesan khusus.
3. Gabungkan dua kata menjadi satu string (contoh: nama depan + nama belakang).
