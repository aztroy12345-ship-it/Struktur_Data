#include <iostream>
using namespace std;

int main() {
    int data[10] = {12, 25, 7, 30, 18, 40, 22, 5, 9, 15};
    int cari;
    bool ketemu = false;

    cout << "Masukkan data yang dicari: ";
    cin >> cari;

    for (int i = 0; i < 10; i++) {
        if (data[i] == cari) {
            cout << "Data ditemukan pada indeks ke-" << i << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}

