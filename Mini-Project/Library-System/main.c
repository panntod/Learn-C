#include <stdio.h>
#include "buku.h"

int main() {
    int pilihan;
    bacaBukuDariFile();

    do {
        printf("\n=== Menu Perpustakaan ===\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Buku\n");
        printf("3. Simpan ke File\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBuku();
                break;
            case 2:
                tampilkanBuku();
                break;
            case 3:
                simpanBukuKeFile();
                break;
            case 0:
                printf("Keluar program...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}
