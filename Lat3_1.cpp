// Lat_3.1.cpp
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    int noUrut;
    string nama;
    int usia;
    float nilai;
};

int main() {
    Mahasiswa m;
    cout << "Input data mahasiswa:\n";
    cout << "No urut: "; cin >> m.noUrut; cin.ignore();
    cout << "Nama: "; getline(cin, m.nama);
    cout << "Usia: "; cin >> m.usia;
    cout << "Nilai: "; cin >> m.nilai;

    cout << "\nData mahasiswa yang disimpan:\n";
    cout << "No urut: " << m.noUrut << "\n";
    cout << "Nama   : " << m.nama << "\n";
    cout << "Usia   : " << m.usia << "\n";
    cout << "Nilai  : " << m.nilai << "\n";

    return 0;
}

