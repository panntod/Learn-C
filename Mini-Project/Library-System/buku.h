#ifndef BUKU_H
#define BUKU_H

struct Buku {
    int id;
    char judul[100];
    char penulis[100];
    int tahun;
};

void tambahBuku();
void tampilkanBuku();
void simpanBukuKeFile();
void bacaBukuDariFile();

#endif
