// Perpustakaan_Menu.cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Buku {
    int nomorAkses;
    string penulis;
    string judul;
    int jumlah;       // jumlah eksemplar tersedia
    bool terbit;      // true = sudah terbit, false = belum terbit
};

// Mencari index buku berdasarkan nomor akses, -1 jika tidak ada
int cariByNomor(const vector<Buku>& db, int nomor) {
    for (size_t i = 0; i < db.size(); ++i)
        if (db[i].nomorAkses == nomor) return (int)i;
    return -1;
}

void tampilkanInfo(const Buku &b) {
    cout << "Nomor Akses: " << b.nomorAkses << "\n";
    cout << "Penulis    : " << b.penulis << "\n";
    cout << "Judul      : " << b.judul << "\n";
    cout << "Jumlah     : " << b.jumlah << "\n";
    cout << "Terbit     : " << (b.terbit ? "Ya" : "Belum") << "\n";
}

int main() {
    vector<Buku> perpustakaan;
    int pilihan;

    do {
        cout << "\n=== MENU PERPUSTAKAAN ===\n";
        cout << "1. Tampilkan informasi buku (by nomor akses)\n";
        cout << "2. Tambah buku baru / tambah stok\n";
        cout << "3. Tampilkan semua buku penulis tertentu\n";
        cout << "4. Hitung jumlah buku dengan judul tertentu\n";
        cout << "5. Tampilkan jumlah total buku di perpustakaan (sum jumlah)\n";
        cout << "6. Terbitkan buku (kurangi 1 dari jumlah sebagai 'terbit')\n";
        cout << "0. Keluar\n";
        cout << "Pilih: "; cin >> pilihan; cin.ignore();

        if (pilihan == 1) {
            int no; cout << "Masukkan nomor akses: "; cin >> no; cin.ignore();
            int idx = cariByNomor(perpustakaan, no);
            if (idx == -1) cout << "Buku tidak ditemukan.\n";
            else tampilkanInfo(perpustakaan[idx]);
        }
        else if (pilihan == 2) {
            Buku b;
            cout << "Masukkan nomor akses: "; cin >> b.nomorAkses; cin.ignore();
            int idx = cariByNomor(perpustakaan, b.nomorAkses);
            if (idx != -1) {
                int tambah; cout << "Buku sudah ada. Tambah jumlah: "; cin >> tambah; cin.ignore();
                perpustakaan[idx].jumlah += tambah;
                cout << "Stok diperbarui.\n";
            } else {
                cout << "Penulis: "; getline(cin, b.penulis);
                cout << "Judul  : "; getline(cin, b.judul);
                cout << "Jumlah : "; cin >> b.jumlah; cin.ignore();
                cout << "Sudah terbit? (1=Ya,0=Belum): "; int t; cin >> t; cin.ignore();
                b.terbit = (t == 1);
                perpustakaan.push_back(b);
                cout << "Buku ditambahkan.\n";
            }
        }
        else if (pilihan == 3) {
            string nama; cout << "Masukkan nama penulis: "; getline(cin, nama);
            bool found = false;
            for (const auto &b : perpustakaan) {
                if (b.penulis == nama) {
                    tampilkanInfo(b);
                    cout << "-----------------\n";
                    found = true;
                }
            }
            if (!found) cout << "Tidak ada buku dari penulis tersebut.\n";
        }
        else if (pilihan == 4) {
            string jud; cout << "Masukkan judul: "; getline(cin, jud);
            int count = 0;
            for (const auto &b : perpustakaan) if (b.judul == jud) count += b.jumlah;
            cout << "Jumlah total eksemplar dengan judul \"" << jud << "\": " << count << "\n";
        }
        else if (pilihan == 5) {
            int total = 0;
            for (const auto &b : perpustakaan) total += b.jumlah;
            cout << "Jumlah total buku (semua judul): " << total << "\n";
        }
        else if (pilihan == 6) {
            int no; cout << "Masukkan nomor akses buku untuk diterbitkan: "; cin >> no; cin.ignore();
            int idx = cariByNomor(perpustakaan, no);
            if (idx == -1) cout << "Buku tidak ditemukan.\n";
            else {
                if (perpustakaan[idx].jumlah > 0) {
                    perpustakaan[idx].jumlah -= 1;
                    perpustakaan[idx].terbit = true;
                    cout << "Buku dengan nomor " << no << " telah 'terbit' (stok -1).\n";
                } else {
                    cout << "Stok kosong, tidak bisa menerbitkan.\n";
                }
            }
        }
        else if (pilihan == 0) {
            cout << "Keluar menu.\n";
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}

