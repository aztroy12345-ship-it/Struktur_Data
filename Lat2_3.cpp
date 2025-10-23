#include <iostream>
using namespace std;

int main() {
    float x[5][8];
    unsigned int alamat_awal = 0x1000; // &x[0][0] = 1000H
    int baris = 2, kolom = 4, total_kolom = 8;
    int ukuran_float = 4;

    int offset = (baris * total_kolom) + kolom;
    unsigned int alamat_x = alamat_awal + (offset * ukuran_float);

    cout << "Alamat awal &x[0][0] = 0x" << hex << alamat_awal << endl;
    cout << "Offset = " << dec << offset << endl;
    cout << "Ukuran float = " << ukuran_float << " byte" << endl;
    cout << "Alamat &x[2][4] = 0x" << hex << alamat_x << endl;

    return 0;
}

