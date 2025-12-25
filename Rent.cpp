#include "Rent.h"

/* ============ INISIALISASI HEAD ============ */

Toko* firstToko = NULL;
Barang* firstBarang = NULL;
Relasi* firstRelasi = NULL;

/* ============== SEARCH ================= */

Toko* cariToko(int idToko) {
    Toko* p = firstToko;
    while (p != NULL) {
        if (p->idToko == idToko)
            return p;
        p = p->next;
    }
    return NULL;
}

Barang* cariBarang(int idBarang) {
    Barang* p = firstBarang;
    while (p != NULL) {
        if (p->idBarang == idBarang)
            return p;
        p = p->next;
    }
    return NULL;
}

/* ============== TAMBAH DATA ================= */

void tambahToko(int idToko, string namaToko) {
    Toko* baru = new Toko{idToko, namaToko, firstToko};
    firstToko = baru;
}

void tambahBarang(int idBarang, string namaBarang) {
    Barang* baru = new Barang{idBarang, namaBarang, firstBarang};
    firstBarang = baru;
}

void tambahRelasi(int idToko, int idBarang) {
    Toko* t = cariToko(idToko);
    Barang* b = cariBarang(idBarang);

    if (t != NULL && b != NULL) {
        Relasi* r = new Relasi{t, b, firstRelasi};
        firstRelasi = r;
        cout << "Relasi berhasil ditambahkan.\n";
    } else {
        cout << "Toko atau Barang tidak ditemukan.\n";
    }
}

/* ============== HAPUS ================= */

void hapusToko(int idToko) {
    Toko *p = firstToko, *prev = NULL;
    while (p != NULL && p->idToko != idToko) {
        prev = p;
        p = p->next;
    }
    if (!p) return;

    if (prev == NULL)
        firstToko = p->next;
    else
        prev->next = p->next;

    Relasi *r = firstRelasi, *pr = NULL;
    while (r != NULL) {
        if (r->toko == p) {
            if (pr == NULL)
                firstRelasi = r->next;
            else
                pr->next = r->next;
            delete r;
            r = (pr == NULL) ? firstRelasi : pr->next;
        } else {
            pr = r;
            r = r->next;
        }
    }
    delete p;
}

void hapusBarang(int idBarang) {
    Barang *p = firstBarang, *prev = NULL;
    while (p != NULL && p->idBarang != idBarang) {
        prev = p;
        p = p->next;
    }
    if (!p) return;

    if (prev == NULL)
        firstBarang = p->next;
    else
        prev->next = p->next;

    Relasi *r = firstRelasi, *pr = NULL;
    while (r != NULL) {
        if (r->barang == p) {
            if (pr == NULL)
                firstRelasi = r->next;
            else
                pr->next = r->next;
            delete r;
            r = (pr == NULL) ? firstRelasi : pr->next;
        } else {
            pr = r;
            r = r->next;
        }
    }
    delete p;
}

/* ============== TAMPIL ================= */

void tampilSemuaToko() {
    for (Toko* t = firstToko; t != NULL; t = t->next) {
        cout << "\nToko: " << t->namaToko << endl;
        for (Relasi* r = firstRelasi; r != NULL; r = r->next)
            if (r->toko == t)
                cout << " - " << r->barang->namaBarang << endl;
    }
}

void tampilBarangDariToko(int idToko) {
    Toko* t = cariToko(idToko);
    if (!t) return;

    cout << "\nBarang di toko " << t->namaToko << ":\n";
    for (Relasi* r = firstRelasi; r != NULL; r = r->next)
        if (r->toko == t)
            cout << "- " << r->barang->namaBarang << endl;
}

void tampilTokoDariBarang(int idBarang) {
    Barang* b = cariBarang(idBarang);
    if (!b) return;

    cout << "\nToko yang menyewakan " << b->namaBarang << ":\n";
    for (Relasi* r = firstRelasi; r != NULL; r = r->next)
        if (r->barang == b)
            cout << "- " << r->toko->namaToko << endl;
}

void tampilTokoTerbanyakTersedikit() {
    Toko *maxT = NULL, *minT = NULL;
    int max = -1, min = 9999;

    for (Toko* t = firstToko; t != NULL; t = t->next) {
        int count = 0;
        for (Relasi* r = firstRelasi; r != NULL; r = r->next)
            if (r->toko == t) count++;

        if (count > max) { max = count; maxT = t; }
        if (count < min) { min = count; minT = t; }
    }

    if (maxT && minT) {
        cout << "\nToko Terlengkap : " << maxT->namaToko << " (" << max << " barang)\n";
        cout << "Toko Tersedikit : " << minT->namaToko << " (" << min << " barang)\n";
    }
}
