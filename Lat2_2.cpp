#include <iostream>
using namespace std;

int main() {
    int x[15];
    unsigned int alamat_x3 = 0x1000; // &x[3] = 1000H
    int selisih = 9 - 3;
    int ukuran_int = 4;

    unsigned int alamat_x9 = alamat_x3 + (selisih * ukuran_int);

    cout << "Alamat &x[3] = 0x" << hex << alamat_x3 << endl;
    cout << "Ukuran tipe data int = " << dec << ukuran_int << " byte" << endl;
    cout << "Alamat &x[9] = 0x" << hex << alamat_x9 << endl;

    return 0;
}

