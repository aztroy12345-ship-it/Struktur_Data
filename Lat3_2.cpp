// Lat_3.2.cpp
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    int noUrut;
    string nama;
    int usia;
};

int main() {
    const int N = 5;
    Mahasiswa mhs[N];

    // Input 5 mahasiswa
    for (int i = 0; i < N; ++i) {
        cout << "Masukkan data mahasiswa ke-" << (i+1) << ":\n";
        mhs[i].noUrut = i + 1;
        cout << "Nama: "; cin.ignore(i==0?0:1); getline(cin, mhs[i].nama);
        cout << "Usia: "; cin >> mhs[i].usia;
    }

    // Cetak mahasiswa dengan No urut 2
    cout << "\nDetail mahasiswa dengan No urut 2:\n";
    for (int i = 0; i < N; ++i) {
        if (mhs[i].noUrut == 2) {
            cout << "No urut: " << mhs[i].noUrut << "\n";
            cout << "Nama   : " << mhs[i].nama << "\n";
            cout << "Usia   : " << mhs[i].usia << "\n";
            break;
        }
    }
    return 0;
}

