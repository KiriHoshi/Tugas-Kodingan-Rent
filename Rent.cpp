#include "Rent.h"
#include <iostream>
using namespace std;

Toko *firstToko = NULL;
Barang *firstBarang = NULL;
Relasi *firstRelasi = NULL;

Toko *cariToko(int idToko)
{
    Toko *p = firstToko;
    while (p != NULL)
    {
        if (p->idToko == idToko)
            return p;
        p = p->next;
    }
    return NULL;
}

Barang *cariBarang(int idBarang)
{
    Barang *p = firstBarang;
    while (p != NULL)
    {
        if (p->idBarang == idBarang)
            return p;
        p = p->next;
    }
    return NULL;
}

void tambahToko(int idToko, string namaToko)
{
    Toko *baru = new Toko;
    baru->idToko = idToko;
    baru->namaToko = namaToko;
    baru->next = firstToko;
    firstToko = baru;

    cout << "Toko berhasil ditambahkan\n";
}

void tambahBarang(int idBarang, string namaBarang)
{
    Barang *baru = new Barang;
    baru->idBarang = idBarang;
    baru->namaBarang = namaBarang;
    baru->next = firstBarang;
    firstBarang = baru;

    cout << "Barang berhasil ditambahkan\n";
}

void tambahRelasi(int idToko, int idBarang)
{
    Toko *t = cariToko(idToko);
    Barang *b = cariBarang(idBarang);

    if (t == NULL || b == NULL)
    {
        cout << "Toko atau Barang tidak ditemukan\n";
        return;
    }

    Relasi *r = firstRelasi;
    while (r != NULL)
    {
        if (r->toko == t && r->barang == b)
        {
            cout << "Relasi sudah ada\n";
            return;
        }
        r = r->next;
    }

    Relasi *baru = new Relasi;
    baru->toko = t;
    baru->barang = b;
    baru->next = firstRelasi;
    firstRelasi = baru;

    cout << "Relasi berhasil ditambahkan\n";
}

void hapusToko(int idToko)
{
    Toko *p = firstToko, *prev = NULL;

    while (p != NULL && p->idToko != idToko)
    {
        prev = p;
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Toko tidak ditemukan\n";
        return;
    }

    if (prev == NULL)
        firstToko = p->next;
    else
        prev->next = p->next;

    Relasi *r = firstRelasi, *pr = NULL;
    while (r != NULL)
    {
        if (r->toko == p)
        {
            if (pr == NULL)
                firstRelasi = r->next;
            else
                pr->next = r->next;

            Relasi *hapus = r;
            r = r->next;
            delete hapus;
        }
        else
        {
            pr = r;
            r = r->next;
        }
    }

    delete p;
    cout << "Toko dan relasinya berhasil dihapus\n";
}

void hapusBarang(int idBarang)
{
    Barang *p = firstBarang, *prev = NULL;

    while (p != NULL && p->idBarang != idBarang)
    {
        prev = p;
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Barang tidak ditemukan\n";
        return;
    }

    if (prev == NULL)
        firstBarang = p->next;
    else
        prev->next = p->next;

    Relasi *r = firstRelasi, *pr = NULL;
    while (r != NULL)
    {
        if (r->barang == p)
        {
            if (pr == NULL)
                firstRelasi = r->next;
            else
                pr->next = r->next;

            Relasi *hapus = r;
            r = r->next;
            delete hapus;
        }
        else
        {
            pr = r;
            r = r->next;
        }
    }

    delete p;
    cout << "Barang dan relasinya berhasil dihapus\n";
}

void tampilSemuaToko()
{
    if (firstToko == NULL)
    {
        cout << "Data toko kosong\n";
        return;
    }

    for (Toko *t = firstToko; t != NULL; t = t->next)
    {
        cout << "\nID Toko   : " << t->idToko << endl;
        cout << "Nama Toko : " << t->namaToko << endl;
        cout << "Barang disewakan:\n";

        bool ada = false;
        for (Relasi *r = firstRelasi; r != NULL; r = r->next)
        {
            if (r->toko == t)
            {
                cout << " - ID Barang : " << r->barang->idBarang
                     << " | Nama : " << r->barang->namaBarang << endl;
                ada = true;
            }
        }

        if (!ada)
            cout << " (Tidak ada barang)\n";
    }
}

void tampilBarangDariToko(int idToko)
{
    Toko *t = cariToko(idToko);
    if (t == NULL)
    {
        cout << "Toko tidak ditemukan\n";
        return;
    }

    cout << "\nID Toko   : " << t->idToko << endl;
    cout << "Nama Toko : " << t->namaToko << endl;
    cout << "Barang disewakan:\n";

    bool ada = false;
    for (Relasi *r = firstRelasi; r != NULL; r = r->next)
    {
        if (r->toko == t)
        {
            cout << " - ID Barang : " << r->barang->idBarang
                 << " | Nama : " << r->barang->namaBarang << endl;
            ada = true;
        }
    }

    if (!ada)
        cout << " (Tidak ada barang)\n";
}

void tampilTokoDariBarang(int idBarang)
{
    Barang *b = cariBarang(idBarang);
    if (b == NULL)
    {
        cout << "Barang tidak ditemukan\n";
        return;
    }

    cout << "\nID Barang   : " << b->idBarang << endl;
    cout << "Nama Barang : " << b->namaBarang << endl;
    cout << "Disewakan oleh toko:\n";

    bool ada = false;
    for (Relasi *r = firstRelasi; r != NULL; r = r->next)
    {
        if (r->barang == b)
        {
            cout << " - ID Toko : " << r->toko->idToko
                 << " | Nama : " << r->toko->namaToko << endl;
            ada = true;
        }
    }

    if (!ada)
        cout << " (Tidak ada toko)\n";
}

void tampilTokoTerbanyakTersedikit()
{
    if (firstToko == NULL)
    {
        cout << "Data toko kosong\n";
        return;
    }

    Toko *maxT = NULL, *minT = NULL;
    int max = -1, min = 999999;

    for (Toko *t = firstToko; t != NULL; t = t->next)
    {
        int count = 0;
        for (Relasi *r = firstRelasi; r != NULL; r = r->next)
            if (r->toko == t)
                count++;

        if (count > max)
        {
            max = count;
            maxT = t;
        }
        if (count < min)
        {
            min = count;
            minT = t;
        }
    }

    cout << "\nToko Terlengkap : "
         << maxT->namaToko
         << " | ID: " << maxT->idToko
         << " (" << max << " barang)\n";

    cout << "Toko Tersedikit : "
         << minT->namaToko
         << " | ID: " << minT->idToko
         << " (" << min << " barang)\n";
}
