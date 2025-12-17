#include <iostream>
using namespace std;

int main() {
    int data[15] = {2,5,8,12,16,23,38,45,56,72,91,100,123,150,200};
    int cari, kiri = 0, kanan = 14, tengah, langkah = 0;
    bool ketemu = false;

    cout << "Cari angka: ";
    cin >> cari;

    while (kiri <= kanan) {
        langkah++;
        tengah = (kiri + kanan) / 2;
        if (data[tengah] == cari) {
            ketemu = true;
            break;
        } else if (data[tengah] < cari)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    if (ketemu)
        cout << "Data ditemukan. Langkah: " << langkah << endl;
    else
        cout << "Data tidak ditemukan. Langkah: " << langkah << endl;

    return 0;
}

