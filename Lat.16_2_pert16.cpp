#include <iostream>
using namespace std;

int main() {
    int data[10] = {5, 7, 9, 12, 15, 18, 22, 25, 30, 40};
    int kiri = 0, kanan = 9, tengah;
    int cari;
    bool ketemu = false;

    cout << "Masukkan data yang dicari: ";
    cin >> cari;

    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;

        if (data[tengah] == cari) {
            cout << "Data ditemukan pada indeks ke-" << tengah << endl;
            ketemu = true;
            break;
        } else if (data[tengah] < cari) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}

