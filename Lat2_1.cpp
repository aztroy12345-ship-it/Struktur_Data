#include <iostream>
using namespace std;

int main() {
    char x[12];
    unsigned int alamat_awal = 0x1000; // &x[0] = 1000H

    cout << "Menampilkan alamat setiap elemen array char x[12]\n";
    for (int i = 0; i < 12; i++) {
        cout << "&x[" << i << "] = 0x" << hex << (alamat_awal + i) << endl;
    }

    cout << "\nAlamat elemen x[8] = 0x" << hex << (alamat_awal + 8) << endl;
    return 0;
}

