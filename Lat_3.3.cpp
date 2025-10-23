// Lat_3.3.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Mahasiswa {
    int noUrut;
    string nama;
    int umur;
    string alamat;
    float nilai;
};

int main() {
    const int N = 15;
    vector<Mahasiswa> mhs(N);

    for (int i = 0; i < N; ++i) {
        cout << "Masukkan data mahasiswa ke-" << (i+1) << ":\n";
        mhs[i].noUrut = i + 1;
        cout << "Nama   : "; cin.ignore(i==0?0:1); getline(cin, mhs[i].nama);
        cout << "Umur   : "; cin >> mhs[i].umur; cin.ignore();
        cout << "Alamat : "; getline(cin, mhs[i].alamat);
        cout << "Nilai  : "; cin >> mhs[i].nilai;
    }

    cout << "\n=== Daftar 15 Mahasiswa ===\n";
    for (const auto &m : mhs) {
        cout << "No: " << m.noUrut
             << " | Nama: " << m.nama
             << " | Umur: " << m.umur
             << " | Alamat: " << m.alamat
             << " | Nilai: " << m.nilai << "\n";
    }
    return 0;
}

