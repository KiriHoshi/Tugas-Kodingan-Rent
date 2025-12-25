#ifndef RENT_H
#define RENT_H

#include <iostream>
#include <string>
using namespace std;


struct Toko {
    int idToko;
    string namaToko;
    Toko* next;
};

struct Barang {
    int idBarang;
    string namaBarang;
    Barang* next;
};

struct Relasi {
    Toko* toko;
    Barang* barang;
    Relasi* next;
};


extern Toko* firstToko;
extern Barang* firstBarang;
extern Relasi* firstRelasi;


Toko* cariToko(int idToko);
Barang* cariBarang(int idBarang);

void tambahToko(int idToko, string namaToko);
void tambahBarang(int idBarang, string namaBarang);

void tambahRelasi(int idToko, int idBarang);

void hapusToko(int idToko);
void hapusBarang(int idBarang);

void tampilSemuaToko();
void tampilBarangDariToko(int idToko);
void tampilTokoDariBarang(int idBarang);
void tampilTokoTerbanyakTersedikit();

#endif
