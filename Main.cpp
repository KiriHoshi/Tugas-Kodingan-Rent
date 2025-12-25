#include "Rent.h"
#include <limits>

int main() {
    int pilih;

    do {
        cout << "\n===== MENU RENTAL BARANG =====\n";
        cout << "1. Tambah Toko\n";
        cout << "2. Tambah Barang\n";
        cout << "3. Tambah Relasi Toko-Barang\n";
        cout << "4. Hapus Toko\n";
        cout << "5. Hapus Barang\n";
        cout << "6. Tampilkan Semua Toko\n";
        cout << "7. Tampilkan Barang dari Toko\n";
        cout << "8. Tampilkan Toko dari Barang\n";
        cout << "9. Toko Terbanyak & Tersedikit\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            int id;
            string nama;
            cout << "ID Toko: ";
            cin >> id;

            if (cariToko(id) != NULL) {
                cout << "ID Toko sudah terdaftar\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nama Toko: ";
            getline(cin, nama);
            tambahToko(id, nama);
        }
        else if (pilih == 2) {
            int id;
            string nama;
            cout << "ID Barang: ";
            cin >> id;

            if (cariBarang(id) != NULL) {
                cout << "ID Barang sudah terdaftar\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nama Barang: ";
            getline(cin, nama);
            tambahBarang(id, nama);
        }
        else if (pilih == 3) {
            int idT, idB;
            cout << "ID Toko: ";
            cin >> idT;
            cout << "ID Barang: ";
            cin >> idB;
            tambahRelasi(idT, idB);
        }
        else if (pilih == 4) {
            int id;
            cout << "ID Toko: ";
            cin >> id;
            hapusToko(id);
        }
        else if (pilih == 5) {
            int id;
            cout << "ID Barang: ";
            cin >> id;
            hapusBarang(id);
        }
        else if (pilih == 6) {
            tampilSemuaToko();
        }
        else if (pilih == 7) {
            int id;
            cout << "ID Toko: ";
            cin >> id;
            tampilBarangDariToko(id);
        }
        else if (pilih == 8) {
            int id;
            cout << "ID Barang: ";
            cin >> id;
            tampilTokoDariBarang(id);
        }
        else if (pilih == 9) {
            tampilTokoTerbanyakTersedikit();
        }

    } while (pilih != 0);

    return 0;
}
