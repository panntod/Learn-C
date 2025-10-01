#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buku.h"

#define MAX_BUKU 100

struct Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;

void tambahBuku() {
    if (jumlahBuku >= MAX_BUKU) {
        printf("Kapasitas penuh!\n");
        return;
    }

    struct Buku b;
    b.id = jumlahBuku + 1;

    printf("Masukkan judul: ");
    getchar(); // buang newline
    fgets(b.judul, sizeof(b.judul), stdin);
    b.judul[strcspn(b.judul, "\n")] = '\0'; // hapus newline

    printf("Masukkan penulis: ");
    fgets(b.penulis, sizeof(b.penulis), stdin);
    b.penulis[strcspn(b.penulis, "\n")] = '\0';

    printf("Masukkan tahun: ");
    scanf("%d", &b.tahun);

    daftarBuku[jumlahBuku++] = b;
    printf("Buku berhasil ditambahkan!\n");
}

void tampilkanBuku() {
    if (jumlahBuku == 0) {
        printf("Belum ada buku.\n");
        return;
    }

    printf("\n=== Daftar Buku ===\n");
    for (int i = 0; i < jumlahBuku; i++) {
        printf("%d. %s | %s | %d\n", daftarBuku[i].id,
               daftarBuku[i].judul, daftarBuku[i].penulis, daftarBuku[i].tahun);
    }
    printf("===================\n");
}

void simpanBukuKeFile() {
    FILE *f = fopen("buku.txt", "w");
    if (f == NULL) {
        printf("Gagal menyimpan ke file!\n");
        return;
    }

    for (int i = 0; i < jumlahBuku; i++) {
        fprintf(f, "%d;%s;%s;%d\n",
                daftarBuku[i].id,
                daftarBuku[i].judul,
                daftarBuku[i].penulis,
                daftarBuku[i].tahun);
    }

    fclose(f);
    printf("Data buku berhasil disimpan ke file.\n");
}

void bacaBukuDariFile() {
    FILE *f = fopen("buku.txt", "r");
    if (f == NULL) {
        printf("File tidak ditemukan, mulai dari kosong.\n");
        return;
    }

    jumlahBuku = 0;
    while (fscanf(f, "%d;%99[^;];%99[^;];%d\n",
                  &daftarBuku[jumlahBuku].id,
                  daftarBuku[jumlahBuku].judul,
                  daftarBuku[jumlahBuku].penulis,
                  &daftarBuku[jumlahBuku].tahun) == 4) {
        jumlahBuku++;
    }

    fclose(f);
    printf("Data buku berhasil dibaca dari file.\n");
}
